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
	list->length++;
}

List *merge(List *list1, List *list2)
{
	List *newList = createList();
	newList->length = list1->length + list2->length;

	if (strcmp(list1->head->name, list2->head->name) < 0)
	{
		newList->head = list1->head;
		list1->head = list1->head->next;
	}
	else
	{
		newList->head = list2->head;
		list2->head = list2->head->next;
	}

	Entry *current = newList->head;
	for (int i = 1; i < newList->length; ++i)
	{
		if (!isEmpty(list1) && (isEmpty(list2) || strcmp(list1->head->name, list2->head->name) < 0))
		{
			current->next = list1->head;
			list1->head = list1->head->next;
		}
		else
		{
			current->next = list2->head;
			list2->head = list2->head->next;
		}
		current = current->next;
	}
	delete list1;
	delete list2;
	return newList;
}

List *mergeSort(List *list)
{
	if (list->length == 1)
	{
		return list;
	}

	Entry *current = list->head;
	for (int i = 1; i < list->length / 2; ++i)
	{
		current = current->next;
	}
	List *list1 = createList();
	list1->head = list->head;
	list1->length = list->length / 2;

	List *list2 = createList();
	list2->head = current->next;
	current->next = nullptr;
	list2->length = list->length - list1->length;
	
	delete list;
	list1 = mergeSort(list1);
	list2 = mergeSort(list2);
	return merge(list1, list2);
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