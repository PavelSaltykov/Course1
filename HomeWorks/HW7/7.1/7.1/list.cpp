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
	Node *current = list->head;
	Node *previous = nullptr;
	while (current != nullptr && current->value < value)
	{
		previous = current;
		current = current->next;
	}
	Node *newNode = new Node {value, current};
	previous == nullptr ? list->head = newNode : previous->next = newNode;
}

bool deleteValue(List *list, int value)
{
	Node *current = list->head;
	Node *previous = nullptr;
	while (current != nullptr && current->value != value)
	{
		previous = current;
		current = current->next;
	}
	if (current == nullptr)
	{
		return false;
	}
	Node *temp = current->next;
	delete current;
	previous == nullptr ? list->head = temp : previous->next = temp;
	return true;
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

bool checkSortedList(List *list)
{
	if (!isEmpty(list))
	{
		Node *current = list->head->next;
		Node *previous = list->head;
		while (current != nullptr)
		{
			if (current->value < previous->value)
			{
				return false;
			}
			previous = current;
			current = current->next;
		}
	}
	return true;
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