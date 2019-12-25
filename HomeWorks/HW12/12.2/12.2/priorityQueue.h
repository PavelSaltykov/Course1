#pragma once

// ������� � ������������
struct PriorityQueue;

// �������� ������� � ������������;
// ������� ���������� ��������� �� �������.
PriorityQueue *createQueue();

// ���������� �������� � ������� � ������������;
// ������� ��������� ��������� �� �������, �������� � ��������� ���������.
void enqueue(PriorityQueue *queue, int vertex1, int vertex2, int edgeLength);

// ������� ���������� ����� ����������� ����� � ������� ��� �� ������� (���� ������� �����, ���������� -1);
// ��������� ��������� �� �������, ������� �������.
int dequeue(PriorityQueue *queue, int &vertex1, int &vertex2);

// �������� �������;
// ������� ��������� ��������� �� �������.
void deleteQueue(PriorityQueue *queue);