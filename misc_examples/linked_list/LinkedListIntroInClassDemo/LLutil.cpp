#include "LLutil.h"
#include <iostream>
using namespace std;

void InsertAtHead(Node*& head, int anInt)
{
   Node* nodePtr = new Node;
   nodePtr->data = anInt;
   nodePtr->link = head;
   head = nodePtr;
}

void ShowList(Node* head)
{
   //Node* cur = head;
   //while (cur != 0)
   while (head != 0)
   {
      //cout << cur->data << endl;
      cout << head->data << endl;
      //cur = cur->link;
      head = head->link;
   }
}

void AppendAtTail(Node*& head, int anInt)
{
   Node* nodePtr = new Node;
   nodePtr->data = anInt;
   nodePtr->link = 0;
   if (head == 0)
   {
      head = nodePtr;
      return;
   }
   Node* cur = head;
   while (cur->link != 0)
      cur = cur->link;
   cur->link = nodePtr;
}


void ClearList(Node*& head)
{
   Node* hold = 0;
   while (head != 0)
   {
      cout << head->data << " freed" << endl;
      hold = head->link;
      delete head;
      head = hold;
   }
}

