#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int parent[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py)
        return 0;  

    parent[py] = px;
    return 1;
}

int main() {
    int n;

    printf("Enter number of edges: ");
    scanf("%d", &n);

    int edges[n][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

   
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionSet(u, v)) {
            printf("Redundant Edge: [%d, %d]\n", u, v);
            return 0;
        }
    }

    printf("No redundant edge found\n");
    return 0;
}