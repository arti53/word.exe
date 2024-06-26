#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at the front
void insertFront(int key) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front = front - 1;
    }

    queue[front] = key;
}

// Function to insert an element at the rear
void insertRear(int key) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }

    queue[rear] = key;
}

// Function to delete an element from the front
void deleteFront() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

// Function to delete an element from the rear
void deleteRear() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear = rear - 1;
    }
}

// Function to get the front element
int getFront() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    return queue[front];
}

// Function to get the rear element
int getRear() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    return queue[rear];
}

void display(){
    if(front == -1){
        printf("Empty queue.");
    }
    else{
        for(int i = front; i != rear; i = (i+1)%MAX){
            printf("%d ",queue[i]); 
        }
        printf("%d",queue[rear]);
    }
}
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                value = getFront();
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 6:
                value = getRear();
                if (value != -1) {
                    printf("Rear element: %d\n", value);
                }
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Input 1 5 1 7 2 6 7 1 5 2 6 2 9 5 6 7 3 7 4 7 8
