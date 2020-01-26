#pragma once

struct List;

List *createList();

int listLength(List *list);

void addValue(List *list, int value);

int returnValue(List *list, int positionNumber);

bool compareLists(List *list1, List *list2);

void deleteList(List *list);