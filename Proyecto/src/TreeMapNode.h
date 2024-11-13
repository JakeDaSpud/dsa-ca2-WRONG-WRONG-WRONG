#pragma once
#include <iostream>

template <typename K, typename V>
class TreeMapNode
{
	
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
	V& getValue();

	TreeMapNode<K, V>* getParent();
	TreeMapNode<K, V>* getLeft();
	TreeMapNode<K, V>* getRight();
	void setLeft(TreeMapNode<K, V> *l);
	void setRight(TreeMapNode<K, V> *r);

	~TreeMapNode();

};

template <typename K, typename V>
TreeMapNode<K, V>::TreeMapNode(const TreeMapNode<K, V> &other)
{
	left = right = nullptr;
	if(other.left != nullptr)
		this->left = new TreeMapNode<K, V>(*other.left);
	if(other.right != nullptr)
		this->right = new TreeMapNode<K, V>(*other.right);

}

template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::operator=(const TreeMapNode<K, V>& other)
{
	if (this == &other)
		return *this;
	left = right = nullptr;
	if (other.left != nullptr)
		this->left = new TreeMapNode<K, V>(*other.left);
	if (other.right != nullptr)
		this->right = new TreeMapNode<K, V>(*other.right);
	
}
template <typename K, typename V>
TreeMapNode<K, V>::~TreeMapNode()
{
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
V& TreeMapNode<K, V>::getValue()
{
	return this->value;
}
template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::getLeft()
{
	return this->left;
}
template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::getRight()
{
	return this->right;
}
template <typename K, typename V>
TreeMapNode<K, V>* TreeMapNode<K, V>::getParent()
{
	return this->parent;
}
template <typename K, typename V>
void TreeMapNode<K, V>::setLeft(TreeMapNode<K, V> *l)
{
	this->left = l;
}
template <typename K, typename V>
void TreeMapNode<K, V>::setRight(TreeMapNode<K, V> *r)
{
	this->right = r;
}


template <typename K, typename V>
TreeMapNode<K, V>::TreeMapNode()
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}


template <typename K, typename V>
TreeMapNode<K, V>::TreeMapNode(K key, V value)
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	this->data = data;
}
template <typename K, typename V>
int TreeMapNode<K, V>::count()
{
	int c = 1;
	if (left != nullptr)
	{
		c += left->count();
	}
	if (right != nullptr)
	{
		c += right->count();
	}
	return c;
}

template <typename K, typename V>
void TreeMapNode<K, V>::add(K& key, V& value)
{
	if (item == this->data)
	{
		return;
	}
	else if (item < this->data)
	{
		if (left == nullptr)
		{
			left = new TreeMapNode<K, V>();
			left->data = item;
			left->parent = this;
		}
		else
		{
			left->add(item);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new TreeMapNode<K, V>();
			right->data = item;
			right->parent = this;
		}
		else
		{
			right->add(item);
		}
	}
}

template <typename K, typename V>
void TreeMapNode<K, V>::setItem(K& key, V& value)
{
	this->key = key;
	this->value = value;
}

