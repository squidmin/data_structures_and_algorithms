#include <iostream>
#include "node.h"
using namespace jamesrmorse;

int main() 
{
	std::cout << std::endl << "Creating node_1 (using default constructor)..." << std::endl;
	node* node_1 = new node();
	std::cout << std::endl << "node_1 fields:" << std::endl;
	std::cout << std::endl << "node_1->data() == " << node_1->data() << std::endl;
	std::cout << std::endl << "node_1->link() == " << node_1->link() << std::endl;
	
	std::cout << std::endl << "Creating node_2 (using non-default constructor)..." << std::endl;
	node* node_2 = new node(12.34, node_1);
	std::cout << std::endl << "node_2 fields:" << std::endl;
	std::cout << std::endl << "node_2->data() == " << node_2->data() << std::endl;
	std::cout << std::endl << "node_2->link() == " << node_2->link() << std::endl;

	return 0;
}