#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Function to merge k sorted lists
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];

    // Merge lists in a divide-and-conquer manner
    int mid = listsSize / 2;
    struct ListNode* left = mergeKLists(lists, mid);
    struct ListNode* right = mergeKLists(lists + mid, listsSize - mid);

    return mergeTwoLists(left, right);
}

// Function to print a linked list
void printList(struct ListNode* head, FILE* outputFile) {
    while (head) {
        fprintf(outputFile, "%d ", head->val);
        head = head->next;
    }
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    FILE* inputFile = fopen("input4.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (!inputFile || !outputFile) {
        printf("File error.\n");
        return 1;
    }

    int k;
    fscanf(inputFile, "%d", &k);

    struct ListNode** lists = (struct ListNode**)malloc(k * sizeof(struct ListNode*));

    for (int i = 0; i < k; i++) {
        int n;
        fscanf(inputFile, "%d", &n);

        struct ListNode* head = NULL;
        struct ListNode* current = NULL;

        for (int j = 0; j < n; j++) {
            int val;
            fscanf(inputFile, "%d", &val);

            struct ListNode* newNode = createNode(val);

            if (!head) {
                head = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }

        lists[i] = head;
    }

    struct ListNode* mergedList = mergeKLists(lists, k);
    printList(mergedList, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    // Clean up memory
    for (int i = 0; i < k; i++) {
        struct ListNode* current = lists[i];
        while (current) {
            struct ListNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(lists);

    return 0;
}
