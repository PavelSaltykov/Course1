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
	Node *tail = nullptr;
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

void addValue(List *list, char *value)
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



void deleteList(List *list)
{
	while (!isEmpty(list))
	{
		Node *temp = list->head->next;
		delete[] list->head->word;
		delete list->head;
		list->head = temp;
	}
	delete list;
}