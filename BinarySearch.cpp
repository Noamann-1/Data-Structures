#include <stdio.h>

int main() {
    int size, key;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d.\n", mid);
            return 0;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    printf("Element not found.\n");
    return 0;
}

