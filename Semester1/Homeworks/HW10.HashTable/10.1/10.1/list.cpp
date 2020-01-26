#include <string.h>
#include <stdio.h>
#include "list.h"

struct Node
{
	char *word = nullptr;
	int counter = 0;
	Node *next = nullptr;
};

struct List
{
	Node *head = nullptr;
	int length = 0;
};

List *createList()
{
	return new List;
}

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

int listLength(List *list)
{
	return list->length;
}

bool addNewValueToList(List *list, char *value, int quantity)
{
	Node *current = list->head;
	Node *previous = nullptr;
	while (current != nullptr && strcmp(current->word, value) != 0)
	{
		previous = current;
		current = current->next;
	}
	if (current == nullptr)
	{
		list->length++;
		char *newValue = new char[strlen(value) + 1];
		Node *newNode = new Node {newValue, quantity, nullptr};
		strcpy(newValue, value);
		previous == nullptr ? list->head = newNode : previous->next = newNode;
		return true;
	}
	current->counter += quantity;
	return false;
}

bool listContainsValue(List *list, char *value)
{
	Node *current = list->head;
	while (current != nullptr)
	{
		if (strcmp(current->word, value) == 0)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

char *returnValueFromHead(List *list)
{
	if (isEmpty(list))
	{
		return nullptr;
	}
	return list->head->word;
}

int quantityOfValuesFromHead(List *list)
{
	return list->head->counter;
}

void deleteValueFromHead(List *list)
{
	if (isEmpty(list))
	{
		return;
	}
	list->length--;
	Node *headNode = list->head;
	list->head = list->head->next;
	delete[] headNode->word;
	delete headNode;
}

void printList(List *list)
{
	Node *current = list->head;
	while (current != nullptr)
	{
		printf("%s(%d) ", current->word, current->counter);
		current = current->next;
	}
}

void deleteList(List *list)
{
	while (!isEmpty(list))
	{
		deleteValueFromHead(list);
	}
	delete list;
}