#pragma once

struct List;

List *createList();

void addValueToSortedList(List *list, int value);

void printList(List *list);

void deleteList(List *list);