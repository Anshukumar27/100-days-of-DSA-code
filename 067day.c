#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


struct Node {
    int data;
    struct Node* next;
};


struct Graph {
    int V;
    struct Node* adj[MAX];
};


int stack[MAX];
int top = -1;


void push(int v) {
    stack[++top] = v;
}


struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}


void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

void dfs(struct Graph* graph, int v, bool visited[]) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];

    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }

        temp = temp->next;
    }

    push(v);
}

void topologicalSort(struct Graph* graph) {
    bool visited[MAX] = {false};

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}


int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological Order:\n");
    topologicalSort(graph);

    return 0;
}