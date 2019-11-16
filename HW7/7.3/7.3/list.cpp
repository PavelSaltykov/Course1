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
	Entry *head = nullptr;
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
	char *newName = new char[strlen(name) + 1];
	char *newPhone = new char[strlen(phone) + 1];
	list->head = new Entry {newName, newPhone, list->head};
	strcpy(newName, name);
	strcpy(newPhone, phone);
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