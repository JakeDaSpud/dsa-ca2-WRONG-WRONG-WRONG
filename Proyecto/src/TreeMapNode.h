#pragma once
#ifndef _TREEMAPNODE_H_
#define _TREEMAPNODE_H_

#include <iostream>

template <typename K, typename V>
class TreeMapNode {
private:
	TreeMapNode<K, V> *parent;
	TreeMapNode<K, V> *left;
	TreeMapNode<K, V> *right;
	K key;
	V value;
	
public:
	TreeMapNode();
	TreeMapNode(const TreeMapNode<K, V> &other);
	TreeMapNode<K, V>* operator=(const TreeMapNode<K, V> &other);
	TreeMapNode(K key, V value);

	void setItem(K& key, V& value);
	int count();
	void add(K& key, V& value);
	V& get();

	TreeMapNode<K, V>* getParent();
	TreeMapNode<K, V>* getLeft();
	TreeMapNode<K, V>* getRight();
	void setLeft(TreeMapNode<K, V> *l);
	void setRight(TreeMapNode<K, V> *r);

	~TreeMapNode();
};

template <typename K, typename V>
TreeMapNode<K, V>::TreeMapNode(const TreeMapNode<K, V> &other) {
	left = right = nullptr;

	if (other.left != nullptr)
		this->left = new TreeMapNode<K, V>(*other.left);

	if (other.right != nullptr)
		this->right = new TreeMapNode<K, V>(*other.right);
}

template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::operator=(const TreeMapNode<K, V>& other) {
	if (this == &other)
		return *this;

	left = right = nullptr;

	if (other.left != nullptr)
		this->left = new TreeMapNode<K, V>(*other.left);

	if (other.right != nullptr)
		this->right = new TreeMapNode<K, V>(*other.right);
	
}

template <typename K, typename V>
TreeMapNode<K, V>::~TreeMapNode() {
	if (left != nullptr)
	{
		delete left;
		left = nullptr;
	}
	if(right!= nullptr)
	{
		delete right;
		right = nullptr;
	}

}

template <typename K, typename V>
V& TreeMapNode<K, V>::get() {
	return this->value;
}

template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::getLeft() {
	return this->left;
}

template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::getRight() {
	return this->right;
}

template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::getParent() {
	return this->parent;
}

template <typename K, typename V>
void TreeMapNode<K, V>::setLeft(TreeMapNode<K, V> *l) {
	this->left = l;
}

template <typename K, typename V>
void TreeMapNode<K, V>::setRight(TreeMapNode<K, V> *r) {
	this->right = r;
}

template <typename K, typename V>
TreeMapNode<K, V>::TreeMapNode() {
	parent = left = right = nullptr;
}

template <typename K, typename V>
TreeMapNode<K, V>::TreeMapNode(K key, V value) {
	parent = left = right = nullptr;
	this->key = key;
	this->value = value;
}

template <typename K, typename V>
int TreeMapNode<K, V>::count() {
	int count = 1;

	if (left != nullptr) {
		count += left->count();
	}

	if (right != nullptr) {
		count += right->count();
	}

	return count;
}

template <typename K, typename V>
void TreeMapNode<K, V>::add(K& key, V& value) {
	// This is a set implementation, only one of a value will be stored
	if (value == this->value) {
		return;
	}

	else if (value < this->value) {
		if (left == nullptr) {
			left = new TreeMapNode<K, V>();
			left->key = key;
			left->value = value;
			left->parent = this;
		}

		else {
			left->add(key, value);
		}
	}
	
	else {
		if (right == nullptr) {
			right = new TreeMapNode<K, V>();
			right->key = key;
			right->value = value;
			right->parent = this;
		}

		else {
			right->add(key, value);
		}
	}
}

template <typename K, typename V>
void TreeMapNode<K, V>::setItem(K& key, V& value) {
	this->key = key;
	this->value = value;
}

#endif