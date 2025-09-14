#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
    int total_size;
    int front;
    int rear;
    int* arr;
}QUEUE;

QUEUE* create_queue(int size) {
    QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
    q->total_size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*) malloc(size * sizeof(int));
    return q;
}

int is_full(QUEUE* q) {
    return q->rear == (q->total_size - 1);
}

int is_empty(QUEUE* q) {
    return q->front == q->rear;
}

int enqueue(QUEUE* q, int val) {
    if (is_full(q)) {
        // printf("Queue Overflow! Cannot enqueue %d to the queue\n", val);
        return 0;
    } else {
        q->rear = q->rear + 1;
        q->arr[q->rear] = val;
        // printf("Enqueued %d to the queue\n", val);
        return 1;
    }
}

int dequeue(QUEUE* q, int* out_value) {
    if (is_empty(q)) {
        // printf("Queue Underflow! Cannot dequeue from the queue\n");
        return 0;
    } else {
        q->front = q->front + 1;
        *out_value = q->arr[q->front];
        q->arr[q->front] = 0;
        return 1;
    }
}

void print_queue(QUEUE* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
    } else {
        for (int i = q->front + 1; i <= q->rear; i++) {
            printf("Element %d: %d\n", i - (q->front + 1), q->arr[i]);
        }
    }
    printf("\n");
}   

void free_queue(QUEUE* q) {
    free(q->arr);
    free(q);
}

int main() {
    QUEUE* q = create_queue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    print_queue(q);

    int val;
    dequeue(q, &val);
    print_queue(q);

    dequeue(q, &val);
    print_queue(q);

    dequeue(q, &val);
    print_queue(q);

    dequeue(q, &val);
    print_queue(q);

    free_queue(q);
    return 0;
}
