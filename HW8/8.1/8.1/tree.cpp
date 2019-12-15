#include <string.h>
#include "tree.h"

struct Node
{
	int key;
	char *value;
	Node *parent;
	Node *leftChild;
	Node *rightChild;
};

struct Tree
{
	Node *root = nullptr;
};

Tree *createTree()
{
	return new Tree;
}

bool isEmpty(Tree *tree)
{
	return tree->root == nullptr;
}

bool isLeaf(Node *node)
{
	return node->leftChild == nullptr && node->rightChild == nullptr;
}

void insert(Node *node, Node *parent, int key, char *value)
{
	if (key == node->key)
	{
		strcpy(node->value, value);
		node->key = key;
		return;
	}

	if (key < node->key)
	{
		if (node->leftChild == nullptr)
		{
			node->leftChild = new Node {key, value, node, nullptr, nullptr};
			return;
		}
		insert(node->leftChild, node, key, value);
	}

	if (key > node->key)
	{
		if (node->rightChild == nullptr)
		{
			node->rightChild = new Node {key, value, node, nullptr, nullptr};
			return;
		}
		insert(node->rightChild, node, key, value);
	}
}

void addValue(Tree *tree, int key, char *value)
{
	char *newValue = new char[strlen(value) + 1];
	strcpy(newValue, value);
	if (isEmpty(tree))
	{
		tree->root = new Node {key, newValue, nullptr, nullptr, nullptr};
		return;
	}
	insert(tree->root, nullptr, key, newValue);
}

char *get(Node *node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key == node->key)
	{
		return node->value;
	}

	key < node->key ? get(node->leftChild, key) : get(node->rightChild, key);
}

char *getValue(Tree *tree, int key)
{
	return get(tree->root, key);
}

bool find(Node *node, int key)
{
	if (node == nullptr)
	{
		return false;
	}

	if (key == node->key)
	{
		return true;
	}

	key < node->key ? find(node->leftChild, key) : find(node->rightChild, key);
}

bool contains(Tree *tree, int key)
{
	return find(tree->root, key);
}

void deleteChildren(Node *node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteChildren(node->leftChild);
	deleteChildren(node->rightChild);
	delete node->value;
	delete node;
}

void deleteTree(Tree *tree)
{
	deleteChildren(tree->root);
	delete tree;
}