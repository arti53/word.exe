#include <stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100 
int G[MAX_VERTICES][MAX_VERTICES];

//Using matrix : 
int mindistmatrix(int a[], int b[], int n) {
    int min = 999, ind = -1;

    for (int i = 0; i < n; i++) {
        if (!b[i] && a[i] < min) {
            min = a[i];
            ind = i;
        }
    }
    return ind;
}

void displaymatrix(int parent[], int G[][MAX_VERTICES], int n) {
    printf("\n\nMinimum spanning tree is : ");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \n", parent[i], i);
    }
}

void primsmatrix(int G[][MAX_VERTICES], int n) {
    int visited[n];
    int dist[n], parent[n], u;  

    for (int i = 0; i < n; i++) {
        visited[i] = 0; 
        parent[i] = -1;
        dist[i] = 999;
    }

    dist[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        u = mindistmatrix(dist, visited, n); 
        visited[u] = 1;

        for (int j = 0; j < n; j++) {
            if (G[u][j] != 999 && G[u][j] < dist[j] && !visited[j]) {
                dist[j] = G[u][j];
                parent[j] = u;
            }
        }
    }
    displaymatrix(parent, G, n); 
}

int matrix(){
    int v, e, a, b, w;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &v);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            G[i][j] = 999;
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

    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%5d ", G[i][j]);
        }
        printf("\n");
    }

    return v;
}

int main() { 
    int m,f;
    
                f = matrix();
                primsmatrix(G,f);
        
    return 0;
}

// 6
// 9
// 0 1 3
// 0 2 8
// 1 5 7
// 1 3 3
// 2 3 9
// 2 4 7
// 3 4 2
// 0 3 6
// 3 5 1
// 0
