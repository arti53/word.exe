#include<stdio.h>
// #include <conio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 100
int stack[N];
int top = - 1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    int x = stack[top];
    top = top - 1;
    return x;
}

bool stackempty(){
    return top == -1;
}

struct vertex_node{
    int vertex_number;
    struct vertex_node* next;
};

struct graph{
    int no_of_vertices;
    struct vertex_node **A;
};

struct graph* createGraph(int V){
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));

    g->no_of_vertices = V;
    g->A = (struct vertex_node**)malloc(V * sizeof(struct vertex_node));

    for(int i = 0;i<V;i++){
        g->A[i] = NULL;
    }

    return g;
}

struct vertex_node* createVertex(int data){
    struct vertex_node* ver = (struct vertex_node*)malloc(sizeof(struct vertex_node));

    ver->vertex_number = data;
    ver->next = NULL;

    return ver;
}

void createAdjList(int v, struct graph* g, int e){

    int a, b;
    struct vertex_node* temp;
    struct vertex_node* newnode;
    for(int i = 0;i<e;i++){

       scanf("%d %d", &a, &b);

       newnode = createVertex(a);
        temp = g->A[b];

        if(temp == NULL){
            g->A[b] = newnode;
        }
        else{
            while(temp->next != NULL){
                temp = temp ->next;
            }
            temp->next = newnode;
        }

        newnode = createVertex(b);
        temp = g->A[a];

        if(temp == NULL){
            g->A[a] = newnode;
        }
        else{
            while(temp->next != NULL){
                temp = temp ->next;
            }
            temp->next = newnode;
        }
    }

}

void DFS(struct graph* g, int V){

    int visited[V];
    int s;
    struct vertex_node* temp;

    printf("Enter the start vertex : \n");
    scanf("%d", &s);

    for(int i = 0;i<V;i++){
        visited[i] = 0;
    }

    visited[s] = 1;

    push(s);

 while (!stackempty())
    {
        int w = pop();
        printf("%d ", w);
        temp = g->A[w];
        while (temp != NULL)
        {
            int i = temp->vertex_number;
            if (visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
            temp = temp->next;
        }
    }



}

void display(int v, struct graph* g){

     for (int i = 0; i < g->no_of_vertices; i++)
    {
        struct vertex_node *p = g->A[i];
        printf("%d | ", i);
        while (p != NULL)
        {
            printf("%d -> ", p->vertex_number);
            p = p->next;
        }
        printf("NULL");
        printf("\n");
    }
}
int main()
{
    int V,data,e;
    printf("the number of vertices in the graph : ");
    scanf("%d", &V);

    printf("Enter the number of edges:");
    scanf("%d", &e);
    struct graph* g = createGraph(V);

    printf("Enter the start and end vertex for a edge: \n");
    createAdjList(V, g,e);

    display(V, g);

    DFS(g, V);

    return 0;
}

// 5
// 6
// 0 1
// 0 2
// 1 4
// 1 3
// 1 2
// 4 3
// 0
