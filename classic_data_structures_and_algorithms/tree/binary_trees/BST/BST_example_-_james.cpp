#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <queue>

struct btNode
{
   int data_field;
   btNode* left;
   btNode* right;
};

void tree_clear(btNode*&);
void tree_copy(btNode*&, btNode*);
btNode* tree_copy(btNode*);
int size(btNode*);
int rank(btNode*, int);
int tree_depth(btNode*);
int node_depth(btNode*, int);
int node_depth_util(btNode*, int, int);
bool balanced(btNode*);
bool full(btNode*);
void find(int, const btNode*, btNode**, btNode**);    
void insert(btNode*&, btNode*);
void del(btNode*&, int);
void case_a(btNode*&, btNode*, btNode*);
void case_b(btNode*&, btNode*, btNode*);
void case_c(btNode*&, btNode*, btNode*);
void preorder(btNode*, std::ostream&);
void inorder(btNode*, std::ostream&);
void postorder(btNode*, std::ostream&);
void backward_inorder(btNode*, std::ostream&, int);
void breadth_first(btNode*, std::ostream&);
void display(btNode*, int);
void displayMenu();

int main()
{
   btNode* root = 0, * temp = 0;
   int choice, num;
   
   while (1)
   {
      displayMenu();
      std::cin >> choice;
      switch(choice)
      {
         case 1:
            temp = new btNode;
            std::cout << std::endl << "Enter the number to be inserted: ";
            std::cin >> temp->data_field;
            std::cout << std::endl;
            insert(root, temp);
            break;
         case 2:
            if (!root)
            {
               std::cout << std::endl << "Tree is empty, nothing to delete" << std::endl;
               continue;
            }
            std::cout << std::endl << "Enter the number to be deleted: ";
            std::cin >> num;
            del(root, num);
            break;
         case 3:
            std::cout << std::endl << "Preorder traversal of BST rooted at " << root << ": " << std::endl;
            preorder(root, std::cout);
            std::cout << std::endl;
            break;
         case 4:
            std::cout << std::endl << "Inorder traversal of BST rooted at " << root << ": " << std::endl;
            inorder(root, std::cout);
            std::cout << std::endl;
            break;
         case 5:
            std::cout << std::endl << "Postorder traversal of BST rooted at " << root << ": " << std::endl;
            postorder(root, std::cout);
            std::cout << std::endl;
            break;
         case 6:
            std::cout << std::endl << "Backward inorder traversal of BST rooted at " << root << ": " << std::endl;
            backward_inorder(root, std::cout, tree_depth(root));
            std::cout << std::endl;
            break;
         case 7:
            std::cout << std::endl << "Breadth-first traversal of BST rooted at " << root << ": " << std::endl;
            breadth_first(root, std::cout);
            break;
         //case 8:
         //   std::cout << std::endl << "Display of BST rooted at " << root << ": " << std::endl;
         //   display(root);
         //   std::cout << std::endl;
         //   break;
         case 9:
            std::cout << std::endl << "Number of nodes in BST rooted at " << root << ": " << size(root) << std::endl;
            break;
         case 10:
            std::cout << std::endl << "Depth of BST rooted at " << root << ": " << tree_depth(root) << std::endl;
            break;
         case 11:
            std::cout << std::endl << "Tree rooted at " << root << " is ";
            if (balanced(root)) { std::cout << "balanced"; } else { std::cout << "not balanced"; }
            std::cout << std::endl;
            break;
         case 12:
            std::cout << std::endl << "Tree rooted at " << root << " is ";
            if (full(root)) { std::cout << "full"; } else { std::cout << "not full"; }
            std::cout << std::endl;
            break;
         case 0:
            return EXIT_SUCCESS;
         default:
            std::cout << std::endl << "Wrong choice" << std::endl;
        }
    }
}

// CLEARING A TREE
void tree_clear(btNode*& root)
// pre: (none)
// post: dynamic memory of all the tree's nodes has been freed up (returned back to the heap/freestore)
//          and the tree is now empty (root pointer contains the null address).     
{
	if (root)
	{
		tree_clear(root->left);
		tree_clear(root->right);
		delete root;
		root = 0;
	}
}

// COPYING A TREE (1)
void tree_copy(btNode*& dst_root, btNode* src_root)
// pre: destination root pointer (destination root) does not point to anything relevant
// post: dst_root has been made the root to a new tree that is identical (with regard to structure and values)
//       to the tree rooted at src_root
{
   if (!src_root) dst_root = 0;  // base case
   else
   {
   	dst_root = new btNode;
   	dst_root->data_field = src_root->data_field;
   	tree_copy(dst_root->left, src_root->left);
   	tree_copy(dst_root->right, src_root->right);
   }
}

// COPYING A TREE (2)
btNode* tree_copy(btNode* src_root)
// pre: (none)
// post: a root pointer to a new tree that is identical (with regard to structure and values) to the tree
//          rooted at src_root is returned
{
   if (!src_root) return 0;   // base case
   else
   {
   	btNode* ret_root = new btNode;
   	ret_root->data_field = src_root->data_field;
   	ret_root->left = tree_copy(src_root->left);
   	ret_root->right = tree_copy(src_root->right);
   	return ret_root;
   }
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////// TREE INSPECTION ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int size(btNode* root)
// pre: (none)
// post: Number of nodes contained in tree rooted at root is returned
{
   if (!root) return 0;
   return 1 + size(root->left) + size(root->right);
}

int rank(btNode* root, int value)
{
   int rank = 0;
   while (root)
   {
      if (value < root->data_field) root = root->left;
      else if (value > root->data_field)
      {
         rank += 1 + size(root->left);
         root = root->right;
      }
      else return rank + size(root->left);
   }
   return -1;
}

// By the definition used here, depth of an empty tree is 0
int tree_depth(btNode* root)
// pre: (none)
// post: Depth of tree rooted at root is returned
{
   if (!root) { return 0; }
   int depthLST = tree_depth(root->left),
       depthRST = tree_depth(root->right);
   return (depthLST > depthRST) ? 1 + depthLST : 1 + depthRST;
}

/*
// By the definition used here, depth of an empty tree is -1
int tree_depth(btNode* root)
// pre: (none)
// post: Depth of tree rooted at root is returned
{
   if (!root) { return -1; }
   int depthLST = depth(root->left),
       depthRST = depth(root->right);
   return (depthLST > depthRST) ? 1 + depthLST : 1 + depthRST;
}
*/

int node_depth(btNode *node, int data_field)
{
    return node_depth_util(node, data_field, 1);
}

int node_depth_util(btNode *node, int data_field, int depth)
{
    if (!node) return 0;
    if (node->data_field == data_field) return depth;
    int down_depth = node_depth_util(node->left, data_field, depth + 1);
    if (down_depth) return down_depth;
    down_depth = node_depth_util(node->right, data_field, depth + 1);
    return down_depth;
}

bool balanced(btNode* root)
// pre: (none)
// post: True is returned if tree rooted at root is balanced, otherwise false is returned
{
   if (!root) { return true; }
   int size_diff = size(root->left) - size(root->right);
   if (size_diff < -1 || size_diff > 1) { return false; }
   return balanced(root->left) && balanced(root->right);
}

bool full(btNode* root)
// pre: (none)
// post: True is returned if tree rooted at root is a full tree, otherwise false is returned
{
   if (!root) { return true; }
   if ( (root->left && !root->right) || (root->right && !root->left) ) { return false; }
   return full(root->left) && full(root->right);
}

bool is_complete_BT(btNode* root)
{
   if (!root) return true;
   std::queue<btNode*> q;
   bool flag = false;
   q.push(root);
   while(!q.empty())
   {
      btNode* temp_node = q.front();
      if (temp_node->left)
      {
         if (flag) return false;
         else q.push(temp_node->left);
      }
      else flag = true;
      if (temp_node->right)
      {
         if (flag) return false;
         q.push(temp_node->right);
      }
      else flag = true;
   }
   return true;
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// TREE TRAVERSAL ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void find(int value, btNode* root, btNode** parent, btNode** location)
{
   btNode *ptr, *ptrsave;
   if (!root)
   {
      *location = 0;
      *parent = 0;
      return;
   }
   if (value == root->data_field)
   {
      *location = root;
      *parent = 0;
      return;
   }
   if (value < root->data_field) { ptr = root->left; }
   else { ptr = root->right; }
   ptrsave = root;
   while (ptr)
   {
      if (value == ptr->data_field)
      {
         *location = ptr;
         *parent = ptrsave;
         return;
      }
      ptrsave = ptr;
      if (value < ptr->data_field) { ptr = ptr->left; }
      else { ptr = ptr->right; }
   }
   *location = 0;
   *parent = ptrsave;
}

void preorder(btNode* root, std::ostream& out) 
// pre:  (none) 
// post: values (if any) stored on tree rooted at 
//       root have been inserted (each followed by 
//       a space character) in preorder fashion 
//       into out 
{ 
   if (root) // if empty tree, simply return  
   { 
      out << root->data_field << ' '; 
      preorder(root->left, out); 
      preorder(root->right, out); 
   } 
}

void inorder(btNode* root, std::ostream& out) 
// pre:  (none) 
// post: values (if any) stored on tree rooted at 
//       root have been inserted (each followed by 
//       a space character) in inorder fashion 
//       into out 
{ 
   if (root) // if empty tree, simply return  
   { 
      inorder(root->left, out); 
      out << root->data_field << ' '; 
      inorder(root->right, out); 
   } 
}

void postorder(btNode* root, std::ostream& out) 
// pre:  (none) 
// post: values (if any) stored on tree rooted at 
//       root have been inserted (each followed by 
//       a space character) in postorder fashion 
//       into out 
{ 
   if (root) // if empty tree, simply return  
   { 
      postorder(root->left, out); 
      postorder(root->right, out); 
      out << root->data_field << ' '; 
   } 
}

void backward_inorder(btNode* root, std::ostream& out, int depth) 
// pre:  (none) 
// post: values (if any) stored on tree rooted at 
//       root have been inserted into out to produce an output 
//       illustrated below: 
//       tree:     3         output:     5 
//                / \                3 
//               2   5                       4 
//              / \                      2 
//             1   4                             0 
//              \                            1 
//               0 
{ 
   if (root) // if empty tree, simply return  
   { 
      backward_inorder(root->right, out, depth + 1); 
      out << std::setw(4 * depth) << ""; 
      out << root->data_field << std::endl; 
      backward_inorder(root->left, out, depth + 1); 
   } 
}

void breadth_first(btNode* root, std::ostream& out)
// pre: (none)
// post: values (if any) stored on tree rooted at root have been inserted (each 
//          followed by a space character) in breadth-first fashion into out
{
   std::queue<btNode*> q;
   btNode* traverse;
   if (!root) return;
   q.push(root);
   std::cout << std::endl;
   while(!q.empty())
   {
   	traverse = q.front();
   	std::cout << traverse->data_field << " ";
   	q.pop();
   	if (traverse->left) q.push(traverse->left);
   	if (traverse->right) q.push(traverse->right);
   }
   std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// ADDITIVE AND SUBTRACTIVE PROCEDURES ///////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

void insert(btNode*& root, btNode* newNodePtr)
{
   if (!root)
   {
      root = new btNode;
      root->data_field = newNodePtr->data_field;
      root->left = 0, root->right = 0;
      std::cout << "Root node is added" << std::endl;
      return;
   }
   if (root->data_field == newNodePtr->data_field)
   {
      std::cout << "Element already in the tree" << std::endl;
      return;
   }
   if (root->data_field > newNodePtr->data_field)
   {
      if (root->left)
         insert(root->left, newNodePtr);
      else
      {
         root->left = newNodePtr;
         (root->left)->left = 0, (root->left)->right = 0;
         std::cout << "Node added to left" << std::endl;
         return;
      }
   }
   else
   {
      if (root->right)
         insert(root->right, newNodePtr);
      else
      {
         root->right = newNodePtr;
         (root->right)->left = 0;
         (root->right)->right = 0;
         std::cout << "Node added to right" << std::endl;
         return;
      }   
   }
}

void del(btNode*& root, int value)
{
   btNode* parent, * location;
   if (!root)
   {
      std::cout << std::endl << "Tree empty" << std::endl;
      return;
   }
   find(value, root, &parent, &location);
   if (!location)
   {
      std::cout << std::endl << "Item not present in tree" << std::endl;
      return;
   }
   if (!location->left && !location->right) { case_a(root, parent, location); }
   if (location->left && !location->right) { case_b(root, parent, location); }
   if (!location->left && location->right) { case_b(root, parent, location); }
   if (location->left && location->right) { case_c(root, parent, location); }
   delete location;
}

void case_a(btNode*& root, btNode *parent, btNode *location)
{
   if (!parent) { root = 0; }
   else
   {
      if (location == parent->left) { parent->left = 0; }
      else { parent->right = 0; }
   }
}

void case_b(btNode*& root, btNode* parent, btNode* location)
{
   btNode* child;
   if (location->left) { child = location->left; }
   else { child = location->right; }
   if (!parent) { root = child; }
   else
   {
      if (location == parent->left) { parent->left = child; }
      else { parent->right = child; }
   }
}

void case_c(btNode*& root, btNode* parent, btNode* location)
{
   btNode* ptr, * ptrsave, * suc, * parsuc;
   ptrsave = location;
   ptr = location->right;
   while (ptr->left)
   {
      ptrsave = ptr;
      ptr = ptr->left;
   }
   suc = ptr;
   parsuc = ptrsave;
   if (!suc->left && !suc->right) { case_a(root, parsuc, suc); }
   else { case_b(root, parsuc, suc); }
   if (!parent) { root = suc; }
   else
   {
      if (location == parent->left) { parent->left = suc; }
      else { parent->right = suc; }
   }
   suc->left = location->left;
   suc->right = location->right;
}

/*

NEED FIX

void display(btNode* root)
{
   if (root)
   {
      display(root->right, level + 1);
      std::cout << std::endl;
      if (node_depth(root, level) == 1) { std::cout << "Root->:  "; }
      else
      {
         for (unsigned int i = 0; i < level; ++i)
         std::cout << "       ";
      }
      std::cout << root->data_field;
      display(root->left, level + 1);
   }
}
*/

void displayMenu()
{
   std::cout << "---------------------------------" << std::endl;
   std::cout << "Operations on BST" << std::endl;
   std::cout << "---------------------------------" << std::endl;
   std::cout << "1.Insert element " << std::endl;
   std::cout << "2.Delete element " << std::endl;
   std::cout << "3.Preorder traversal" << std::endl;
   std::cout << "4.Inorder traversal" << std::endl;
   std::cout << "5.Postorder traversal" << std::endl;
   std::cout << "6.Backward inorder traversal" << std::endl;
   std::cout << "7.Breadth-first traversal" << std::endl;
   std::cout << "8.Display" << std::endl;
   std::cout << "9.Inspect number of nodes in tree" << std::endl;
   std::cout << "10.Inspect depth of tree" << std::endl;
   std::cout << "11.Check if tree is balanced" << std::endl;
   std::cout << "12.Check if tree is full" << std::endl;
   std::cout << "---------------------------------" << std::endl;
   std::cout << "0.Quit" << std::endl;
   std::cout << "---------------------------------" << std::endl;
   std::cout << "Enter your choice : ";
}
