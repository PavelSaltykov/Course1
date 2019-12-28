#include "priorityQueue.h"
#include "Prim.h"

void addEdgesToQueue(int **graph, int currentVertex, int size, bool *used, PriorityQueue *queueOfEdges)
{
	for (int i = 0; i < size; ++i)
	{
		if (graph[currentVertex][i] != 0 && !used[i])
		{
			enqueue(queueOfEdges, currentVertex, i, graph[currentVertex][i]);
		}
	}
}

int **createMinimalSpanningTree(int **graph, int size)
{
	bool *used = new bool[size] {};
	PriorityQueue *queueOfEdges = createQueue();
	int **spanningTree = new int *[size];
	for (int i = 0; i < size; ++i)
	{
		spanningTree[i] = new int[size] {};
	}

	const int root = 0;
	used[root] = true;
	addEdgesToQueue(graph, root, size, used, queueOfEdges);

	while (!isEmpty(queueOfEdges))
	{
		int vertex1 = 0;
		int vertex2 = 0;
		const int lengthEdge = dequeue(queueOfEdges, vertex1, vertex2);
		if (!used[vertex1] || !used[vertex2])
		{
			const int currentVertex = (used[vertex1]) ? vertex2 : vertex1;
			used[currentVertex] = true;
			spanningTree[vertex1][vertex2] = lengthEdge;
			spanningTree[vertex2][vertex1] = lengthEdge;
			addEdgesToQueue(graph, currentVertex, size, used, queueOfEdges);
		}
	}
	delete[] used;
	deleteQueue(queueOfEdges);
	return spanningTree;
}