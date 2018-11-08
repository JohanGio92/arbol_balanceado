#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "AvlNode.h"
#include <algorithm>
#include <iostream>

template <class T>
class AvlTree {
private:
	AvlNode<T>* head;
	bool isEmpty(AvlNode<T>* avlNode);
	void destroy(AvlNode<T>* node);
	void inOrder(AvlNode<T>* node);
	AvlNode<T>* insert(AvlNode<T>* iterator, T data);
public:
	AvlTree(T data);
	void insert(T data);
	AvlNode<T>* search(T data);
	AvlNode<T>* begin();
	T findMin();
	T findMax();
	void inOrder();
	virtual ~AvlTree();
};

template<class T>
AvlTree<T>::AvlTree(T data) {
	head = new AvlNode<T>(data);
}

template<class T>
bool AvlTree<T>::isEmpty(AvlNode<T>* avlNode){
	return avlNode == nullptr;
}

template<class T>
AvlNode<T>* AvlTree<T>::insert(AvlNode<T>* iterator, T data) {
	if (isEmpty(iterator))
		return new AvlNode<T>(data);
	if(data < iterator->getData()){
		iterator->setLeft(this->insert(iterator->getLeft(), data));
	} else if(data > iterator->getData()){
		iterator->setRight(this->insert(iterator->getRight(), data));
	} else{
		return iterator;
	}

	iterator->updateHeight();
	int balance = iterator->getBalance();

	if(balance > 1 && data < iterator->getLeft()->getData()){
		return iterator->rightRotation();
	}

	if(balance < -1 && data > iterator->getRight()->getData()){
		return iterator->leftRotation();
	}

	if(balance > 1 && data > iterator->getLeft()->getData()){
		return iterator->rightLeftRotation();
	}

	if(balance < -1 && data < iterator->getRight()->getData()){
		return iterator->LeftRightRotation();
	}

	return iterator;
}

template<class T>
AvlNode<T>* AvlTree<T>::search(T data) {
	AvlNode<T>* iterator = this->begin();
	bool ok = false;
	while(!this->isEmpty(iterator) && !ok){
		if(iterator->getData() == data){
			ok = true;
		} else if(data < iterator->getData()){
			iterator = iterator->getLeft();
		} else{
			iterator = iterator->getRight();
		}
	}
	return iterator;
}

template<class T>
AvlNode<T>* AvlTree<T>::begin() {
	return head;
}

template<class T>
T AvlTree<T>::findMin() {
	AvlNode<T>* iterator = head;
	while(!this->isEmpty(iterator->getLeft())){
		iterator = iterator->getLeft();
	}
	return iterator->getData();
}

template<class T>
T AvlTree<T>::findMax() {
	AvlNode<T>* iterator = head;
	while (!this->isEmpty(iterator->getRight())) {
		iterator = iterator->getRight();
	}
	return iterator->getData();
}

template<class T>
void AvlTree<T>::destroy(AvlNode<T>* node) {
	if(!this->isEmpty(node)){
		this->destroy(node->getLeft());
		this->destroy(node->getRight());
		delete node;
	}
}

template<class T>
void AvlTree<T>::inOrder() {
	this->inOrder(this->begin());
}

template<class T>
void AvlTree<T>::inOrder(AvlNode<T>* iterator) {
	if (!this->isEmpty(iterator)) {
		this->inOrder(iterator->getLeft());
		this->inOrder(iterator->getRight());
		std::cout << iterator->getData() << std::endl;
	}
}

template<class T>
void AvlTree<T>::insert(T data) {
	head = this->insert(this->begin(), data);
}

template<class T>
AvlTree<T>::~AvlTree() {
	this->destroy(this->begin());
}

#endif
