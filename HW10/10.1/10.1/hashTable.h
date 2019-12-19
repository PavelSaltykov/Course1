#pragma once


struct HashTable;


HashTable *createHashTable();


void addValueToTable(HashTable *table, char *value);


bool tableContainsValue(HashTable *table, char *value);


void printTable(HashTable *table);


float loadFactor(HashTable *table);


int maximumListLength(HashTable *table);


float averageListLength(HashTable *table);


void deleteTable(HashTable *table);