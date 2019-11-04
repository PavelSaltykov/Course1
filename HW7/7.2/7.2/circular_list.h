#pragma once

// ������
struct List;

// �������� ������
List *createList();

// ���������� �������� � ����������� ������
void addValue(List *list, int value);

void deleteValue(List *list, int positionNumber, bool shouldMoveHead);

bool onlyHeadInList(List *list);

int headValue(List *list);

void deleteList(List *list);