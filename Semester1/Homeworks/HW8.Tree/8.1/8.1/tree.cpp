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

void insert(Node *node, int key, char *value)
{
	if (key == node->key)
	{
		delete[] node->value;
		node->value = value;
		return;
	}

	if (key < node->key)
	{
		if (node->leftChild == nullptr)
		{
			node->leftChild = new Node {key, value, node, nullptr, nullptr};
			return;
		}
		insert(node->leftChild, key, value);
	}

	if (key > node->key)
	{
		if (node->rightChild == nullptr)
		{
			node->rightChild = new Node {key, value, node, nullptr, nullptr};
			return;
		}
		insert(node->rightChild, key, value);
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
	insert(tree->root, key, newValue);
}

char *get(Node *node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key == node->key)
	{
		char *value = new char[strlen(node->value) + 1];
		strcpy(value, node->value);
		return value;
	}

	return key < node->key ? get(node->leftChild, key) : get(node->rightChild, key);
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

	return key < node->key ? find(node->leftChild, key) : find(node->rightChild, key);
}

bool contains(Tree *tree, int key)
{
	return find(tree->root, key);
}

Node *findNodeClosestToMiddle(Node *node)
{
	Node *rightmostNodeOnTheLeft = node->leftChild;
	int leftPathLength = 1;
	while (rightmostNodeOnTheLeft->rightChild != nullptr)
	{
		rightmostNodeOnTheLeft = rightmostNodeOnTheLeft->rightChild;
		leftPathLength++;
	}

	Node *leftmostNodeOnTheLeft = node->rightChild;
	int rightPathLength = 1;
	while (leftmostNodeOnTheLeft->leftChild != nullptr)
	{
		leftmostNodeOnTheLeft = leftmostNodeOnTheLeft->leftChild;
		rightPathLength++;
	}

	return (leftPathLength > rightPathLength) ? rightmostNodeOnTheLeft : leftmostNodeOnTheLeft;
}

void copyData(Node *destination, Node *source)
{
	char *newValue = new char[strlen(source->value) + 1];
	strcpy(newValue, source->value);
	delete[] destination->value;

	destination->value = newValue;
	destination->key = source->key;
}

void deleteNode(Node *node, int key)
{
	if (node == nullptr)
	{
		return;
	}

	if (key == node->key)
	{
		if (node->rightChild != nullptr && node->leftChild != nullptr)
		{
			Node *helpNode = findNodeClosestToMiddle(node);
			copyData(node, helpNode);
			deleteNode(helpNode, helpNode->key);
			return;
		}

		if (node->rightChild == nullptr)
		{
			if (node->leftChild != nullptr)
			{
				node->leftChild->parent = node->parent;
			}
			key < node->parent->key ? node->parent->leftChild = node->leftChild : node->parent->rightChild = node->leftChild;
		}
		else 
		{
			if (node->rightChild != nullptr)
			{
				node->rightChild->parent = node->parent;
			}
			key < node->parent->key ? node->parent->leftChild = node->rightChild : node->parent->rightChild = node->rightChild;
		}
		delete[] node->value;
		delete node;
		return;
	}

	key < node->key ? deleteNode(node->leftChild, key) : deleteNode(node->rightChild, key);
}

void deleteRoot(Tree *tree)
{
	if (tree->root->rightChild != nullptr && tree->root->leftChild != nullptr)
	{
		Node *helpNode = findNodeClosestToMiddle(tree->root);
		copyData(tree->root, helpNode);
		deleteNode(helpNode, helpNode->key);
		return;
	}

	Node *newRoot = nullptr;
	if (tree->root->rightChild == nullptr)
	{
		newRoot = tree->root->leftChild;
	}
	else
	{
		newRoot = tree->root->rightChild;
	}
	if (newRoot != nullptr)
	{
		newRoot->parent = nullptr;
	}
	delete[] tree->root->value;
	delete tree->root;
	tree->root = newRoot;
}

void deleteValue(Tree *tree, int key)
{
	if (isEmpty(tree))
	{
		return;
	}

	if (tree->root->key == key)
	{
		deleteRoot(tree);
		return;
	}
	deleteNode(tree->root, key);
}

void deleteChildren(Node *node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteChildren(node->leftChild);
	deleteChildren(node->rightChild);
	delete[] node->value;
	delete node;
}

void deleteTree(Tree *tree)
{
	deleteChildren(tree->root);
	delete tree;
}