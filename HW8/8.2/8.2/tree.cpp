#include <stdio.h>
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

bool isEmpty(Tree *tree)
{
	return tree->root == nullptr;
}

bool isLeaf(Node *node)
{
	return node->leftChild == nullptr && node->rightChild == nullptr;
}

bool isOperation(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int number(char *string, int &numberPosition)
{
	int number = 0;
	while (string[numberPosition] >= '0' && string[numberPosition] <= '9')
	{
		number = number * 10 + (string[numberPosition] - '0');
		numberPosition++;
	}
	return number;
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
		node->operand = number(string, positionNumber);
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

void printNode(Node *node)
{
	if (isLeaf(node))
	{
		printf("%d ", node->operand);
		return;
	}
	printf("%c ", node->operation);
	printNode(node->leftChild);
	printNode(node->rightChild);

}

void printTree(Tree *tree)
{
	if (isEmpty(tree))
	{
		return;
	}
	printNode(tree->root);
}

int calculateSubtree(Node *node)
{
	if (isLeaf(node))
	{
		return node->operand;
	}
	const int operand1 = calculateSubtree(node->leftChild);
	const int operand2 = calculateSubtree(node->rightChild);
	const char operation = node->operation;
	if (operation == '+')
	{
		return operand1 + operand2;
	}
	if (operation == '-')
	{
		return operand1 - operand2;
	}
	if (operation == '*')
	{
		return operand1 * operand2;
	}
	return operand1 / operand2;
}

int calculate(Tree *tree)
{
	return calculateSubtree(tree->root);
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