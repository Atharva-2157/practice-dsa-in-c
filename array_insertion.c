#include<stdio.h>

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int index_insertion(int arr[], int size, int element, int capacity, int index) {
    if(size >= capacity) {
        return -1;
    }

    for (int i = size - 1; i >= index; i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int index_deletion(int arr[], int size, int capacity, int index) {
    if(index >= capacity) {
        return -1;
    }
    
    for(int i = index; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }

    return 1;
}

int main() {
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5; 
    int element = 45, capacity = 100, index = 3;
    
    display(arr, size);

    int success = index_insertion(arr, size, element, capacity, index);
    if(success == 1) {
        size += 1;
    }
    display(arr, size);

    int deletion_success = index_deletion(arr, size, capacity, 4);
    if(deletion_success == 1) {
        size -= 1;
    }
    display(arr, size);

    return 0;
}