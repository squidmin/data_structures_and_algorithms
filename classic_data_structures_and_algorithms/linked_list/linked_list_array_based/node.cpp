#include <iostream>
#include "node.h"

namespace jamesrmorse
{
	/*
	unsigned int list_length(const node* head_ptr)
	Precondition: head_ptr is the head pointer of a linked list.
	Postcondition: The value returned is the number of nodes in the linked list.
	*/
	unsigned int list_length(const node* head_ptr)
	{
		unsigned int answer = 0;
		const node* cursor = head_ptr;
		while (cursor)
		{
			++answer;
			cursor = cursor->link_field;
		}
		return answer;
	}

	/*
	Precondition: head_ptr is the head pointer of a linked list.
	Postcondition: Memory allocated for the list pointed to by head_ptr is given back to the heap.
	*/
	void list_clear(node*& head_ptr)
	{
        node* cursor = head_ptr;
        while (head_ptr)
        {
            cursor = head_ptr;
            head_ptr = head_ptr->link();
            delete cursor;
        }
        head_ptr = 0;
	}

	/*
	Precondition: source_ptr is the head pointer of a linked list.
	                 head_ptr does not point to anything relevant.
	                 tail_ptr does not point to anything relevant.
	Postcondition: head_ptr will point to the first node of a copy of the linked list pointed to by source_ptr;
                     tail_ptr will point to the last node of a copy of the linked list pointed to by source_ptr.
	*/
	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
	{
	    if (!source_ptr) return;
	    head_ptr = 0, tail_ptr = 0;
	    head_ptr = new node(entry, head_ptr);
	    tail_ptr = head_ptr;
	    source_ptr = source_ptr->link();
	    while (source_ptr)
	    {
	   	    node* insert_ptr = new node(source_ptr->data(), tail_ptr->link());
            tail_ptr = tail_ptr->link();
            source_ptr = source_ptr->link();
	    }
	}
}
