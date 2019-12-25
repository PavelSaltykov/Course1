#include "priorityQueue.h"

struct QueueElement
{
	int vertex1 = -1;
	int edgeLength = -1;
	int vertex2 = 0;
	QueueElement *next = nullptr;
};

struct PriorityQueue
{
	QueueElement *front = nullptr;
};

PriorityQueue *createQueue()
{
	return new PriorityQueue;
}

bool isEmpty(PriorityQueue *queue)
{
	return queue->front == nullptr;
}

void enqueue(PriorityQueue *queue, int vertex1, int vertex2, int edgeLength)
{
	QueueElement *current = queue->front;
	QueueElement *previous = nullptr;
	while (current != nullptr && current->edgeLength >= edgeLength)
	{
		previous = current;
		current = current->next;
	}
	QueueElement *newQueueElement = new QueueElement {vertex1, edgeLength, vertex2, current};
	previous == nullptr ? queue->front = newQueueElement : previous->next = newQueueElement;
}

int dequeue(PriorityQueue *queue, int &vertex1, int &vertex2)
{
	if (isEmpty(queue))
	{
		return -1;
	}
	QueueElement *first = queue->front;
	queue->front = queue->front->next;
	int firstEdgeLength = first->edgeLength;
	vertex1 = queue->front->vertex1;
	vertex2 = queue->front->vertex2;
	delete first;
	return firstEdgeLength;
}

void deleteQueue(PriorityQueue *queue)
{
	while (!isEmpty(queue))
	{
		QueueElement *temp = queue->front->next;
		delete queue->front;
		queue->front = temp;
	}
	delete queue;
}