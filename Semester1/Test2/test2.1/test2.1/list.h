#pragma once

struct List;

List *createList();

int listLength(List *list);

void addValue(List *list, int value);

int returnValue(List *list, int positionNumber);

void printList(List *list);

void deleteList(List *list);