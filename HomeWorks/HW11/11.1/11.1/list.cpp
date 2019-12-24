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
	if (!isEmpty(list))
	{
		list->tail->next = new Node {value, nullptr};
		list->tail = list->tail->next;
		return;
	}
	list->head = new Node {value, nullptr};
	list->tail = list->head;
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

bool compareLists(List *list1, List *list2)
{
	Node *current1 = list1->head;
	Node *current2 = list2->head;
	while (current1 != nullptr)
	{
		if (current1->value != current2->value)
		{
			return false;
		}
		current1 = current1->next;
		current2 = current2->next;
	}
	return current2 == nullptr;
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