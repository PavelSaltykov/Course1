#include "tree.h"

struct Node
{
	char operation = '\0';
	int operand = 0;
	Node *leftChild = nullptr;
	Node *rightChild = nullptr;
};

struct Tree
{
	Node *root = nullptr;
};

Tree *createTree()
{
	return new Tree;
}

bool isOperation(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

Node *newNode(char *string, int &positionNumber)
{
	positionNumber++;
	while (string[positionNumber] == ' ' || string[positionNumber] == '(' || string[positionNumber] == ')')
	{
		positionNumber++;
	}

	Node *node = new Node;
	if (isOperation(string[positionNumber]))
	{
		node->operation = string[positionNumber];
		node->leftChild = newNode(string, positionNumber);
		node->rightChild = newNode(string, positionNumber);
	}
	else
	{
		node->operand = string[positionNumber] - '0';
	}
	return node;
}

Tree *build(char *string)
{
	int positionNumber = 0;
	Tree *tree = createTree();
	while (string[positionNumber] == ' ' || string[positionNumber] == '(')
	{
		positionNumber++;
	}
	tree->root = new Node;
	tree->root->operation = string[positionNumber];
	tree->root->leftChild = newNode(string, positionNumber);
	tree->root->rightChild = newNode(string, positionNumber);
	return tree;
}



void deleteChildren(Node *node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteChildren(node->leftChild);
	deleteChildren(node->rightChild);
	delete node;
}

void deleteTree(Tree *tree)
{
	deleteChildren(tree->root);
	delete tree;
}