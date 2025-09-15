#include<stdio.h>

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high) {
    int merged_array[100];
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            merged_array[k] = arr[i];
            i++;
        } else {
            merged_array[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        merged_array[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high) {
        merged_array[k] = arr[j];
        j++;
        k++;
    }

    for(int m = low; m <= high; m++) {
        arr[m] = merged_array[m];
    }
}

void merge_sort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }  
}

int main() {
    int arr[] = {6, 3, 4, 6, 21, 75, 93, 73, 39, 93, 83, 74, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array \n");
    print_array(arr, n);

    merge_sort(arr, 0, n);

    printf("Sorted array \n");
    print_array(arr, n);
    return 0;
    return 0;
}