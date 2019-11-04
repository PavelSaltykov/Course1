#include <stdio.h>
#include "circular_list.h"

struct Node
{
	int value;
	Node *next;
};

struct List
{
	Node *head = nullptr;
	Node *tail = nullptr;
};

List *createList()
{
	return new List;
}

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

bool onlyHeadInList(List *list)
{
	return list->head == list->tail;
}

int headValue(List *list)
{
	return list->head->value;
}

void addValue(List *list, int value)
{
	if (isEmpty(list))
	{
		list->head = new Node {value, nullptr};
		list->head->next = list->head;
		list->tail = list->head;
	}
	else
	{
		list->tail->next = new Node {value, list->head};
		list->tail = list->tail->next;
	}
}

void deleteValue(List *list, int positionNumber, bool shouldMoveHead)
{
	Node *current = list->head;
	Node *previous = list->tail;
	for (int i = 1; i < positionNumber; ++i)
	{
		previous = current;
		current = current->next;
	}

	if (current == list->head || current == list->tail || shouldMoveHead)
	{
		list->head = current->next;
		list->tail = previous;
	}
	previous->next = current->next;
	delete current;
}

void deleteList(List *list)
{
	while (list->head != list->tail)
	{
		deleteValue(list, 1);
	}
	delete list->head;
	delete list;
}