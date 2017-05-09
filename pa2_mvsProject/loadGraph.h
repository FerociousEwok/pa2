/*
loadGraph.h
Ben Donn
bdonn
*/


/**/
int** makeAdjMatrix(IntVec *adjList, int nodeCount);

/**/
IntVec* transposeGraph(IntVec* origGraph, int n);

/**/
printAdjVerts(IntVec *adjList);

/**/
printAdjMatrix(int** adjMatrix, int nodeCount);

/**/
IntVec* loadGraph(FILE *inputFile, int nodeCount, char* flag);

/**/
int getNodeCount(FILE *inputFile);

/**/
//IntVec* loadGraphUndirected(FILE *inputFile, int nodeCount);

/**/
int getEdgeCount(IntVec *adjList);