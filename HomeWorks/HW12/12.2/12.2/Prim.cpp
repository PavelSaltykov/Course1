#include "priorityQueue.h"
#include "Prim.h"

void addVertex(int **graph, int size, bool *used, int **spanningTree)
{

}

int **createMinimalSpanningTree(int **graph, int size)
{
	bool *used = new bool[size];
	PriorityQueue *queueOfEdges = createQueue();
	int **spanningTree = new int *[size];
	for (int i = 0; i < size; ++i)
	{
		spanningTree[i] = new int[size] {};
	}

	int root = 0;
	for (int i = 0; i < 0; ++i)
	{
		if (graph[root][i] != 0 && !used[i])
		{
			enqueue()
		}
	}
}