/*
graph02.c
Ben Donn
bdonn
pa2

TODO: encapsulate global variables locally.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intVec.h"
#include "loadGraph.h"

int main(int argc, char **argv)
{
	//variables
	FILE *inputFile = NULL;
	char *tempInputString = "";
	char *readMode = "r+";
	IntVec *adjList;
	char *flag = "default";
	int nodeCount = 0;

	if (argc == 1) //no command line argument
	{
		fprintf(stderr, "Error: no command line arguments.\nPress any key to close: ");
		getc(stdin);
		exit(0);
	}
	else if (argc == 2) //if there is not a -U flag
		tempInputString = argv[1];
	else if (argc == 3) //flag given
	{
		flag = argv[1];
		tempInputString = argv[2];
	}
	inputFile = fopen(tempInputString, readMode); //create file
	if (inputFile == 0)
	{
		fprintf(stderr, "fopen() error\nPress any key to close: ");
		getc(stdin);
		exit(1);
	}

	nodeCount = getNodeCount(inputFile);
	if (flag != "-U" || flag != "default")//if bad command line input
	{
		fprintf(stderr, "Error reading command line input\nPress any key to close: ");
		getc(stdin);
		exit(1);
	}
	adjList = loadGraph(inputFile, nodeCount, flag);

	printAdjVerts(adjList, nodeCount);
	if (nodeCount <= 20)
		printAdjMatrix(makeAdjMatrix(adjList, nodeCount), nodeCount);
	for (int i = 0; i < 2; i++) //run twice; second transpose
	{
		adjList = transposeGraph(adjList, nodeCount); //adjList now transposedAdjList.
		printAdjVerts(adjList, nodeCount);
		if (nodeCount <= 20)
			printAdjMatrix(makeAdjMatrix(adjList, nodeCount), nodeCount);
	}

	//free allocated memory--------------------------------------------------------
	for (int i = 0; i <= sizeof(adjList); i++)
		free(adjList[i]);
	free(adjList);
	fprintf(stdout, "Program completed with no errors, exiting...");
	//delay(5000);//wait a few seconds then close
	getc(stdin);
	return EXIT_SUCCESS;
}
	/* 

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

	}
	--------------------------------------------------------------------------------*/
	


	/*printing no longer supported here
	
	//Time for printing
	fprintf(stdout, "n = %d\nm = %d\n", n, m);
	for (int w = 1; w <= n; w++) //for each node
	{
		printf("%d		[", (w));
		for (int u = 0; u < intSize(adjList[w]); u++) //for each edge from that node
		{
			printf("%d",intData(adjList[w], u)); 
			
			if (u<intSize(adjList[w])-1) //if its not the last element
			{
				printf(", ");
			}
		}
		printf("]\n");
	}
	fclose(inputFile);
	for(int i = 0; i<=n; i++)
		free(adjList[i]);
	free(adjList);
	getc(stdin);
}

*/