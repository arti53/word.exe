#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct node {
    int vertex;
    int weight;
    struct node* next;
};

struct node* A[MAX_VERTICES];
int parent[MAX_VERTICES];

int findpar(int i) {
    if (parent[i] == i) {
        return i;
    }
    return findpar(parent[i]);
}

void uni(int a, int b) {
    int x = findpar(a);
    int y = findpar(b);
    parent[x] = y;
}

void kruskal(struct node* A[], int v) {
    int n = 0, a, b, min;

    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    while (n < v - 1) {
        min = 999;
        for (int i = 0; i < v; i++) {
            struct node* temp = A[i];
            while (temp != NULL) {
                if (temp->weight < min && findpar(i) != findpar(temp->vertex)) {
                    a = i;
                    b = temp->vertex;
                    min = temp->weight;
                }
                temp = temp->next;
            }
        }
        uni(a, b);
        printf("Edge %d-%d : Weight = %d\n", a, b, min);
        n++;
    }
}

void displayAdjacencyList(struct node* A[], int v) {
    printf("Adjacency List:\n");
    for (int i = 0; i < v; i++) {
        struct node* temp = A[i];
        printf("Vertex %d:", i);
        while (temp != NULL) {
            printf(" -> (%d, %d)", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void list() {
    int u, v, w, n, total_edges;
    char ch;
   
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        A[i] = NULL;
    }

    scanf("%d", &total_edges);

    struct node* new;
    for (int i = 0; i < total_edges; i++) {
        
        scanf("%d %d %d", &u, &v, &w);

        new = (struct node*)malloc(sizeof(struct node));
        new->vertex = v;
        new->weight = w;
        new->next = A[u];
        A[u] = new;

        new = (struct node*)malloc(sizeof(struct node));
        new->vertex = u;
        new->weight = w;
        new->next = A[v];
        A[v] = new;
    }

    displayAdjacencyList(A, n);
    kruskal(A, n);
}

int main() {
    list();
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


