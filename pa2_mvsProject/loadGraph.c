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

int** makeAdjMatrix(IntVec *adjList, int nodeCount)
{
	int** adjMatrix;
	//first initilize all values to 0.
	for (int i = 1; i <= nodeCount; i++)//for each node. i.e. each index of array.
	{
		for (int j = 1; j <= nodeCount; j++) //for each node that adjList[i] could have an edge to.
		{
			for (int z = 0; z < intSize(adjList[i]); z++) //for each element in adjList[i]
			{
				if (intData(adjList[i], z) == j)//if adjList[i] has edge to adjList[j]
					adjMatrix[i][j] = 1;
				else
					adjMatrix[i][j] = 0;
			}
		}
	}
	return adjMatrix;
}

IntVec* transposeGraph(IntVec* adjList, int n)
{
	IntVec* transposedList;
	for (int i = 0; i <= n; i++) //initialize a new array of vectors.
	{
		transposedList[i] = intMakeEmptyVec();
	}
	for (int i = 1; i <= n; i++)//traverse through adjList data
	{
		for (int j = 0; j < intSize(adjList[i]); j++)//for each element in adjList[i]->data
		{
			intVecPush(transposedList[intData(adjList[i], j)], i);//transpose from adjList to new vector array.
		}
	}
	return transposedList;
}

void printAdjVerts(IntVec *adjList, int nodeCount) //Done
{
	int n, m = 0;
	m = getEdgeCount(adjList);
	//n = getNodeCount(adjList);

	fprintf(stdout, "nodeCount = %d\nedgeCount = %d\n", n, m);
	for (int w = 1; w <= n; w++) //for each node
	{
		fprintf(stdout, "%d	  [", (w));
		for (int u = 0; u < intSize(adjList[w]); u++) //for each edge from that node
		{
			fprintf(stdout, "%d", intData(adjList[w], u));
			if (u<intSize(adjList[w]) - 1) //if its not the last element
				fprintf(stdout, ", ");
		}
		fprintf(stdout, "]\n");
	}
}

void printAdjMatrix(int** adjMatrix, int nodeCount)
{
	fprintf(stdout, "     ");//alignment
	for (int i = 1; i <= nodeCount; i++)
	{
		fprintf(stdout, "%d ", i);//horizontal index
	}
	fprintf(stdout, "\n   ------------------");
	for (int i = 1; i <= nodeCount; i++) //for each adjList[i]
	{
		fprintf(stdout, "\n%d :  ", i);
		for (int j = 1; j <= nodeCount; j++) //for each potential edge
		{
			fprintf(stdout, "%d  ", adjMatrix[i][j]);
		}
	}
}


/*
The below function callocs an array of vectors and fills it based on inputFile
	then returns a pointer to the array.
*/
IntVec* loadGraph(FILE *inputFile, int nodeCount, char* flag) //Done
{
	//local variables
	int tempInt = 0, dataValue = 0;
	float weight;
	IntVec *tempList;
	char *lineOfFile, *tempToken, *tempDataValue, *tempWeight;

	//nodeCount = getNodeCount(inputFile);
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
		if (flag == "-U") //if undirected, add this edge also.
			intVecPush(tempList[dataValue], tempInt);
	}
	return tempList;
}
/* 
IntVec* loadGraphUndirected(FILE *inputFile, int nodeCount) //edges go both ways; for each edge, edgeCount+=2.
{
	//local variables
	int nodeCount = 0, tempInt = 0, dataValue = 0;
	float weight;
	IntVec *tempList;
	char *lineOfFile, *tempToken, *tempDataValue, *tempWeight;

	//nodeCount = getNodeCount(inputFile);
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

		intVecPush(tempList[tempInt], dataValue);//edge from tempInt vector to dataValue Vector.
		intVecPush(tempList[dataValue], tempInt);//edge from dataValue vector to tempInt vector.
	}
	return tempList;
}
*/
int getNodeCount(FILE *inputFile) //Only call once or there might be errors.
{
	char *tempString;
	fscanf(inputFile, "%s", tempString); //load first line
	return ((int)tempString[0] - (int)'0'); //convert string to int.
}

int getEdgeCount(IntVec *adjList) //Can call multiple times.
{
	int n, m = 0;
	n = sizeof(adjList);
	n -= 1;
	for (int i = n; i > 0; i--)
		m += intSize(adjList[i]);
	return m;
}