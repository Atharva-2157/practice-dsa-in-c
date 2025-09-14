#include<stdio.h>

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selection_sort(int arr[], int n) {
    int min;
    int index_of_min;
    int temp;
    for(int i = 0; i < n - 1; i++) {
        index_of_min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[index_of_min]) {
                index_of_min = j;
            }
        }
        swap(&arr[i], &arr[index_of_min]);
    }
}

void print_array(int arr[], int n) {
    for(int i = 0; i  < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 90, 76, 58, 36, 54, 45, 84, 38, 93};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array :\n");
    print_array(arr, n);

    selection_sort(arr, n);

    printf("Sorted array :\n");
    print_array(arr, n);
    return 0;
}