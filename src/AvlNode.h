#ifndef AVLNODE_H_
#define AVLNODE_H_

#include <algorithm>

template<class T>
class AvlNode {
private:
	T data;
	AvlNode<T>* left;
	AvlNode<T>* right;
	unsigned height;
public:
	AvlNode(T data);
	T getData();
	void setData(T data);
	unsigned getHeight();
	void setHeight(unsigned height);
	AvlNode<T>* getLeft();
	void setLeft(AvlNode<T>* left);
	AvlNode<T>* leftRotation();
	AvlNode<T>* rightRotation();
	AvlNode<T>* LeftRightRotation();
	AvlNode<T>* rightLeftRotation();
	AvlNode<T>* getRight();
	void updateHeight();

	void setRight(AvlNode<T>* right);
	unsigned getBalance();
	virtual ~AvlNode();
};

template<class T>
AvlNode<T>::AvlNode(T data) : data(data), left(nullptr), right(nullptr), height(1){
}

template<class T>
T AvlNode<T>::getData() {
	return data;
}

template<class T>
void AvlNode<T>::setData(T data) {
	this->data = data;
}

template<class T>
unsigned AvlNode<T>::getHeight() {
	return height;
}

template<class T>
void AvlNode<T>::setHeight(unsigned height) {
	this->height = height;
}

template<class T>
AvlNode<T>* AvlNode<T>::getLeft() {
	return left;
}

template<class T>
void AvlNode<T>::setLeft(AvlNode<T>* left) {
	this->left = left;
}

template<class T>
AvlNode<T>* AvlNode<T>::leftRotation() {
	AvlNode<T>* pivot = right;
	right = right->left;
	pivot->left = this;
	this->updateHeight();
	pivot->updateHeight();
	return pivot;
}

template<class T>
AvlNode<T>* AvlNode<T>::rightRotation() {
	AvlNode<T>* pivot = left;
	left = left->right;
	pivot->right = this;
	this->updateHeight();
	pivot->updateHeight();
	return pivot;
}

template<class T>
AvlNode<T>* AvlNode<T>::LeftRightRotation() {
	right = right->rightRotation();
	return this->leftRotation();
}

template<class T>
AvlNode<T>* AvlNode<T>::rightLeftRotation() {
	left = left->leftRotation();
	return this->rightRotation();
}

template<class T>
AvlNode<T>* AvlNode<T>::getRight() {
	return right;
}



template<class T>
void AvlNode<T>::setRight(AvlNode<T>* right) {
	this->right = right;
}

template<class T>
unsigned AvlNode<T>::getBalance() {
	return (left != nullptr ? left->getHeight() : 0)
			- (right != nullptr ? right->getHeight() : 0);
}

template<class T>
void AvlNode<T>::updateHeight() {
	height = std::max(left != nullptr ? left->getHeight() : 0,
			right != nullptr ? right->getHeight() : 0) + 1;
}


template<class T>
AvlNode<T>::~AvlNode() {
	delete left;
	delete right;
}
#endif
