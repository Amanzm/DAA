#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Recursive Preorder Traversal
void preorderRecursive(struct TreeNode* root, FILE* outputFile) {
    if (root != NULL) {
        fprintf(outputFile, "%d ", root->data);
        preorderRecursive(root->left, outputFile);
        preorderRecursive(root->right, outputFile);
    }
}

// Non-recursive Preorder Traversal using a stack
void preorderNonRecursive(struct TreeNode* root, FILE* outputFile) {
    // Implementation similar to non-recursive inorder traversal
    // But, print the data before pushing onto the stack
    struct TreeNode* stack[100];
    int top = -1;

    while (root != NULL || top >= 0) {
        while (root != NULL) {
            fprintf(outputFile, "%d ", root->data);
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];
        root = root->right;
    }
}

// Recursive Postorder Traversal
void postorderRecursive(struct TreeNode* root, FILE* outputFile) {
    if (root != NULL) {
        postorderRecursive(root->left, outputFile);
        postorderRecursive(root->right, outputFile);
        fprintf(outputFile, "%d ", root->data);
    }
}

// Non-recursive Postorder Traversal using two stacks
void postorderNonRecursive(struct TreeNode* root, FILE* outputFile) {
    struct TreeNode* stack1[100];
    struct TreeNode* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        root = stack1[top1--];
        stack2[++top2] = root;

        if (root->left)
            stack1[++top1] = root->left;
        if (root->right)
            stack1[++top1] = root->right;
    }

    while (top2 >= 0) {
        root = stack2[top2--];
        fprintf(outputFile, "%d ", root->data);
    }
}

// Level-order Traversal
void levelOrder(struct TreeNode* root, FILE* outputFile) {
    if (root == NULL) return;

    struct TreeNode* queue[100];
    int front = 0;
    int rear = -1;

    queue[++rear] = root;

    while (front <= rear) {
        struct TreeNode* current = queue[front++];
        fprintf(outputFile, "%d ", current->data);

        if (current->left)
            queue[++rear] = current->left;
        if (current->right)
            queue[++rear] = current->right;
    }
}

int main() {
    // Open the input and output files
    FILE* inputFile = fopen("input7.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("File error.\n");
        exit(1);
    }

    struct TreeNode* root = NULL;
    int data;

    // Read input data from the file and insert into the binary tree
    while (fscanf(inputFile, "%d", &data) != EOF) {
        root = insert(root, data);
    }

    // Recursive Preorder Traversal
    fprintf(outputFile, "Recursive Preorder Traversal: ");
    preorderRecursive(root, outputFile);
    fprintf(outputFile, "\n");

    // Non-recursive Preorder Traversal
    fprintf(outputFile, "Non-recursive Preorder Traversal: ");
    preorderNonRecursive(root, outputFile);
    fprintf(outputFile, "\n");

    // Recursive Postorder Traversal
    fprintf(outputFile, "Recursive Postorder Traversal: ");
    postorderRecursive(root, outputFile);
    fprintf(outputFile, "\n");

    // Non-recursive Postorder Traversal
    fprintf(outputFile, "Non-recursive Postorder Traversal: ");
    postorderNonRecursive(root, outputFile);
    fprintf(outputFile, "\n");

    // Level-order Traversal
    fprintf(outputFile, "Level-order Traversal: ");
    levelOrder(root, outputFile);
    fprintf(outputFile, "\n");

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
