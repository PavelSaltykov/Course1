#pragma once

// Список
struct List;

// Создание списка
List *createList();

// Добавление значения в циклический список
void addValue(List *list, int value);

void deleteValue(List *list, int positionNumber, bool shouldMoveHead);

bool onlyHeadInList(List *list);

int headValue(List *list);

void deleteList(List *list);