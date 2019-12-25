#include <string.h>
#include "avlTree.h"

struct Node
{
	int key;
	char *value;
	int height;
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

int getHeight(Node *node)
{
	return node != nullptr ? node->height : -1;
}

int getBalanceFactor(Node *node)
{
	return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void updateHeight(Node *node)
{
	int heightLeft = getHeight(node->leftChild);
	int heightRight = getHeight(node->rightChild);
	node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

Node *rotateRight(Node *root)
{
	Node *pivot = root->leftChild;
	root->leftChild = pivot->rightChild;
	pivot->parent = root->parent;
	if (pivot->rightChild != nullptr)
	{
		pivot->rightChild->parent = root;
	}

	pivot->rightChild = root;
	root->parent = pivot;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}

Node *rotateLeft(Node *root)
{
	Node *pivot = root->rightChild;
	root->rightChild = pivot->leftChild;
	pivot->parent = root->parent;
	if (pivot->leftChild != nullptr)
	{
		pivot->leftChild->parent = root;
	}

	pivot->leftChild = root;
	root->parent = pivot;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}

Node *balance(Node *node)
{
	updateHeight(node);
	if (getBalanceFactor(node) == 2)
	{
		if (getBalanceFactor(node->rightChild) < 0)
		{
			node->rightChild = rotateRight(node->rightChild);
		}
		return rotateLeft(node);
	}
	if (getBalanceFactor(node) == -2)
	{
		if (getBalanceFactor(node->leftChild) > 0)
		{
			node->leftChild = rotateLeft(node->leftChild);
		}
		return rotateRight(node);
	}
	return node;
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
			node->leftChild = new Node {key, value, 0, node, nullptr, nullptr};
			return;
		}
		insert(node->leftChild, key, value);
		node->leftChild = balance(node->leftChild);
	}

	if (key > node->key)
	{
		if (node->rightChild == nullptr)
		{
			node->rightChild = new Node {key, value, 0, node, nullptr, nullptr};
			return;
		}
		insert(node->rightChild, key, value);
		node->rightChild = balance(node->rightChild);
	}
}

void addValue(Tree *tree, int key, char *value)
{
	char *newValue = new char[strlen(value) + 1];
	strcpy(newValue, value);
	if (isEmpty(tree))
	{
		tree->root = new Node {key, newValue, 0, nullptr, nullptr, nullptr};
		return;
	}
	insert(tree->root, key, newValue);
	tree->root = balance(tree->root);
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
	strcpy(destination->value, source->value);
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
			key < node->parent->key)? node->parent->leftChild = node->leftChild: node->parent->rightChild = node->leftChild;
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

	Node *parent = node->parent;
	if (key < node->key)
	{
		deleteNode(node->leftChild, key);
	}
	else
	{
		deleteNode(node->rightChild, key);
	}
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
	/tree->root = balance(newRoot);
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