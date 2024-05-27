#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int parent[MAX_VERTICES];
int G[MAX_VERTICES][MAX_VERTICES];

int findparmatrix(int i) {
    while (i != parent[i]) {
        i = parent[i];
    }
    return i;
}

void unimatrix(int a, int b) {
    int i, j;
    i = findparmatrix(a);
    j = findparmatrix(b);

    parent[j] = i;
}

void kruskalmatrix(int G[][MAX_VERTICES], int v) {
    int min1, n1 = 1, a, b;

    for (int i = 0; i < v; i++)
        parent[i] = i;

    while (n1 < v) {
        min1 = 999;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (G[i][j] < min1 && findparmatrix(i) != findparmatrix(j)) {
                    a = i;
                    b = j;
                    min1 = G[i][j];
                }
            }
        }
        unimatrix(a, b);
        printf("Edge %d-%d : Weight = %d\n", a, b, min1);
        n1++;
    }
}

void displayGraph(int G[][MAX_VERTICES], int v) {
    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (G[i][j] == 999) {
                printf("  INF "); // Print INF for no connection
            } else {
                printf("%5d ", G[i][j]);
            }
        }
        printf("\n");
    }
}

int matrix() {
    int v, e, a, b, w, start_vertex;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &v);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            G[i][j] = 999; // Initialize with high value (representing infinity)
        }
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("\nEnter edge: ");
        scanf("%d %d", &a, &b);
        printf("Enter weight from edge %d to %d: ", a, b);
        scanf("%d", &w);
        G[a][b] = G[b][a] = w;
    }

    printf("\nEnter the start vertex (though it won't affect Kruskal's algorithm): ");
    scanf("%d", &start_vertex);

    displayGraph(G, v); // Display the graph as an adjacency matrix

    return v;
}

int main() {
    int m, f;
                f = matrix();
                kruskalmatrix(G, f);
           

    return 0;
}

// 10 
// 18
// 0 1 2
// 1 3 6
// 1 7 2
// 1 5 4
// 1 2 2 
// 2 5 3 
// 2 8 7
// 2 4 1 
// 2 3 4
// 3 4 3
// 4 9 2 
// 5 6 4
// 5 8 7
// 6 8 3 
// 6 9 1
// 7 6 10
// 8 9 5
// 0
