#include<stdio.h>

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void count_sort(int arr[], int n) {
    int max = arr[0];
    int count_array[100];
    int i, j;
    for(i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    for (i = 0; i <= max; i++) {
        count_array[i] = 0;
    }

    for(i = 0; i < n; i++) {
        count_array[arr[i]] += 1;
    }

    j = 0;
    for(i = 0; i <= max; i++) {
        while(count_array[i] > 0) {
            arr[j] = i;
            count_array[i] -= 1;
            j++;
        }
    }

}

int main() {
    int arr[] = {6, 3, 4, 6, 21, 75, 93, 73, 39, 93, 83, 74, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array \n");
    print_array(arr, n);

    count_sort(arr, n);

    printf("Sorted array \n");
    print_array(arr, n);
    return 0;
    return 0;
}