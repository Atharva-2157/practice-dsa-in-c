#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}NODE;

typedef struct stack {
    int total_size;
    int current_size;
    NODE* top;
}STACK;

NODE* create_node(int data) {
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

STACK* create_stack(int size) {
    STACK* s = (STACK*) malloc(sizeof(STACK));
    s->total_size = size;
    s->current_size = 0;
    s->top = NULL;
    return s;
}

void print_stack(STACK* s) {
    NODE* current = s->top;
    int index = s->current_size - 1;
    while (current != NULL) {
        printf("Element %d: %d\n", index, current->data);
        current = current->next;
        index--;
    }
    printf("\n");
}

int is_full(STACK* s) {
    return s->current_size == s->total_size;
}

int is_empty(STACK* s) {
    return s->current_size == 0;
}

int push(STACK* s, int val) {
    if (is_full(s)) {
        // printf("Stack Overflow! Cannot push %d to the stack\n", val);
        return -1;
    } else {
        NODE* new_node = create_node(val);
        new_node->next = s->top;
        s->top = new_node;
        s->current_size++;
        // printf("Pushed %d to the stack\n", val);
        return 1;
    }
}

int pop(STACK* s) {
    if (is_empty(s)) {
        // printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        NODE* temp = s->top;
        int popped_value = temp->data;
        s->top = s->top->next;
        free(temp);
        s->current_size--;
        // printf("Popped %d from the stack\n", popped_value);
        return popped_value;
    }
}

int peek(STACK* s) {
    if (is_empty(s)) {
        // printf("Stack is empty! Cannot peek\n");
        return -1;
    } else {
        return s->top->data;
    }
}

void free_stack(STACK* s) {
    NODE* current = s->top;
    NODE* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(s);
    printf("Stack memory cleanup done\n");
}

int main() {
    STACK* stack = create_stack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_stack(stack);

    printf("Popped: %d\n", pop(stack));
    print_stack(stack);

    printf("Popped: %d\n", pop(stack));
    print_stack(stack);

    free_stack(stack);
    return 0;
}