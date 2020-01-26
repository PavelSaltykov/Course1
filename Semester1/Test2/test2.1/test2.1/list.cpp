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
	Node *tail = nullptr;
	int length = 0;
};

List *createList()
{
	return new List;
}

int listLength(List *list)
{
	return list->length;
}

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

void addValue(List *list, int value)
{
	list->length++;
	if (!isEmpty(list))
	{
		list->tail->next = new Node {value, nullptr};
		list->tail = list->tail->next;
		return;
	}
	list->head = new Node {value, nullptr};
	list->tail = list->head;
}

int returnValue(List *list, int positionNumber)
{
	Node *current = list->head;
	for (int i = 0; i < positionNumber; ++i)
	{
		current = current->next;
	}
	return current->value;
}

void printList(List *list)
{
	Node *current = list->head;
	while (current != nullptr)
	{
		printf("%d ", current->value);
		current = current->next;
	}
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