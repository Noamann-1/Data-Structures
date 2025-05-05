#include <stdio.h>

int main() {
    int size, i, ind, val;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size+1];
    printf("Enter the elements of array:\n");
    for (i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the index to insert value (0 to %d): ", size);
    scanf("%d", &ind);
    
    printf("\nEnter the value to insert: ");
    scanf("%d", &val);
    for (i=size; i>ind; i--) {
        arr[i] = arr[i-1];
    }
    arr[ind] = val;
    size++;
    printf("Array after insertion:\n");
    for (i=0; i<size; i++) { 
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
