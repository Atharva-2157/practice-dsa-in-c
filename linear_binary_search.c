#include<stdio.h>

int linear_search(int arr[], int size, int element) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int size, int element) {
    int low = 0;
    int high = size;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == element) {
            return mid;
        } else if(arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element_to_search = 21;

    int linear_search_index = linear_search(arr, size, element_to_search);
    printf("Linear search result => %d.\n", linear_search_index);

    int binary_search_index = binary_search(arr, size, element_to_search);
    printf("Binary search result => %d.\n", binary_search_index);
}