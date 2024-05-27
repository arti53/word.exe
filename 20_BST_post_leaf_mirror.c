#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Stack structure for non-recursive traversal
struct Stack {
    int top;
    unsigned capacity;
    struct Node** array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node*)malloc(stack->capacity * sizeof(struct Node));
    return stack;
}

// Function to check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push node onto stack
void push(struct Stack* stack, struct Node* node) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

// Function to pop node from stack
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    return node;
}

// Function to perform postorder traversal iteratively
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);
    push(stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* temp = pop(stack1);
        push(stack2, temp);

        if (temp->left)
            push(stack1, temp->left);
        if (temp->right)
            push(stack1, temp->right);
    }

    while (!isEmpty(stack2)) {
        struct Node* temp = pop(stack2);
        printf("%d ", temp->data);
    }
    printf("\n");
}

// Function to display leaf nodes of the tree
void displayLeafNodes(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* temp = pop(stack);

        if (temp->left == NULL && temp->right == NULL)
            printf("%d ", temp->data);

        if (temp->right)
            push(stack, temp->right);
        if (temp->left)
            push(stack, temp->left);
    }
    printf("\n");
}

// Function to mirror the binary tree
void mirrorTree(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* temp = pop(stack);
        struct Node* tempSwap = temp->left;
        temp->left = temp->right;
        temp->right = tempSwap;

        if (temp->left)
            push(stack, temp->left);
        if (temp->right)
            push(stack, temp->right);
    }
}

// Driver program
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        // printf("\nMenu:\n");
        // printf("1. Insert Node\n");
        // printf("2. Postorder Traversal\n");
        // printf("3. Display Leaf Nodes\n");
        // printf("4. Mirror the Tree\n");
        // printf("5. Exit\n");
        // printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: \n");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Postorder Traversal: \n");
                postorderTraversal(root);
                break;
            case 3:
                printf("Leaf Nodes: \n");
                displayLeafNodes(root);
                break;
            case 4:
                mirrorTree(root);
                printf("Tree has been mirrored.\n");
                break;
            case 5:
                printf("Exiting!!!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


// 1
// 23
// 1
// 19
// 1
// 25
// 1
// 17
// 1
// 21
// 1
// 24
// 1
// 28
// 2
// 3
// 4
// 2
// 5
