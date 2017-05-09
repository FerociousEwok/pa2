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

printAdjVerts(IntVec *adjList) //Done
{
	int n, m = 0;
	m = getEdgeCount(adjList);
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
	//todo next
}


/*
The below function callocs an array of vectors and fills it based on inputFile
	then returns a pointer to the array.
*/
IntVec* loadGraph(FILE *inputFile) //Done
{
	//local variables
	int nodeCount = 0, edgeCount = 0, tempInt = 0, dataValue = 0;
	float weight;
	IntVec *tempList;
	char *lineOfFile, *tempToken, *tempDataValue, *tempWeight;

	nodeCount = getNodeCount(inputFile);
	tempList = calloc(nodeCount + 1, sizeof(IntVec));
	for (int i = 0; i <= nodeCount; i++)
		tempList[i] = intMakeEmptyVec();
	//below is some input file cleanup
	for (int i = 0; i < 1; i++)
		fgets(lineOfFile, 20, inputFile);
	while ((fgets(lineOfFile, 20, inputFile) != NULL)) //for each line of the file.
	{
		if (lineOfFile[0] == '\n') //if fgets needed to clear newline character
			fgets(lineOfFile, 20, inputFile);
		sscanf(lineOfFile, "%s %s %s", tempToken, tempDataValue, tempWeight);
		//get first token
		tempInt = (int)tempToken[0] - (int)'0';
		//get second token
		dataValue = (int)tempDataValue[0] - (int)'0';
		//if there is a weight
		if (!((float)tempWeight[0] == 0.00))
			weight = (float)tempWeight[0] - (float)'0';
		intVecPush(tempList[tempInt], dataValue);
		edgeCount += 1;
	}
	return tempList;
}
IntVec* loadGraphUndirected(FILE *inputFile)
{

}

int getNodeCount(FILE *inputFile) //Done
{
	char *tempString;
	fscanf(inputFile, "%s", tempString); //load first line
	return ((int)tempString[0] - (int)'0'); //convert string to int.
}

int getEdgeCount(IntVec *adjList)
{
	int n, m = 0;
	n = sizeof(adjList); //the 0 index is not a vector, so subtract one for number of vectors.
	n -= 1;
	//adding up number of edges
	for (int i = n; i > 0; i--)
		m += intSize(adjList[i]);
	return m;
}