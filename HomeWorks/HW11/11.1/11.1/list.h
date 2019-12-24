#pragma once

// 
struct List;

// 
List *createList();

//
bool isEmpty(List *list);

//
void addValue(List *list, int value);

// 
void printList(List *list);

//
void deleteList(List *list);