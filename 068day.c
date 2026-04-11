#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        indegree[v]++;
    }


    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX], index = 0;

    while (!isEmpty()) {
        int u = dequeue();
        topo[index++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    if (index != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}