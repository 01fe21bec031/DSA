#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    } else {
        printf("Invalid vertices. Cannot add edge.\n");
    }
}

void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(struct Graph* graph) {
    free(graph);
}

int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printGraph(graph);

    freeGraph(graph);
    return 0;
}

