#include "btNode.h"
#include <iostream>

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

// write definition for bst_insert here
void bst_insert(btNode*& bst_root, const int insInt)
{
   btNode* root_ptr = 0, * parent_ptr = 0;
   if (!bst_root) 
   {
      btNode* new_node = new btNode;
      new_node->data = insInt;
      new_node->left = 0, new_node->right = 0;
      bst_root = new_node;
      root_ptr = bst_root;
      return;
   }
   
   root_ptr = bst_root;
   bool done = false;
   while (!done)
   {
      if (root_ptr->data == insInt)
      {
         done = true;
         return;
      }
      else if (insInt < root_ptr->data)
      {
         parent_ptr = root_ptr;
         root_ptr = root_ptr->left;
         if (root_ptr == 0) { done = true; }
      }
      else
      {
         parent_ptr = root_ptr;
         root_ptr = root_ptr->right;
         if (root_ptr == 0) { done = true; }
      }
   }

   btNode* new_node = new btNode;
   new_node->data = insInt;
   new_node->left = 0;
   new_node->right = 0;
   if (insInt < parent_ptr->data)
      parent_ptr->left = new_node;
   else
      parent_ptr->right = new_node;
}

// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int remInt)
{
   if (!bst_root) { return false; }
   btNode* root_ptr = bst_root;
   if (remInt == root_ptr->data)
   {
      if (!root_ptr->left)
      {
         btNode* oldroot_ptr = root_ptr;
         root_ptr = root_ptr->right;
         delete oldroot_ptr;
         bst_root = root_ptr;
      }
      else
         bst_remove_max(root_ptr->left, root_ptr->data);
      return true;
   }
   else if (remInt < root_ptr->data)
      return bst_remove(root_ptr->left, remInt);
   else if (remInt > root_ptr->data)
      return bst_remove(root_ptr->right, remInt);
}

// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root, int &removed)
{
   removed = bst_root->data;
   btNode* temp = bst_root;
   if (bst_root->right)
      bst_remove_max(bst_root->right, removed);
   else if (bst_root->left)
      bst_remove_max(bst_root->left, bst_root->data);
   else
   {
      bst_root = 0;
      delete temp;
   }
}
