#pragma once

// ������
struct List;

// �������� ������;
// ������� ���������� ��������� �� ������.
List *createList();

// ������� ��������� �������� � ����� ������;
// ��������� ��������� �� ������, ��������.
void addValue(List *list, int value);

// ����� ������ �� �����;
// ������� ��������� ��������� �� ������.
void printList(List *list);

// ������� ���������� true, ���� ������ ���������.
bool compareLists(List *list1, List *list2);

// �������� ������;
// ������� ��������� ��������� �� ������.
void deleteList(List *list);