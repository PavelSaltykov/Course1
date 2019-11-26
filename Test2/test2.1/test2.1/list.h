#pragma once

struct List;

List *createList();

void addValue(List *list, int value);

List *newList(List *list);

int deleteValue(List *list);

void deleteList(List *list);