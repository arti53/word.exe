#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    int weight;
    struct node *next;

};

int smallestPath(int visited[] ,int  dist[] , int v)
{
    int min = 99;
    int a;
    for(int i=0;i<v;i++)
    {
        if(dist[i]<min && visited[i]!=1)
        {
            min = dist[i];
            a=i;
        }
    }
    return a;
}

void diskstra(struct node *A[], int v) {

    int visited[v], u,dist[v];

    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        dist[i]=99;
    }

    printf("Enter start : ");
    scanf("%d",&u);

    dist[u]=0;
    struct node *temp;

    for(int i=0;i<v;i++)
    {
        u = smallestPath(visited,dist,v);
        visited[u] = 1;
        temp = A[u];
        while(temp!=NULL)
        {
            if(visited[temp->data]!=1 && dist[u]!=99 && temp->weight!=99 && dist[u] + temp->data < dist[temp->data])
            {
                dist[temp->data] = dist[u] + temp->weight;
            }
            temp = temp->next;
        }
        
    }

    for(int i=0;i<v;i++)
    {
        printf("%d---%d\n",i,dist[i]);
    }
    
}
int main()
{
    int v;
    printf("Enter the no of vertices : ");
    scanf("%d",&v);
    struct node *A[100];

    for(int i=0;i<v;i++)
    {
        A[i] = NULL;
    }

    struct node *temp=NULL;
    int edges;
    int neigh;

     int w;

    for(int i=0;i<v;i++)
    {
        printf("Enter the no of neighbours of %d : ",i);
        scanf("%d",&edges);
        for(int j=0;j<edges;j++)
        {
            printf("Enter the neighbour : ");
            scanf("%d",&neigh);
            printf("Enter the weight : ");
            scanf("%d",&w);
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = neigh;
            newnode->weight = w;
            newnode->next=NULL;
            if(A[i]==NULL)
            {
                A[i] = newnode;
            }
            else
            {
                temp->next = newnode;
            }
            temp = newnode;

        }
    }

    for(int i=0;i<v;i++)
    {
        temp=A[i];
        printf("%d",i);
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    diskstra(A,v);

}