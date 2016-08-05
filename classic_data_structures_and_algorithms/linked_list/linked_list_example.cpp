#include <iostream>

struct node {
   int data;
   node* link;
};

void InsertAsHead(node*&, int);
void InsertAsTail(node*&, int);
void InsertSortedUp(node*&, int);
bool IsSortedUp(node*);
bool DelFirstTargetNode(node*&, int);
bool DelNodeBefore1stMatch(node*&, int);
bool DelNodeAfter1stMatch(node*&, int);
int FindListLength(node*);
void FindMinMax(node*, int&, int&);
double FindAverage(node*);
bool HasDup(node*);
bool Swap1stTargetNodeWithNodeB4(node*&, int);
bool LL1IsContainedInLL2(node*, node*);
void ShowAll(std::ostream& outs, node*);
void ListClear(node*&);

int main()
{
   node* headPtr = 0;
   InsertAsHead(headPtr, 1);
   ShowAll(std::cout, headPtr);
   return 0;
}

void InsertAsHead(node*& headPtr, int value)
{
   node* newNodePtr = new node;
   newNodePtr->data = value;
   newNodePtr->link = headPtr;
   headPtr = newNodePtr;
}

void InsertAsTail(node*& headPtr, int value)
{
   node* newNodePtr = new node;
   newNodePtr->data = value;
   newNodePtr->link = 0;
   if (!headPtr)
   {
      headPtr = newNodePtr;
      return;
   }
   node* cursor = headPtr;
   while (cursor->link) { cursor = cursor->link; }
   cursor->link = newNodePtr;
}

void InsertSortedUp(node*& headPtr, int value)
{
   node *precursor = 0, * cursor = headPtr; 
   while (cursor && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   } 
   node *newNodePtr = new node;
   newNodePtr->data = value;
   newNodePtr->link = cursor;   // because cursor->data >= value
   if (cursor == headPtr) { headPtr = newNodePtr; }
   else { precursor->link = newNodePtr; }
   
   // Using-only-cursor (no precursor) version:
   /* 
   node *newNodePtr = new node;
   newNodePtr->data = value;
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      //if (cursor->link != 0)
      //   newNodePtr->link = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }
   */
   
   /*
   node *newNodePtr = new node;
   newNodePtr->data = value;
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   else
   {
      node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }
   */
}

bool IsSortedUp(node* headPtr)
{
   if (!headPtr || !headPtr->link) return true;   // empty or 1-node
   while (headPtr->link) // not at last node
   {
      if (headPtr->link->data < headPtr->data) return false;
      headPtr = headPtr->link;
   }
   return true;
}

bool DelFirstTargetNode(node*& headPtr, int target)
{
   node *precursor = 0, * cursor = headPtr;
   while (cursor && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   if (!cursor)
   {
      std::cout << target << " not found." << std::endl;
      return false;
   }
   if (cursor == headPtr) { headPtr = headPtr->link; }   //OR precursor == 0
   else { precursor->link = cursor->link; }
   delete cursor;
   return true;
}

bool DelNodeBefore1stMatch(node*& headPtr, int target)
{
   if (!headPtr || !headPtr->link || headPtr->data == target) return false;
   node *cur = headPtr->link, *pre = headPtr, *prepre = 0;
   while (cur && cur->data != target)
   {
      prepre = pre;
      pre = cur;
      cur = cur->link;
   }
   if (!cur) { return false; }
   if (cur == headPtr->link)
   {
      headPtr = cur;
      delete pre;
   }
   else
   {
      prepre->link = cur;
      delete pre;
   }
   return true;
}

bool DelNodeAfter1stMatch(node*& headPtr, int target)
{
   if (!headPtr || !headPtr->link) return false;
   while (headPtr->link && headPtr->data != target)
      headPtr = headPtr->link;
   if (!headPtr->link) return false;
   node* holdPtr = headPtr->link;
   headPtr->link = holdPtr->link;
   delete holdPtr;
   return true;
}

int FindListLength(node* headPtr)
{
   int length = 0;
   while (headPtr)
   {
      ++length;
      headPtr = headPtr->link;
   }
   return length;
}

void FindMinMax(node* headPtr, int& minValue, int& maxValue)
{
   if (!headPtr)
   {
      std::cerr << "FindMinMax() attempted on empty list" << std::endl;
      std::cerr << "Minimum and maximum values not set" << std::endl;
   }
   else
   {
      minValue = maxValue = headPtr->data;
      while (headPtr->link)
      {
         headPtr = headPtr->link;
         if (headPtr->data < minValue) minValue = headPtr->data;
         else if (headPtr->data > maxValue) maxValue = headPtr->data;
      }
   }
}

double FindAverage(node* headPtr)
{
   if (!headPtr)
   {
      std::cerr << "FindAverage() attempted on empty list" << std::endl;
      std::cerr << "An arbitrary zero value is returned" << std::endl;
      return 0.0;
   }
   else
   {
      int sum = 0, count = 0;
      while (headPtr)
      {
         ++count;
         sum += headPtr->data;
         headPtr = headPtr->link;
      }
      return double(sum) / count;
   }
}

bool HasDup(node* headPtr) 
{ 
   if (!headPtr || !headPtr->link) return false;
   Node* cursor = 0; 
   int anchorData; 
   while (headPtr->link) // anchor node not last node 
   { 
      anchorData = headPtr->data; 
      cursor = headPtr->link; // points to 1st node downstream of anchor node 
      while (cursor) 
      { 
         if (cursor->data == anchorData) return true; 
         cursor = cursor->link; 
      } 
      headPtr = headPtr->link; 
   } 
   return false; 
}

bool Swap1stTargetNodeWithNodeB4(node*& headPtr, int target) 
{ 
   if (!headPtr || !headPtr->link || headPtr->data == target) return false; 
   node *cur = headPtr->link, *pre = headPtr, *prepre = 0; 
   while (cur && cur->data != target) 
   { 
      prepre = pre; 
      pre = cur; 
      cur = cur->link; 
   } 
   if (!cur) return false; 
   if (cur == headPtr->link) 
   { 
      pre->link = cur->link; 
      cur->link = pre; 
      headPtr = cur;
   else 
   { 
      pre->link = cur->link; 
      cur->link = pre; 
      prepre->link = cur; 
   } 
   return true; 
}

bool LL1IsContainedInLL2(node* headPtr_1, node* headPtr_2) 
{ 
   if (!headPtr_1) return true;  // empty list is always contained (even if 2nd list is empty) 
   if (!headPtr_2) return false; // list1 can't be empty so can't be contained if list2 is empty 
   node* headPtr_2_copy = headPtr_2; 
   while (headPtr_1) 
   { 
      while (headPtr_2_copy) 
      { 
         if (headPtr_1->data == headPtr_2_copy->data) break; 
         headPtr_2_copy = headPtr_2_copy->link; 
      } 
      if (!headPtr_2_copy) return false; 
      headPtr_1 = headPtr_1->link; 
      headPtr_2_copy = headPtr_2; 
   } 
   return true; 
}

void ShowAll(std::ostream& outs, node* headPtr)
{
   while (headPtr)
   {
      outs << headPtr->data << "  ";
      headPtr = headPtr->link;
   }
   outs << std::endl;
}

void ListClear(node*& headPtr)
{
   int count = 0;
   node *cursor = headPtr;
   while (headPtr)
   {
      headPtr = headPtr->link;
      delete cursor;
      cursor = headPtr;
      ++count;
   }

   std::clog << "Dynamic memory for " << count << " nodes freed"
             << std::endl;
}
