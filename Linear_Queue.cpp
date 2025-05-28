#include <stdio.h>
#define max 10

int Q[max], F = -1, R = -1;

void Enqueue();
void Dequeue();
void Display();
void Count();
void Front();
void Rear();

int main() {
    int choice;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Front\n");
        printf("6. Rear\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                Enqueue();
                break;
            case 2: 
                Dequeue();
                break;
            case 3: 
                Display();
                break;
            case 4:
                Count();
                break;
            case 5:
                Front();
                break;
            case 6:
                Rear();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    }
}

void Enqueue() {
    int x;

    if (R == max - 1) {
        printf("Queue is Full!\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &x);
        if (F == -1) {
            F = 0;
        }
        R++;
        Q[R] = x;
        printf("Element %d inserted.\n", x);
    }
}

void Dequeue() {
    if (F == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Deleted element = %d\n", Q[F]);
        if (F == R) { // If only one element was in the queue
            F = R = -1;
        } else {
            F++;
        }
    }
}

void Display() {
    if (F == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = F; i <= R; i++) {
            printf("Q[%d] = %d\n", i, Q[i]);
        }
    }
}

void Count() {
    if (F == -1) {
        printf("Queue is Empty!\n");
    } else {
        int count = R - F + 1;
        printf("Number of elements in queue = %d\n", count);
    }
}

void Front() {
    if (F == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element = %d\n", Q[F]);
    }
}

void Rear() {
    if (F == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Rear element = %d\n", Q[R]);
    }
}

