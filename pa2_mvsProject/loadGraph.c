#include "intVec.h"
#include "loadGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
loadGraph.c
Ben Donn
bdonn
*/

int** makeAdjMatrix(IntVec *adjList)
{
	return NULL;
}

IntVec* transposeGraph(IntVec* adjList, int n)
{
	return NULL;
}

printAdjVerts(IntVec *adjList)
{
	int n, m = 0;
	n = sizeof(adjList); //the 0 index is not a vector, so subtract one for number of vectors.
	n -= 1;
	//adding up number of edges
	for (int i = n; i > 0; i--)
		m += intSize(adjList[i]);
	fprintf(stdout, "n = %d\nm = %d\n", n, m);
	for (int w = 1; w <= n; w++) //for each node
	{
		fprintf(stdout, "%d		[", (w));
		for (int u = 0; u < intSize(adjList[w]); u++) //for each edge from that node
		{
			fprintf(stdout, "%d", intData(adjList[w], u));

			if (u<intSize(adjList[w]) - 1) //if its not the last element
				fprintf(stdout, ", ");
		}
		fprintf(stdout, "]\n");
	}
}

printAdjMatrix(int** adjMatrix)
{

}