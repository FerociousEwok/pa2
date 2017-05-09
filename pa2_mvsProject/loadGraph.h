/*
loadGraph.h
Ben Donn
bdonn
*/

int** makeAdjMatrix(IntVec *adjList);
IntVec* transposeGraph(IntVec* origGraph, int n);
printAdjVerts(IntVec *adjList);
printAdjMatrix(int** adjMatrix);