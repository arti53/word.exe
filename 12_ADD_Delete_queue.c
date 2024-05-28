#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Queue {
    int size;
    Node* head;
    Node* tail;
} Queue;

const Queue queue_init = { .size = 0, .head = NULL, .tail = NULL };

int is_empty_q(Queue *q) {
    return q->tail == NULL;
}

Node* create_node(int elm) {
    Node* node = malloc(sizeof *node);
    if (!node) return NULL;
    node->data = elm;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void enqueue(Queue *q, int elm) {
    Node* updated_head = create_node(elm);
    if (!updated_head) return;
    if (!q->head) {
        q->head = updated_head;
        q->tail = q->head;
    } else {
        updated_head->next = q->head;
        q->head->prev = updated_head;
        q->head = updated_head;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (!is_empty_q(q)) {
        Node* node = q->tail;
        int elm = q->tail->data;
        q->tail = node->prev;
        if (q->tail) {
            q->tail->next = NULL;
        } else {
            q->head = NULL;
        }
        free(node);
        q->size--;
        return elm;
    }
    return -111; // assuming -111 won't be in the queue
}

int front(Queue *q) {
    if (q->tail)
        return q->tail->data;
    else
        return -111;
}

void clear_q(Queue *q) {
    while (!is_empty_q(q))
        dequeue(q);
    printf("Queue Cleared\n");
}

void reverse_q(Queue *q) {
    if (is_empty_q(q)) return;

    Node *current = q->head;
    Node *temp = NULL;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Swap head and tail pointers
    if (temp != NULL) {
        q->head = temp->prev;
    }

    // Update the tail pointer
    q->tail = q->head;
    while (q->tail->next != NULL) {
        q->tail = q->tail->next;
    }
}

void print_q(Queue *q) {
    for(Node* trav = q->head; trav != NULL; trav = trav->next)
        printf("%d ", trav->data);
    printf("\n");
}

int main() {
    Queue q1 = queue_init;
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Clear Queue\n");
        printf("5. Front Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q1, value);
                break;
            case 2:
                value = dequeue(&q1);
                if (value == -111) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                print_q(&q1);
                break;
            case 4:
                clear_q(&q1);
                break;
            case 5:
                value = front(&q1);
                if (value == -111) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Front element: %d\n", value);
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


// 1 1
// 1 2
// 1 3
// 1 4
// 2
// 3
// 5
// 4
// 6















// #include <stdio.h>
// #include <stdlib.h>

// // Structure for doubly linked list node
// struct Node {
//     int data;
//     struct Node* prev;
//     struct Node* next;
// };

// // Structure for stack
// struct Stack {
//     int top;
//     unsigned capacity;
//     int* array;
// };

// // Function to create a new doubly linked list node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->prev = NULL;
//     newNode->next = NULL;
//     return newNode;
// }

// struct Stack* createStack(unsigned capacity) {
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//     stack->top = -1;
//     stack->capacity = capacity;
//     stack->array = (int*)malloc(stack->capacity * sizeof(int));
//     return stack;
// }

// void push(struct Stack* stack, int item) {
//     if (stack->top == stack->capacity - 1) {
//         printf("Stack Overflow\n");
//         return;
//     }
//     stack->array[++stack->top] = item;
// }

// int pop(struct Stack* stack) {
//     if (stack->top == -1) {
//         printf("Stack Underflow\n");
//         return -1;
//     }
//     return stack->array[stack->top--];
// }

// void enqueue(struct Node** front, struct Node** rear, struct Stack* stack, int data) {
//     struct Node* newNode = createNode(data);

//     if (*rear == NULL) {
//         *front = *rear = newNode;
//     } else {
//         (*rear)->next = newNode;
//         newNode->prev = *rear;
//         *rear = newNode;
//     }

//     push(stack, data);
// }

// int dequeue(struct Node** front, struct Node** rear) {
//     if (*front == NULL) {
//         printf("Queue is empty\n");
//         return -1;
//     }

//     struct Node* temp = *front;
//     int data = temp->data;

//     *front = (*front)->next;
//     if (*front == NULL)
//         *rear = NULL;
//     else
//         (*front)->prev = NULL;

//     free(temp);
//     return data;
// }

// void displayQueue(struct Node* front) {
//     if (front == NULL) {
//         printf("Queue is empty\n");
//         return;
//     }

//     printf("Queue: ");
//     while (front != NULL) {
//         printf("%d ", front->data);
//         front = front->next;
//     }
//     printf("\n");
// }

// int main() {
//     struct Node* front = NULL;
//     struct Node* rear = NULL;
//     struct Stack* stack = createStack(100); // Adjust the capacity as needed
//     int choice, data;

//         printf("\nMenu:\n");
//         printf("1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Display Queue\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");

//     while (1) {
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter data to enqueue: \n");
//                 scanf("%d", &data);
//                 enqueue(&front, &rear, stack, data);
//                 break;
//             case 2:
//                 data = dequeue(&front, &rear);
//                 if (data != -1) {
//                     printf("Dequeued element: %d\n", data);
//                 }
//                 break;
//             case 3:
//                 displayQueue(front);
//                 break;
//             case 4:
//                 printf("Exiting !!!\n");
//                 return 0;
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     }

//     return 0;
// }


// // Input 
// // 1
// // 10
// // 1
// // 20
// // 1
// // 30
// // 3
// // 2
// // 3
// // 4
