#include <iostream>

struct node {
   int data;
   node* link;
};

void insert_as_head(node*&, int);
void insert_as_tail(node*&, int);
void insert_sorted_up(node*&, int);
// etc.

int main()
{
   
	return 0;
}

void insert_as_head(node*& head_ptr, int value)
{
   node* new_node_ptr = new node;
   new_node_ptr->data = value;
   new_node_ptr->link = head_ptr;
   head_ptr = new_node_ptr;
}

void insert_as_tail(node*& head_ptr, int value)
{
   node* new_node_ptr = new node;
   new_node_ptr->data = value;
   new_node_ptr->link = 0;
   if (!head_ptr)
   {
      head_ptr = new_node_ptr;
      return;
   }
   node* cursor = head_ptr;
   while (cursor->link) { cursor = cursor->link; }
   cursor->link = new_node_ptr;
}

void insert_sorted_up(node*& head_ptr, int value)
{
   node* precursor = 0, * cursor = head_ptr;
   while (cursor && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   node* new_node_ptr = new node;
   new_node_ptr->data = value;
   new_node_ptr->link = cursor;
   if (cursor == head_ptr) { head_ptr = new_node_ptr; }
   else { precursor->link = new_node_ptr; }
}

bool is_sorted_up(node* head_ptr)
{
   if (!head_ptr || !head_ptr->link) { return true; }
   while (head_ptr->link)
   {
      if (head_ptr->link->data < head_ptr->data) { return false; }
      head_ptr = head_ptr->link;
   }
   return true;
}

bool delete_first_target_node(node*& head_ptr, int target)
{
   node* precursor = 0, * cursor = head_ptr;
   while (cursor && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   if (!cursor) { return false; }
   if (cursor == head_ptr) { head_ptr = head_ptr->link; }
   else { precursor->link = cursor->link; }
   delete cursor;
   return true;
}
