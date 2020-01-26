#include "priorityQueue.h"

struct QueueElement
{
	int value = 0;
	int priority = 0;
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

void enqueue(PriorityQueue *queue, int value, int priority)
{
	QueueElement *current = queue->front;
	QueueElement *previous = nullptr;
	while (current != nullptr && current->priority >= priority)
	{
		previous = current;
		current = current->next;
	}
	QueueElement *newQueueElement = new QueueElement {value, priority, current};
	previous == nullptr ? queue->front = newQueueElement : previous->next = newQueueElement;
}

int dequeue(PriorityQueue *queue)
{
	if (isEmpty(queue))
	{
		return -1;
	}
	QueueElement *first = queue->front;
	queue->front = queue->front->next;
	int firstValue = first->value;
	delete first;
	return firstValue;
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