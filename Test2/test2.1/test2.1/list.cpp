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

int listLength(List *list)
{
	Node *current = list->head;
	int listLength = 0;
	while (current != nullptr)
	{
		listLength++;
		current = current->next;
	}
	return listLength;
}

void addValue(List *list, int value)
{
	Node *current = list->head;
	Node *previous = nullptr;
	while (current != nullptr)
	{
		previous = current;
		current = current->next;
	}
	Node *newNode = new Node {value, current};
	previous == nullptr ? list->head = newNode : previous->next = newNode;
}

List *newList(List *list)
{
	if (isEmpty(list))
	{
		return nullptr;
	}
	List *newList = createList();
	int maxLength = 0;
	List *tempList = createList();
	addValue(tempList, list->head->value);
	Node *current = list->head->next;
	Node *previous = list->head;

	while (true)
	{
		while (current != nullptr && current->value > previous->value)
		{
			addValue(tempList, current->value);
			previous = current;
			current = current->next;
		}

		if (listLength(tempList) > maxLength)
		{
			deleteList(newList);
			List *newList = createList();
			newList->head = tempList->head;
			maxLength = listLength(tempList);
			tempList->head = nullptr;
		}
		else
		{
			deleteList(tempList);
			List *tempList = createList();
		}
		if (current == nullptr)
		{
			break;
		}
		addValue(tempList, current->value);
		previous = current;
		current = current->next;
	}
	deleteList(tempList);
	return newList;
}

int deleteValue(List *list)
{
	int headValue = list->head->value;
	Node *temp = list->head->next;
	delete list->head;
	list->head = temp;
	return headValue;
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