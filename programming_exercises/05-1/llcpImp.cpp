#include <iostream>
#include <cstdlib>
#include "llcpInt.h"
using namespace std;

int FindListLength(Node* headPtr)
{
   int length = 0;

   while (headPtr != 0)
   {
      ++length;
      headPtr = headPtr->link;
   }

   return length;
}

bool IsSortedUp(Node* headPtr)
{
   if (headPtr == 0 || headPtr->link == 0) // empty or 1-node
      return true;
   while (headPtr->link != 0) // not at last node
   {
      if (headPtr->link->data < headPtr->data)
         return false;
      headPtr = headPtr->link;
   }
   return true;
}

void InsertAsHead(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = headPtr;
   headPtr = newNodePtr;
}

void InsertAsTail(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = 0;
   if (headPtr == 0)
      headPtr = newNodePtr;
   else
   {
      Node *cursor = headPtr;

      while (cursor->link != 0) // not at last node
         cursor = cursor->link;
      cursor->link = newNodePtr;
   }
}

void InsertSortedUp(Node*& headPtr, int value)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   }

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = cursor;
   if (cursor == headPtr)
      headPtr = newNodePtr;
   else
      precursor->link = newNodePtr;

   ///////////////////////////////////////////////////////////
   /* using-only-cursor (no precursor) version
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   //newNodePtr->link = 0;
   //if (headPtr == 0)
   //   headPtr = newNodePtr;
   //else if (headPtr->data >= value)
   //{
   //   newNodePtr->link = headPtr;
   //   headPtr = newNodePtr;
   //}
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   //else if (headPtr->link == 0)
   //   head->link = newNodePtr;
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

   ////////////////// commented lines removed //////////////////

   Node *newNodePtr = new Node;
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
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }
   */
   ///////////////////////////////////////////////////////////
}

bool DelFirstTargetNode(Node*& headPtr, int target)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   if (cursor == 0)
   {
      cout << target << " not found." << endl;
      return false;
   }
   if (cursor == headPtr) //OR precursor == 0
      headPtr = headPtr->link;
   else
      precursor->link = cursor->link;
   delete cursor;
   return true;
}

bool DelNodeBefore1stMatch(Node*& headPtr, int target)
{
   if (headPtr == 0 || headPtr->link == 0 || headPtr->data == target) return false;
   Node *cur = headPtr->link, *pre = headPtr, *prepre = 0;
   while (cur != 0 && cur->data != target)
   {
      prepre = pre;
      pre = cur;
      cur = cur->link;
   }
   if (cur == 0) return false;
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

void ShowAll(ostream& outs, Node* headPtr)
{
   while (headPtr != 0)
   {
      outs << headPtr->data << "  ";
      headPtr = headPtr->link;
   }
   outs << endl;
}

void FindMinMax(Node* headPtr, int& minValue, int& maxValue)
{
   if (headPtr == 0)
   {
      cerr << "FindMinMax() attempted on empty list" << endl;
      cerr << "Minimum and maximum values not set" << endl;
   }
   else
   {
      minValue = maxValue = headPtr->data;
      while (headPtr->link != 0)
      {
         headPtr = headPtr->link;
         if (headPtr->data < minValue)
            minValue = headPtr->data;
         else if (headPtr->data > maxValue)
            maxValue = headPtr->data;
      }
   }
}

double FindAverage(Node* headPtr)
{
   if (headPtr == 0)
   {
      cerr << "FindAverage() attempted on empty list" << endl;
      cerr << "An arbitrary zero value is returned" << endl;
      return 0.0;
   }
   else
   {
      int sum = 0,
          count = 0;

      while (headPtr != 0)
      {
         ++count;
         sum += headPtr->data;
         headPtr = headPtr->link;
      }

      return double(sum) / count;
   }
}

void ListClear(Node*& headPtr, int noMsg)
{
   int count = 0;

   Node *cursor = headPtr;
   while (headPtr != 0)
   {
      headPtr = headPtr->link;
      delete cursor;
      cursor = headPtr;
      ++count;
   }
   if (noMsg) return;
   clog << "Dynamic memory for " << count << " nodes freed"
        << endl;
}

// definition of RemBadSplitGood of Assignment 5 Part 1
void RemBadSplitGood(Node*& head, Node*& head_LE5, Node*& head_GE7)
{
   const int SENTINEL = -99;
   const short int LIST_1_VAL = 6, 
                   LIST_2_LOWER = 0, LIST_2_UPPER = 5, 
                   LIST_3_LOWER = 7, LIST_3_UPPER = 9,
                   VALID_RANGE_LOWER = 0, VALID_RANGE_UPPER = 9;
   bool list1empty = true, list2empty = true, list3empty = true;

   Node* head_pre = 0, * head_cur = head;

   head_LE5 = 0, head_GE7 = 0;
   Node* LE5_tail = 0, * GE7_tail = 0;

   while (head_cur) 
   {
      if ( (head_cur->data < VALID_RANGE_LOWER) || (head_cur->data > VALID_RANGE_UPPER) )
      {
         // If head_cur points to the first node in List 1...
         if (!head_pre) {
            // If the next node is not null, set head to the next node.
            if (head_cur->link)
            { 
               head = head_cur->link; 
               delete head_cur;
               head_cur = head;
               continue;
            // If the next node is null, set head to sentinel.
            } else {
               delete head_cur;
               Node* sentinelNode_head = new Node;
               sentinelNode_head->data = SENTINEL;
               sentinelNode_head->link = 0;
               head = sentinelNode_head;
               list1empty = false;
            }
         }
         // If head_cur does not point to first node in List 1...
         if (head_pre) {
            if (head_cur->link) {
               head_pre->link = head_cur->link;
               delete head_cur;
               head_cur = head_pre;
            } else {
               head_pre->link = 0;
               delete head_cur;
               head_cur = head_pre;
            }
         }
      }

      if (head_cur->data >= LIST_2_LOWER && head_cur->data <= LIST_2_UPPER)
      {
         if (!head_LE5)
         {
            head_LE5 = head_cur;
            LE5_tail = head_LE5;
            list2empty = false;
         }
         else
         {
            LE5_tail->link = head_cur;
            LE5_tail = head_cur;
         }
         if (!head_pre)
         {
            head = head_cur->link;
            LE5_tail->link = 0;
            head_cur = head;
            continue;
         }
         else
         {
            head_pre->link = head_cur->link;
            head_cur = head_pre;
         }
         LE5_tail->link = 0;
      }

      if (head_cur->data >= LIST_3_LOWER && head_cur->data <= LIST_3_UPPER)
      {
         if (!head_GE7)
         {
            head_GE7 = head_cur;
            GE7_tail = head_GE7;
            
            list3empty = false;
         }
         else
         {
            GE7_tail->link = head_cur;
            GE7_tail = head_cur;
         }
         if (!head_pre)
         {
            head = head_cur->link;
            GE7_tail->link = 0;
            head_cur = head;
            continue;
         }
         else
         {
            head_pre->link = head_cur->link;
            head_cur = head_pre;
         }
         GE7_tail->link = 0;
      }

      if (head_cur->data == LIST_1_VAL) { list1empty = false; }

      // Break if list 1 link is null, otherwise advance head_cur.
      if (head_cur->link) {
         head_pre = head_cur;
         head_cur = head_cur->link;
         if (!list2empty) {}
         if (!list3empty) {}
      } else {
         break;
      }
   }

   if (list1empty) {
      Node* sentinelNode_head = new Node;
      sentinelNode_head->data = SENTINEL;
      sentinelNode_head->link = 0;
      head = sentinelNode_head;
   }

   if (list2empty) {
      Node* sentinelNode_head = new Node;
      sentinelNode_head->data = SENTINEL;
      sentinelNode_head->link = 0;
      head_LE5 = sentinelNode_head;
   }

   if (list3empty) {
      Node* sentinelNode_head = new Node;
      sentinelNode_head->data = SENTINEL;
      sentinelNode_head->link = 0;
      head_GE7 = sentinelNode_head;
   }

}
