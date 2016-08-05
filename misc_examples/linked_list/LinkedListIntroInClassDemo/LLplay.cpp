#include "LLutil.h"
#include <iostream>
using namespace std;

int main()
{
   Node* head = 0;

   InsertAtHead(head, 100);
   InsertAtHead(head, 101);
   InsertAtHead(head, 102);
   InsertAtHead(head, 103);
   InsertAtHead(head, 104);
   AppendAtTail(head, 105);
   AppendAtTail(head, 105);
   AppendAtTail(head, 106);
   AppendAtTail(head, 107);
   AppendAtTail(head, 108);
   ShowList(head);
   cout << endl;
   ClearList(head);

   return 0;
}
