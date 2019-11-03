#include <stdio.h>
#include "list.h"

struct Node
{
	int value;
	Node *next;
};

struct List
{
	Node *head = nullptr;
};

List *createList()
{
	return new List;
}

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

void addValue(List *list, int value)
{
	if (isEmpty(list))
	{
		list->head = new Node {value, nullptr};
	}
	else
	{
		Node *first = list->head;
		Node *previous = nullptr;
		while (!isEmpty(list) && list->head->value < value)
		{
			previous = list->head;
			list->head = list->head->next;
		}
		if (previous != nullptr)
		{
			previous->next = new Node {value, list->head};
			list->head = first;
		}
		else
		{
			list->head = new Node {value, first};
		}
	}
}

bool deleteValue(List *list, int value)
{
	if (isEmpty(list))
	{
		return false;
	}
	Node *first = list->head;
	Node *previous = nullptr;
	while (!isEmpty(list) && list->head->value != value)
	{
		previous = list->head;
		list->head = list->head->next;
	}
	if (isEmpty(list))
	{
		list->head = first;
		return false;
	}
	if (previous != nullptr)
	{
		Node *temp = list->head->next;
		delete list->head;
		previous->next = temp;
		list->head = first;
	}
	else
	{
		Node *temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	return true;
}

void printList(List *list)
{
	Node *first = list->head;
	while (!isEmpty(list))
	{
		printf("%d ", list->head->value);
		list->head = list->head->next;
	}
	list->head = first;
}

void deleteList(List *list)
{
	while (!isEmpty(list))
	{
		Node *temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	delete list;
}