#pragma once

// Список
struct List;

// Создание списка;
// функция возвращает указатель на список.
List *createList();

// Функция добавляет значение в конец списка;
// принимает указатель на список, значение.
void addValue(List *list, int value);

// Вывод списка на экран;
// функция принимает указатель на список.
void printList(List *list);

// Функция возвращает true, если списки совпадают.
bool compareLists(List *list1, List *list2);

// Удаление списка;
// функция принимает указатель на список.
void deleteList(List *list);