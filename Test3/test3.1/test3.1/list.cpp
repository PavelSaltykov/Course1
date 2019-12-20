#include <stdio.h>
#include "list.h"

struct Node
{
	int value = 0;
	int counter = 0;
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

void addValueToSortedList(List *list, int value)
{
	Node *current = list->head;
	Node *previous = nullptr;
	while (current != nullptr && value > current->value)
	{
		previous = current;
		current = current->next;
	}
	if (current == nullptr || current->value != value)
	{
		Node *newNode = new Node {value, 1, current};
		previous == nullptr ? list->head = newNode : previous->next = newNode;
		return;
	}
	current->counter++;
}

void printList(List *list)
{
	Node *current = list->head;
	while (current != nullptr)
	{
		printf("%d(%d) ", current->value, current->counter);
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