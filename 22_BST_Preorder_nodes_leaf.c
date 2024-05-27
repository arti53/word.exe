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

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
        struct Node* newNode = createNode(data);

    // If the tree is empty, return a new node
    if (root == NULL) {
        return newNode;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    // Traverse the tree to find the insertion point
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            // If the data is already in the tree, do nothing and return the root
            free(newNode);
            return root;
        }
    }

    // Insert the new node as a child of the parent node
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;

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
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
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

// Function to perform preorder traversal iteratively
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(stack);
        printf("%d ", node->data);

        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }
}

// Function to count total nodes in the tree
int countTotalNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    struct Stack* stack = createStack(100);
    int count = 0;
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(stack);
        count++;

        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }

    return count;
}

// Function to display leaf nodes of the tree
void displayLeafNodes(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(stack);

        if (node->left == NULL && node->right == NULL) {
            printf("%d ", node->data);
        }

        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }
}

// Driver program
int main() {
    struct Node* root = NULL;
    int choice, value, count;

    while (1) {
        // printf("\nMenu:\n");
        // printf("1. Insert Node\n");
        // printf("2. Preorder Traversal\n");
        // printf("3. Display Total Number of Nodes\n");
        // printf("4. Display Leaf Nodes\n");
        // printf("5. Exit\n");
        // printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: \n");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                count = countTotalNodes(root);
                printf("Total Number of Nodes: %d\n", count);
                break;
            case 4:
                printf("Leaf Nodes: ");
                displayLeafNodes(root);
                printf("\n");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
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
// 5
