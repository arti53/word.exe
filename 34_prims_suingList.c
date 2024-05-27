#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex, weight;
    struct node *next;
};

void createAdjList(struct node *A[], int n) {
    int edges;
    for (int i = 0; i < n; i++) {
        A[i] = NULL;
    }
    printf("Enter no. of edges : ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int startvertex, endvertex, weight;
        printf("Enter startvertex, endvertex, weight : ");
        scanf("%d %d %d", &startvertex, &endvertex, &weight);

        // Create new node for endvertex in adjacency list of startvertex
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->vertex = endvertex;
        newnode->weight = weight;
        newnode->next = A[startvertex];
        A[startvertex] = newnode;

        // Create new node for startvertex in adjacency list of endvertex
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->vertex = startvertex;
        newnode->weight = weight;
        newnode->next = A[endvertex];
        A[endvertex] = newnode;
    }
}

void displayAdjList(struct node *A[], int n) {
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        struct node *current = A[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->vertex, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

void display(int dist[], int par[], int n) {
    printf("Edge Weight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d %d \n", par[i], i, dist[i]);
    }
}

int minimum(int dist[], int visited[], int n) {
    int min = 99, index;
    for (int i = 0; i < n; i++) {
        if (dist[i] < min && visited[i] == 0) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void adjListPrims(struct node *A[], int n) {
    int visited[n], dist[n], par[n], v, u;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = 99;
        par[i] = -1;
    }
    printf("Enter start vertex : ");
    scanf("%d", &v);
    par[v] = v;
    dist[v] = 0;
    for (int i = 0; i < n - 1; i++) {
        u = minimum(dist, visited, n);
        visited[u] = 1;
        struct node *p = A[u];
        while (p != NULL) {
            if (visited[p->vertex] == 0 && p->weight < dist[p->vertex]) {
                par[p->vertex] = u;
                dist[p->vertex] = p->weight;
            }
            p = p->next;
        }
    }
    display(dist, par, n);
}

int main() {
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    struct node *A[n];
    createAdjList(A, n);
    displayAdjList(A, n);
    adjListPrims(A, n);
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
