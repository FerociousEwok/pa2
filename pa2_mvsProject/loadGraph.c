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
	//todo next
}

IntVec* loadGraph(FILE *inputFile) //process inputfile and store in adjList array
{
	fscanf(inputFile, "%s", tempString); //load first line
	n = (int)tempString[0] - (int)'0'; //convert string to int.
	tempString[0] = '\0';  //clear tempstring first char


	adjList = calloc(n + 1, sizeof(IntVec));  //creates array of vector nodes
	for (int i = 0; i <= n; i++)  //fill array with vector nodes
	{
		adjList[i] = intMakeEmptyVec();
	}
	//below is some input file cleanup
	for (int i = 0; i < 1; i++)
		fgets(tempString, 20, inputFile);

	//now time to read each line of input and load array as we go.
	while ((fgets(tempString, 20, inputFile) != NULL)) //for each line of the file.
	{
		if (tempString[0] == '\n') //if fgets needed to clear newline character
			fgets(tempString, 20, inputFile);

		sscanf(tempString, "%s %s %s", tempToken, tempDataValue, tempWeight);
		//get first token
		tempInt = (int)tempToken[0] - (int)'0';
		//get second token
		dataValue = (int)tempDataValue[0] - (int)'0';
		//if there is a weight
		if (!((float)tempWeight[0] == 0.00))
			weight = (float)tempWeight[0] - (float)'0';

		intVecPush(adjList[tempInt], dataValue); //add element in proper location.
		m += 1;

		return NULL;
	}
}

int getNodeCount(FILE *inputFile)
{
	return 0;
}