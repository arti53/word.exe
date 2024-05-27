
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

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    struct Node* parent = NULL;
    struct Node* current = root;

    // Find the node to be deleted and its parent
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node was not found
    if (current == NULL) {
        return root;
    }

    // Case 1: Node to be deleted has no children (leaf node)
    if (current->left == NULL && current->right == NULL) {
        if (current != root) {
            if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL;
        }
        free(current);
    }

    // Case 2: Node to be deleted has two children
    else if (current->left && current->right) {
        struct Node* successor = findMin(current->right);
        int val = successor->data;
        deleteNode(root, successor->data);
        current->data = val;
    }

    // Case 3: Node to be deleted has only one child
    else {
        struct Node* child = (current->left) ? current->left : current->right;

        if (current != root) {
            if (current == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
        free(current);
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
}

// Driver program
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        // printf("\nMenu:\n");
        // printf("1. Insert Node\n");
        // printf("2. Delete Node\n");
        // printf("3. Postorder Traversal\n");
        // printf("4. Exit\n");
        // printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: \n");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("\nPostorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
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
// 3
// 2
// 28
// 3
// 2
// 25
// 3
// 2
// 19
// 3
// 4
