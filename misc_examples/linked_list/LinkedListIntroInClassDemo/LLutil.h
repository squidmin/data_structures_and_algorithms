struct Node
{
   int data;
   Node* link;
};

void InsertAtHead(Node*& head, int anInt);
void ShowList(Node* head);
void ClearList(Node*& head);
void AppendAtTail(Node*& head, int anInt);
