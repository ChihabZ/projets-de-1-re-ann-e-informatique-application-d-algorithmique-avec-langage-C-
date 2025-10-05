

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertFIFO(struct Node** head, struct Node** tail, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}


void displayList(struct Node* head) {
    printf("\nFIFO Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &value);
        insertFIFO(&head, &tail, value);
    }

    displayList(head);
    freeList(head);

    return 0;
}