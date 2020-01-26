#include <stdio.h>
#include "priorityQueue.h"

bool tests()
{
	PriorityQueue *queue = createQueue();
	enqueue(queue, 1, 2);
	enqueue(queue, 2, 1);
	enqueue(queue, 3, 4);
	enqueue(queue, 4, 3);
	enqueue(queue, 5, 4);

	bool testsPassed = dequeue(queue) == 3;
	testsPassed = testsPassed && dequeue(queue) == 5;
	testsPassed = testsPassed && dequeue(queue) == 4;
	testsPassed = testsPassed && dequeue(queue) == 1;
	testsPassed = testsPassed && dequeue(queue) == 2;
	testsPassed = testsPassed && dequeue(queue) == -1;

	deleteQueue(queue);
	return testsPassed;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}
	return 0;
}