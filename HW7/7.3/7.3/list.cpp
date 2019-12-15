#include <stdio.h>
#include <string.h>
#include "list.h"

struct Entry
{
	char *name = nullptr;
	char *phone = nullptr;
	Entry *next = nullptr;
};

struct List
{
	int length = 0;
	Entry *head = nullptr;
	Entry *tail = nullptr;
};

List *createList()
{
	return new List;
}

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

void addEntry(List *list, char *name, char *phone)
{
	list->length++;
	char *newName = new char[strlen(name) + 1];
	char *newPhone = new char[strlen(phone) + 1];
	strcpy(newName, name);
	strcpy(newPhone, phone);
	Entry *newEntry = new Entry {newName, newPhone, nullptr};

	if (isEmpty(list))
	{
		list->head = newEntry;
		list->tail = list->head;
		return;
	}
	list->tail->next = newEntry;
	list->tail = list->tail->next;
}

char *returnNameFromHead(List *list)
{
	return list->head->name;
}

char *returnPhoneFromHead(List *list)
{
	return list->head->phone;
}

int listLength(List *list)
{
	return list->length;
}

void deleteHead(List *list)
{
	if (isEmpty(list))
	{
		return;
	}
	list->length--;
	Entry *temp = list->head->next;
	delete list->head->name;
	delete list->head->phone;
	delete list->head;
	list->head = temp;
}

void printList(List *list)
{
	if (isEmpty(list))
	{
		return;
	}
	Entry *current = list->head;
	while (current != nullptr)
	{
		printf("%s - %s\n", current->name, current->phone);
		current = current->next;
	}
}

void deleteList(List *list)
{
	while (!isEmpty(list))
	{
		Entry *temp = list->head->next;
		delete list->head->name;
		delete list->head->phone;
		delete list->head;
		list->head = temp;
	}
	delete list;
}