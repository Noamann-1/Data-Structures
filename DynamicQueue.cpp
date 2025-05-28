#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *front = NULL, *rear = NULL;

void ENQUEUE();
void DEQUEUE();
void DISPLAY();
void COUNT();
void SEARCH();

int main() {
    int choice;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("[1]  ENQUEUE\n");
        printf("[2]  DEQUEUE\n");
        printf("[3]  DISPLAY QUEUE\n");
        printf("[4]  COUNT ELEMENTS\n");
        printf("[5]  SEARCH ELEMENT\n");
        printf("[6]  EXIT PROGRAM\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: ENQUEUE(); break;
            case 2: DEQUEUE(); break;
            case 3: DISPLAY(); break;
            case 4: COUNT(); break;
            case 5: SEARCH(); break;
            case 6: printf("EXITED SUCCESSFULLY!\n"); return 0;
            default: printf("INVALID CHOICE! TRY AGAIN.\n");
        }
    }
    return 0;
}

void ENQUEUE() {
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    int val;
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value to ENQUEUE: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", val);
}

void DEQUEUE() {
    if (front == NULL) {
        printf("QUEUE IS EMPTY!\n");
        return;
    }

    struct Queue *temp = front;
    printf("Dequeued: %d from address %p\n", temp->data, (void *)temp);
    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
}

void DISPLAY() {
    struct Queue *temp = front;
    if (front == NULL) {
        printf("QUEUE IS EMPTY!\n");
        return;
    }

    printf("QUEUE ELEMENTS: [ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void COUNT() {
    struct Queue *temp = front;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("TOTAL ELEMENTS IN QUEUE: %d\n", count);
}

void SEARCH() {
    if (front == NULL) {
        printf("QUEUE IS EMPTY!\n");
        return;
    }

    int key, found = 0;
    struct Queue *temp = front;
    printf("Enter element to SEARCH: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d FOUND at address %p\n", key, (void *)temp);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("Element %d NOT FOUND in the queue.\n", key);
}

