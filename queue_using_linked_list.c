#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}NODE;

typedef struct queue {
    NODE* front;
    NODE* rear;
}QUEUE;

NODE* create_node(int data) {
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

QUEUE* create_queue() {
    QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int is_empty(QUEUE* q) {
    return q->front == NULL;
}

int is_full(QUEUE* q) {
    NODE* temp = create_node(0);
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0; 
    }
}

int enqueue(QUEUE* q, int val) {
    if (is_full(q)) {
        // printf("Queue Overflow! Cannot enqueue %d to the queue\n", val);
        return 0;
    } else {
        NODE* new_node = create_node(val);
        if (is_empty(q)) {
            q->front = new_node;
            q->rear = new_node;
        } else {
            q->rear->next = new_node;
            q->rear = new_node;
        }
        // printf("Enqueued %d to the queue\n", val);
        return 1;
    }
}

int dequeue(QUEUE* q, int* out_value) {
    if (is_empty(q)) {
        // printf("Queue Underflow! Cannot dequeue from the queue\n");
        return 0;
    } else {
        NODE* temp = q->front;
        *out_value  = temp->data;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return 1;
    }
}

void print_queue(QUEUE* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
    } else {
        NODE* current = q->front;
        int index = 0;
        while (current != NULL) {
            printf("Element %d: %d\n", index, current->data);
            current = current->next;
            index++;
        }
    }
    printf("\n");
}

void free_queue(QUEUE* q) {
    NODE* current = q->front;
    NODE* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(q);
    // printf("Queue memory cleanup done\n");
}

int main() {

    QUEUE* q = create_queue();
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

