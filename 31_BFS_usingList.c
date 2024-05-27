#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct stack
{
    int capacity;
    int top;
    int *arr;
};

struct stack *createStack(int capacity)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->capacity = capacity;
    st->top = -1;
    st->arr = (int *)malloc(sizeof(int) * st->capacity);
    return st;
}

void push(struct stack *st, int data)
{
    if (st->top >= st->capacity)
    {
        return;
    }

    st->arr[++st->top] = data;
}

int isEmpty(struct stack *st)
{
    if (st->top < 0)
    {
        return 1;
    }

    return 0;
}

int pop(struct stack *st)
{
    if (isEmpty(st))
    {
        return -1;
    }

    return st->arr[st->top--];
}

struct graph
{
    int V;
    struct node **head;
};

struct queue
{
    int f, r;
    int capacity;
    int *arr;
};

struct queue *createQueue(int capacity)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->f = q->r = -1;
    q->capacity = capacity;
    q->arr = (int *)malloc(sizeof(int) * q->capacity);
    return q;
}

void enqueue(struct queue *q, int value)
{
    if (q->r == q->capacity - 1)
    {
        printf("full\n");
        return;
    }
    q->arr[++q->r] = value;
}

int dequeue(struct queue *q)
{
    if (q->f == q->r)
    {
        printf("Empty \n");
        return -1;
    }

    return q->arr[++q->f];
}

struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->vertex = data;
    n->next = NULL;
    return n;
}

struct graph *createGraph(int v)
{

    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->V = v;
    g->head = (struct node **)malloc(v * sizeof(struct node *));
    for (int i = 0; i < v; i++)
    {
        g->head[i] = NULL;
    }

    return g;
}

void adjList(struct graph *g, int V)
{
    int e, u, v;
    struct node *p, *newV;
    printf("Enter number of edges : ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("Enter edge (start - end) : ");
        scanf("%d %d", &u, &v);
        newV = newNode(u);
        p = g->head[v];
        if (p == NULL)
        {
            g->head[v] = newV;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newV;
        }

        newV = newNode(v);
        p = g->head[u];
        if (p == NULL)
        {
            g->head[u] = newV;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newV;
        }
    }
}

void display(struct graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        struct node *p = g->head[i];
        printf("%d | ", i);
        while (p != NULL)
        {
            printf("%d -> ", p->vertex);
            p = p->next;
        }
        printf("Null");
        printf("\n");
    }
}

void BFS(struct graph *g, int v)
{
    int visited[v], start;
    struct node *temp;
    struct queue *q = createQueue(20);
    printf("Enter start vertex : ");
    scanf("%d", &start);
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    visited[start] = 1;
    enqueue(q, start);
    while (q->f != q->r)
    {
        int w = dequeue(q);
        printf("%d ", w);

        temp = g->head[w];
        while (temp != NULL)
        {
            int n = temp->vertex;
            if (visited[n] == 0)
            {
                enqueue(q, n);
                visited[n] = 1;
            }
            temp = temp->next;
        }
    }
}


void main()
{
    int v;
    printf("Enter number of vertics : ");
    scanf("%d", &v);
    struct graph *g = createGraph(v);
    adjList(g, v);
    display(g);
    printf("\n");
    BFS(g, v);
    
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
