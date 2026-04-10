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

    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}


bool dfs(struct Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];

    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(graph, neighbor, visited, v))
                return true;
        }
        else if (neighbor != parent) {
            return true; 
        }

        temp = temp->next;
    }

    return false;
}

bool isCycle(struct Graph* graph) {
    bool visited[MAX] = {false};

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, -1))
                return true;
        }
    }

    return false;
}


int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);

    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    if (isCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}