#include "AvlTree.h"
#include <iostream>

using namespace std;

int main() {
	AvlTree<int>* avltree = new AvlTree<int>(5);
	avltree->insert(8);
	avltree->insert(9);
	avltree->insert(2);
	avltree->insert(1);
	std::cout << "InOrder" << std::endl;
	avltree->inOrder();
	std::cout << "max: "<< avltree->findMax() << std::endl;
	std::cout << "min: "<< avltree->findMin() << std::endl;
	delete avltree;
	return 0;
}
