#include<stdio.h>

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do {
        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }while(i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high) {
    int partition_index;

    if(low < high) {
        partition_index = partition(arr, low, high);
        quick_sort(arr, 0, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}


void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 3, 4, 6, 21, 75, 93, 73, 39, 93, 83, 74, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array \n");
    print_array(arr, n);

    quick_sort(arr, 0, n);

    printf("Sorted array \n");
    print_array(arr, n);
    return 0;
}