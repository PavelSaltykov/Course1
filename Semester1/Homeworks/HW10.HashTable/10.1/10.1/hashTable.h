#pragma once

// Хеш-таблица
struct HashTable;

// Создание хеш-таблицы;
// функция возвращает указатель на таблицу.
HashTable *createHashTable();

// Добавление значения в хеш-таблицу;
// функция возвращает указатель на таблицу, значение.
void addValueToTable(HashTable *table, char *value);

// Функция проверяет, содержится ли значение в хеш-таблице;
// принимает указатель на список, значение;
// возвращает true, если содержится; false - не содержится.
bool tableContainsValue(HashTable *table, char *value);

// Вывод хеш-таблицы на экран;
// функция принимает указатель на таблицу.
void printTable(HashTable *table);

// Функция возвращает коэффициент заполнения хеш-таблицы;
// принимает указатель на таблицу.
float loadFactor(HashTable *table);

// Функция возвращает максимальную длину списка в сегменте таблицы;
// принимает указатель на таблицу.
int maximumListLength(HashTable *table);

// Функция возвращает среднюю длину списка в сегменте таблицы;
// принимает указатель на таблицу.
float averageListLength(HashTable *table);

// Удаление хеш-таблицы;
// функция принимает указатель на таблицу.
void deleteTable(HashTable *table);