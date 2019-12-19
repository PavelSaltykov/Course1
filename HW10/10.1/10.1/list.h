#pragma once


struct List;


List *createList();


bool isEmpty(List *list);


int listLength(List *list);


bool addNewValueToList(List *list, char *value, int quantity);


bool listContainsValue(List *list, char *value);


char *returnValueFromHead(List *list);


int quantityOfValuesFromHead(List *list);


void deleteValueFromHead(List *list);


void printList(List *list);


void deleteList(List *list);