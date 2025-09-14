#include<stdio.h>
#include<stdlib.h>

typedef struct DEQueue {
    int front;
    int rear;
    int capacity;
    int* array;
} DOUBLE_ENDED_QUEUE;

DOUBLE_ENDED_QUEUE* create_double_ended_queue(int size) {
    DOUBLE_ENDED_QUEUE* deq = (DOUBLE_ENDED_QUEUE*)malloc(sizeof(DOUBLE_ENDED_QUEUE));
    deq->capacity = size;
    deq->front = -1;
    deq->rear = -1;
    deq->array = (int*)malloc(deq->capacity * sizeof(int));
    return deq;
}

int is_full(DOUBLE_ENDED_QUEUE* deq) {
    return (deq->front == 0 && deq->rear == deq->capacity - 1) || (deq->front == deq->rear + 1);
}

int is_empty(DOUBLE_ENDED_QUEUE* deq) {
    return deq->front == -1;
}

int insert_front(DOUBLE_ENDED_QUEUE* deq, int value) {
    if (is_full(deq)) {
        printf("Double Ended Queue is full\n");
        return 0;
    }
    if (is_empty(deq)) {
        deq->front = 0;
        deq->rear = 0;
    } else if (deq->front == 0) {
        deq->front = deq->capacity - 1;
    } else {
        deq->front--;
    }
    deq->array[deq->front] = value;
    return 1;
}

int insert_rear(DOUBLE_ENDED_QUEUE* deq, int value) {
    if (is_full(deq)) {
        printf("Double Ended Queue is full\n");
        return 0;
    }
    if (is_empty(deq)) {
        deq->front = 0;
        deq->rear = 0;
    } else if (deq->rear == deq->capacity - 1) {
        deq->rear = 0;
    } else {
        deq->rear++;
    }
    deq->array[deq->rear] = value;
    return 1;
}

int delete_front(DOUBLE_ENDED_QUEUE* deq, int* out_value) {
    if (is_empty(deq)) {
        printf("Double Ended Queue is empty\n");
        return 0;
    }
    *out_value = deq->array[deq->front];
    deq->array[deq->front] = 0;
    if (deq->front == deq->rear) {
        deq->front = -1;
        deq->rear = -1;
    } else if (deq->front == deq->capacity - 1) {
        deq->front = 0;
    } else {
        deq->front++;
    }
    return 1;
}   

int delete_rear(DOUBLE_ENDED_QUEUE* deq, int* out_value) {
    if (is_empty(deq)) {
        printf("Double Ended Queue is empty\n");
        return 0;
    }
    *out_value = deq->array[deq->rear];
    deq->array[deq->rear] = 0;
    if (deq->front == deq->rear) {
        deq->front = -1;
        deq->rear = -1;
    } else if (deq->rear == 0) {
        deq->rear = deq->capacity - 1;
    } else {
        deq->rear--;
    }
    return 1;
}

void display(DOUBLE_ENDED_QUEUE* deq) {
    if (is_empty(deq)) {
        printf("Double Ended Queue is empty\n");
        return;
    }
    int i = deq->front;
    while (1) {
        printf("%d ", deq->array[i]);
        if (i == deq->rear) break;
        i = (i + 1) % deq->capacity;
    }
    printf("\n");
}

void free_double_ended_queue(DOUBLE_ENDED_QUEUE* deq) {
    if (deq) {
        if (deq->array) {
            free(deq->array);
        }
        free(deq);
    }
}

int main() {
    DOUBLE_ENDED_QUEUE* deq = create_double_ended_queue(5);
    insert_rear(deq, 10);
    insert_rear(deq, 20);
    insert_front(deq, 5);
    display(deq);
    int value;
    delete_front(deq, &value);
    printf("Deleted from front: %d\n", value);
    display(deq);
    delete_rear(deq, &value);
    printf("Deleted from rear: %d\n", value);
    display(deq);
    free_double_ended_queue(deq);
    return 0;
}