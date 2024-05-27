#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to merge two sorted doubly linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* t1 = head1;
    struct Node* t2 = head2;
    struct Node* mergedHead = NULL;
    struct Node* temp;

    if (t1 == NULL) 
        return t2;
    if (t2 == NULL) 
        return t1;

    if (t1->data <= t2->data) {
        mergedHead = t1;
        t1 = t1->next;
    } else {
        mergedHead = t2;
        t2 = t2->next;
    }

    temp = mergedHead;

    while (t1 != NULL && t2 != NULL) {
        if (t1->data <= t2->data) {
            temp->next = t1;
            t1->prev = temp;
            t1 = t1->next;
        } else {
            temp->next = t2;
            t2->prev = temp;
            t2 = t2->next;
        }
        temp = temp->next;
    }

    if (t1 != NULL) {
        temp->next = t1;
        t1->prev = temp;
    } else if (t2 != NULL) {
        temp->next = t2;
        t2->prev = temp;
    }

    return mergedHead;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* mergedHead = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node into List 1\n");
        printf("2. Insert a node into List 2\n");
        printf("3. Print List 1\n");
        printf("4. Print List 2\n");
        printf("5. Merge the two lists\n");
        printf("6. Print Merged List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert into List 1: ");
                scanf("%d", &data);
                insert(&head1, data);
                break;
            case 2:
                printf("Enter the data to insert into List 2: ");
                scanf("%d", &data);
                insert(&head2, data);
                break;
            case 3:
                printf("List 1: ");
                printList(head1);
                break;
            case 4:
                printf("List 2: ");
                printList(head2);
                break;
            case 5:
                mergedHead = mergeLists(head1, head2);
                printf("Lists merged successfully.\n");
                break;
            case 6:
                if (mergedHead != NULL) {
                    printf("Merged List: ");
                    printList(mergedHead);
                } else {
                    printf("Lists have not been merged yet.\n");
                }
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


//Input 1 2 1 5 2 3 2 7 3 4 5 6 7
