#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Stack {
    int items[MAX_VERTICES];
    int top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top == MAX_VERTICES - 1)
        printf("Stack overflow\n");
    else
        stack->items[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

struct Graph {
    int vertices;
    int** adjMatrix;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void DFS(struct Graph* graph, int startVertex, int* visited) {
    struct Stack* stack = createStack();

    push(stack, startVertex);

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(stack, i);
            }
        }
    }

    free(stack);
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    int* visited = (int*)calloc(graph->vertices, sizeof(int));

    printf("Depth-First Traversal starting from vertex 0: ");
    DFS(graph, 0, visited);
    printf("\n");

    free(visited);
    freeGraph(graph);
    return 0;
}

