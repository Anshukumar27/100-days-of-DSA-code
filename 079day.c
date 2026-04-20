#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adj[MAX];
};

struct HeapNode {
    int vertex, dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

void addEdge(struct Graph* g, int u, int v, int w) {
    struct Node* temp = newNode(v, w);
    temp->next = g->adj[u];
    g->adj[u] = temp;

    temp = newNode(u, w);
    temp->next = g->adj[v];
    g->adj[v] = temp;
}

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

struct HeapNode extractMin(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}

void insertHeap(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}


void dijkstra(struct Graph* g, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= g->V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap h;
    h.size = 0;

    insertHeap(&h, src, 0);

    while (h.size > 0) {
        struct HeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        struct Node* temp = g->adj[u];

        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= g->V; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->V = n;

    for (int i = 0; i <= n; i++)
        g->adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(g, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(g, src);

    return 0;
}