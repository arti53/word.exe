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

// Function to insert a node into the BST non-recursively
struct Node* insertNode(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }

    struct Node* parent = NULL;
    struct Node* current = root;
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            return root; // Duplicate value
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

// Function to find the minimum value node in the BST non-recursively
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST non-recursively
struct Node* deleteNode(struct Node* root, int data) {
    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        return root; // Node not found
    }

    if (current->left == NULL || current->right == NULL) {
        struct Node* newCurrent;

        if (current->left == NULL) {
            newCurrent = current->right;
        } else {
            newCurrent = current->left;
        }

        if (parent == NULL) {
            free(current);
            return newCurrent;
        }

        if (current == parent->left) {
            parent->left = newCurrent;
        } else {
            parent->right = newCurrent;
        }

        free(current);
    } else {
        struct Node* minNode = findMin(current->right);
        int minValue = minNode->data;
        root = deleteNode(root, minNode->data);
        current->data = minValue;
    }

    return root;
}

// Function to find the height of the tree non-recursively
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int height = 0;
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front != rear) {
        int nodeCount = rear - front;
        height++;

        while (nodeCount > 0) {
            struct Node* node = queue[front++];
            if (node->left != NULL)
                queue[rear++] = node->left;
            if (node->right != NULL)
                queue[rear++] = node->right;
            nodeCount--;
        }
    }
    return height;
}

// Function to print nodes at a given level non-recursively
void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int currentLevel = 1;
    while (front != rear && currentLevel < level) {
        int nodeCount = rear - front;
        while (nodeCount > 0) {
            struct Node* node = queue[front++];
            if (node->left != NULL)
                queue[rear++] = node->left;
            if (node->right != NULL)
                queue[rear++] = node->right;
            nodeCount--;
        }
        currentLevel++;
    }

    while (front != rear) {
        struct Node* node = queue[front++];
        printf("%d ", node->data);
    }
}

// Function to print level order traversal of tree non-recursively
void printLevelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
        printf("\n");
    }
}

// Driver program
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: \n");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter value to delete: \n");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Level Order Traversal: \n");
                printLevelOrder(root);
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
// 21
// 3
// 4
