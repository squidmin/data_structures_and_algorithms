
#ifndef NODE_H
#define NODE_H

namespace jamesrmorse
{
	class node
	{
	public:
		node() : data_field(0), link_field(0) { }

		node(const double& init_data, node* init_link) : 
		data_field(init_data), link_field(init_link) { }

		// Member functions to set the data and link fields:
		void set_data(const double& new_data)     { data_field = new_data; }
		void set_link(node* new_link)             { link_field = new_link; }

		// To retreive the current data:
		double data() const { return data_field; }
		
		// Two slightly different member functions to retrieve the current link:
		const node* link() const { return link_field; }
		node* link()             { return link_field; }

	private:
		double data_field;
		node* link_field;
	};

	// FUNCTIONS for the linked list toolkit:
	unsigned int list_length(const node* head_ptr);
	void list_clear(node*& head_ptr);
	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
}

#endif
