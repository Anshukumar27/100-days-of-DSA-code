#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

struct Node {
    int vertex;
    int dist;
};

struct Node heap[MAX];
int size = 0;

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int v, int dist) {
    heap[size].vertex = v;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

struct Node pop() {
    struct Node root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return size == 0;
}


void dijkstra(int n, int adj[MAX][MAX], int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct Node curr = pop();
        int u = curr.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] > 0 && !visited[v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(v, dist[v]);
                }
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[MAX][MAX] = {0};

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; 
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(n, adj, src);

    return 0;
}