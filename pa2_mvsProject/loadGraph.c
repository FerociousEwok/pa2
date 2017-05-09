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
	int n, m;
	n = sizeof(adjList); //the 0 index is not a vector, so subtract one for number of vectors.
	n -= 1;
	//adding up number of edges
	
	for (int i = n; i > 0; i--)
	{
		m += intSize(adjList[i]);
	}





	//Time for printing
	fprintf(stdout, "n = %d\nm = %d\n", n, m);
	for (int w = 1; w <= n; w++) //for each node
	{
		printf("%d		[", (w));
		for (int u = 0; u < intSize(adjList[w]); u++) //for each edge from that node
		{
			printf("%d", intData(adjList[w], u));

			if (u<intSize(adjList[w]) - 1) //if its not the last element
			{
				printf(", ");
			}
		}
		printf("]\n");
	}
}
printAdjMatrix(int** adjMatrix)
{

}