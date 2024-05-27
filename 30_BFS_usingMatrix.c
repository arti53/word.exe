#include <stdio.h>
#include <stdlib.h>

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

void BFS(int v, int g[v][v]) // matrix
{
    int visited[v], start, w;
    struct queue *q = createQueue(v);
    printf("Enter start vertex : ");
    scanf("%d", &start);
    enqueue(q, start);
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    visited[start] = 1;
    while (q->f != q->r)
    {
        w = dequeue(q);
        printf("%d ", w);
        for (int i = 0; i < v; i++)
        {
            if (g[w][i] == 1 && visited[i] == 0)
            {
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
}


void main()
{
    int n, e, u, v;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    printf("Enter number of edges : ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("Enter edge (start - end) : ");
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    BFS(n, adjMatrix);
    
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
