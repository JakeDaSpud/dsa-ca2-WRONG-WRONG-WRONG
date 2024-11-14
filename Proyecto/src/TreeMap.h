#pragma once
#ifndef _TREEMAP_H_
#define _TREEMAP_H_

#include "TreeMapNode.h"
#include <vector>

template <typename K, typename V>
class TreeMap {
private:
	void addItemToArray(TreeMapNode<K, V> *node, int &pos, TreeMapNode<K, V> *arr);

public:
	TreeMapNode<K, V> *root;

	TreeMap();
	TreeMap(const TreeMap<K, V> &other);
	TreeMap<K, V> operator=(const TreeMap<K, V> &other);

	void add(TreeMapNode<K, V> &node);
	bool remove(TreeMapNode<K, V> &node);
	void clear();
	int count();
	V& get(K &itemKey);

	void printInOrder();
	void printInOrder(TreeMapNode<K, V> *node);
	void printPreOrder();
	void printPreOrder(TreeMapNode<K, V> *node);
	void printPostOrder();
	void printPostOrder(TreeMapNode<K, V> *node);
	TreeMapNode<K, V>* toArray();

	~TreeMap();
};

template <typename K, typename V>
TreeMap<K, V>::TreeMap() {
	root = nullptr;
}

template <typename K, typename V>
TreeMap<K, V>::TreeMap(const TreeMap<K, V> &other) {
	root = nullptr;
	if(other.root != nullptr)
		root = new TreeMapNode<K, V>(*other.root);
}

template <typename K, typename V>
TreeMap<K, V> TreeMap<K, V>::operator=(const TreeMap<K, V> &other) {
	if (this == &other)
		return *this;

	if (other.root != nullptr)
		root = new TreeMapNode<K, V>(*other.root);

	else
		root = nullptr;

	return *this;
}

template <typename K, typename V>
void TreeMap<K, V>::add(TreeMapNode<K, V> &item) {
	if (root == nullptr) {
		root = new TreeMapNode<K, V>(item);
		root->setItem(item);
	}

	else {
		root->add(item);
	}
}

template <typename K, typename V>
int TreeMap<K, V>::count() {
	if (root == nullptr)
		return 0;
	
	return root->count();
}

template <typename K, typename V>
bool TreeMap<K, V>::remove(TreeMapNode<K, V> &node) {
	TreeMapNode<K, V> *toBeRemoved = root;
	TreeMapNode<K, V> *parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{
		if (toBeRemoved->getKey() == node.getKey()) {
			found = true;
		}

		else {
			parent = toBeRemoved;

			if (toBeRemoved->getValue() > itemKey) {
				toBeRemoved = toBeRemoved->getLeft();
			}

			else {
				toBeRemoved = toBeRemoved->getRight();
			}
		}
	}

	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr) {
		TreeMapNode<K, V> *newChild;

		if (toBeRemoved->getLeft() == nullptr) {
			newChild = toBeRemoved->getRight();
		}

		else {
			newChild = toBeRemoved->getLeft();
		}

		if (parent == nullptr) {
			root = newChild;
		}

		else if (parent->getLeft() == toBeRemoved) {
			parent->setLeft(newChild);
		}

		else {
			parent->setRight(newChild);
		}

		return true;
	}

	TreeMapNode<K, V> *smallestParent = toBeRemoved;
	TreeMapNode<K, V> *smallest = toBeRemoved->getRight();
	
	while (smallest->getLeft() != nullptr) {
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}

	toBeRemoved->setItem(smallest->getItem());
	
	if (smallestParent == toBeRemoved) {
		smallestParent->setRight(smallest->getRight());
	}

	else {
		smallestParent->setLeft(smallest->getRight());
	}
}

template <typename K, typename V>
V& TreeMap<K, V>::get(K &itemKey) {
	bool found = false;
	TreeMapNode<K, V>* current = root;

	while (!found) {
		if (current == nullptr)
			break;

		if (current->getKey() == itemKey)
			return current->getItem();
		
		else if (current->getItem() > itemKey)
			current = current->getLeft();
		
		else
			current = current->getRight();
	}

	throw std::logic_error("Item not found");
}

template <typename K, typename V>
void TreeMap<K, V>::addItemToArray(TreeMapNode<K, V>* node, int &pos, TreeMapNode<K, V> *arr) {
	if (node != nullptr) {
		addItemToArray(node->getLeft(), pos, arr);
		arr[pos] = node->getValue();
		pos++;
		addItemToArray(node->getRight(), pos, arr);
	}
}

template <typename K, typename V>
TreeMapNode<K, V> *TreeMap<K, V>::toArray() {
	TreeMapNode<K, V> *arr = new TreeMapNode<K, V>[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}

template <typename K, typename V>
void TreeMap<K, V>::clear() {
	delete root;
	root = nullptr;
}

template <typename K, typename V>
TreeMap<K, V>::~TreeMap() {
	if (root != nullptr)
	{
		delete root;
		root = nullptr;
	}
}

template<typename K, typename V>
void TreeMap<K, V>::printInOrder() {
	this->printInOrder(root);
	std::cout << std::endl;
}

template<typename K, typename V>
void TreeMap<K, V>::printInOrder(TreeMapNode<K, V> *node) {
	
}

template<typename K, typename V>
void TreeMap<K, V>::printPreOrder() {
	this->printPreOrder(root);
	std::cout << std::endl;
}

template<typename K, typename V>
void TreeMap<K, V>::printPreOrder(TreeMapNode<K, V> *node) {

}

template<typename K, typename V>
void TreeMap<K, V>::printPostOrder() {
	this->printPostOrder(root);
	std::cout << std::endl;
}

template<typename K, typename V>
void TreeMap<K, V>::printPostOrder(TreeMapNode<K, V> *node) {

}

#endif