#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack *next;
};

struct Stack *top = NULL;

void PUSH();
void POP();
void DISPLAY();

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("[1]  PUSH\n");
        printf("[2]  POP\n");
        printf("[3]  DISPLAY STACK\n");
        printf("[4]  EXIT PROGRAM\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: PUSH(); break;
            case 2: POP(); break;
            case 3: DISPLAY(); break;
            case 4: printf("EXITED SUCCESSFULLY!\n"); return 0;
            default: printf("INVALID CHOICE! TRY AGAIN.\n");
        }
    }
    return 0;
}

void PUSH() {
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    int val;

    if (!newNode) {
        printf("Memory allocation failed!\n");
//        return;
    }
	else{
	
    printf("Enter value to PUSH: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = top;
    top = newNode;

    printf("Pushed: %d\n", val);
}
}

void POP() {
    if (top == NULL) {
        printf("STACK IS EMPTY!\n");
        return;
    }

    struct Stack *temp = top;
    printf("Popped: %d from address %p\n", temp->data, (void *)temp);
    top = top->next;
    free(temp);
}

void DISPLAY() {
    struct Stack *temp = top;
    if (top == NULL) {
        printf("STACK IS EMPTY!\n");
        return;
    }

    printf("STACK ELEMENTS (Top to Bottom): [ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

