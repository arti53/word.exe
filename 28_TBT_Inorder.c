#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    int lbit; 
    int rbit;
    struct node *left, *right;
};

struct node* insertTBT(struct node *head, int data){
    struct node *temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->lbit = temp->rbit = 0;
    temp->val = data;
    if(head->lbit == 0){
        head->left = temp;
        temp->left = temp->right = head;
        head->lbit = 1;
        return head;
    }
    p = head->left;

    while(1){
        if(data < p->val && p->lbit == 1){
            p = p->left;
        }
        else if(data > p->val && p->rbit == 1){
            p = p->right;
        }
        else{
            break;
        }
    }

    if(data < p->val){
        temp->right = p;
        temp->left = p->left;
        p->left = temp;
        p->lbit = 1;
    }

    if(data > p->val){
        temp->left = p;
        temp->right = p->right;
        p->right = temp;
        p->rbit = 1;
    }
    return head;
}

void inorderTBT(struct node *root) {
    struct node *temp = root->left;

    while(temp->lbit == 1){
        temp = temp->left;
    }

    while(temp != root){
        printf("%d - ",temp->val);
        if(temp->rbit == 1){
            temp = temp->right;
            while(temp->lbit == 1){
                temp = temp->left;
            }
        }
        else{
            temp = temp->right;
        }
    }
}

int main(){
    int data;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->lbit = 0;
    head->rbit = 1;
    head->left = head->right = head;

    int choice;
    int x;
    
    while(1) {
        printf("\n\n\t Threaded Binary Tree Menu:\n\n");
        printf("1. Create TBT\n");
        printf("2. Insert node \n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the how many nodes :");
                scanf("%d",&x);
                break;
            case 2:
                printf("\nEnter the data : ");
                for(int i=0; i<x; i++){
                    scanf("%d",&data);
                    head = insertTBT(head, data);
                }
                break;
            case 3:
                printf("\nInorder Traversal: ");
                inorderTBT(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

// 1 5
// 2
// 34
// 25
// 12
// 60
// 45
// 3
// 4
