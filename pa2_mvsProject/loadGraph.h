/*
loadGraph.h
Ben Donn
bdonn
*/


/**/
int** makeAdjMatrix(IntVec *adjList);

/**/
IntVec* transposeGraph(IntVec* origGraph, int n);

/**/
printAdjVerts(IntVec *adjList);

/**/
printAdjMatrix(int** adjMatrix);

/**/
IntVec* loadGraph(FILE *inputFile, int nodeCount, char* flag);

/**/
int getNodeCount(FILE *inputFile);

/**/
IntVec* loadGraphUndirected(FILE *inputFile, int nodeCount);

/**/
int getEdgeCount(IntVec *adjList);