#include<stdio.h>

void bubble_sort(int arr[], int n) {
    int is_swapped = 0;
    int no_of_passed = 0;
    int temp;
    for (int i = 0; i < n-1; i++) {
        is_swapped = 0;
        no_of_passed++;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                is_swapped = 1;
            }
        }

        if (is_swapped == 0) {
            break; // Array is already sorted
        }
    }
    printf("Number of passes: %d\n", no_of_passed);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    print_array(arr, n);
    bubble_sort(arr, n);
    printf("Sorted array: \n");
    print_array(arr, n);
    return 0;
}