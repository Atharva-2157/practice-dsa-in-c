#include<stdio.h>
#include<stdlib.h>

typedef struct circular_queue {
    int total_size;
    int front;
    int rear;
    int* arr;
}CIRCULAR_QUEUE;

CIRCULAR_QUEUE* create_circular_queue(int size) {
    CIRCULAR_QUEUE* q = (CIRCULAR_QUEUE*) malloc(sizeof(CIRCULAR_QUEUE));
    q->total_size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*) malloc(size * sizeof(int));
    return q;
}

int is_full(CIRCULAR_QUEUE* q) {
    return (q->rear + 1) % q->total_size == q->front;
}

int is_empty(CIRCULAR_QUEUE* q) {
    return q->front == -1;
}

int enqueue(CIRCULAR_QUEUE* q, int val) {
    if (is_full(q)) {
        // printf("Queue Overflow! Cannot enqueue %d to the queue\n", val);
        return 0;
    } else {
        if (is_empty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->total_size;
        q->arr[q->rear] = val;
        // printf("Enqueued %d to the queue\n", val);
        return 1;
    }
}

int dequeue(CIRCULAR_QUEUE* q, int* out_value) {
    if (is_empty(q)) {
        // printf("Queue Underflow! Cannot dequeue from the queue\n");
        return 0;
    } else {
        *out_value = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->total_size;
        }
        return 1;
    }
}   

void print_circular_queue(CIRCULAR_QUEUE* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
    } else {
        int i = q->front;
        int index = 0;
        while (1) {
            printf("Element %d: %d\n", index, q->arr[i]);
            if (i == q->rear) {
                break;
            }
            i = (i + 1) % q->total_size;
            index++;
        }
    }
    printf("\n");
}   

void free_circular_queue(CIRCULAR_QUEUE* q) {
    free(q->arr);
    free(q);
    // printf("Circular Queue memory cleanup done\n");
} 

int main() {
    CIRCULAR_QUEUE* q = create_circular_queue(5);
    int dequeued_value;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    print_circular_queue(q);

    dequeue(q, &dequeued_value);
    printf("Dequeued: %d\n", dequeued_value);
    dequeue(q, &dequeued_value);
    printf("Dequeued: %d\n", dequeued_value);
    print_circular_queue(q);

    enqueue(q, 50);
    enqueue(q, 60);
    print_circular_queue(q);

    enqueue(q, 70); // This should fail as the queue is full
    print_circular_queue(q);

    while (dequeue(q, &dequeued_value)) {
        printf("Dequeued: %d\n", dequeued_value);
    }
    print_circular_queue(q);

    free_circular_queue(q);

    return 0;
}