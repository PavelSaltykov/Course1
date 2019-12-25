#pragma once

// Очередь с приоритетами
struct PriorityQueue;

// Создание очереди с приоритетами;
// функция возвращает указатель на очередь.
PriorityQueue *createQueue();

// Добавление значения в очередь с приоритетами;
// функция принимает указатель на очередь, значение и численный приоритет.
void enqueue(PriorityQueue *queue, int vertex1, int vertex2, int edgeLength);

// Функция возвращает длину наименьшего ребра и удаляет его из очереди (если очередь пуста, возвращает -1);
// принимает указатель на очередь, смежные вершины.
int dequeue(PriorityQueue *queue, int &vertex1, int &vertex2);

// Удаление очереди;
// функция принимает указатель на очередь.
void deleteQueue(PriorityQueue *queue);