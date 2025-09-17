#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int temp;
    int swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0;

        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break;
    }
}

void display(int arr[], int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    bubbleSort(arr, size);
    display(arr, size);

    return 0;
}

