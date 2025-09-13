#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

struct stack* create_stack(int size) {
    struct stack* s = (struct stack*) malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;  // empty stack
    s->arr = (int*) malloc(size * sizeof(int));
    return s;
}

void print_stack(struct stack *ptr) {
    for (int i = 0; i <= ptr->top; i++) {
        printf("Element %d: %d\n", i, ptr->arr[i]);
    }
    printf("\n");
}

int is_full(struct stack *ptr) {
    int is_full;
    if (ptr->top == ptr->size - 1) {
        is_full = 1;
    } else {
        is_full = 0;
    }

    return is_full;
}

int is_empty(struct stack *ptr) {
    int is_empty;
    if (ptr->top == -1) {
        is_empty = 1;
    } else {
        is_empty = 0;
    }

    return is_empty;
}

int push(struct stack *ptr, int val) {
    if (is_full(ptr)) {
        // printf("Stack Overflow! Cannot push %d to the stack\n", val);
        return -1;
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        // printf("Pushed %d to the stack\n", val);
        return 1;
    }
}

int pop(struct stack *ptr) {
    if (is_empty(ptr)) {
        // printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow! Cannot peek.\n");
        return -1;  // or some error value
    }
    return s->arr[s->top];
}

int free_stack(struct stack *ptr) {
    if (ptr == NULL) {
        return -1;
    }
    if (ptr->arr != NULL) {
        free(ptr->arr);
    }
    free(ptr);
    return 1;
}

int main() {
    struct stack *s;
    s = create_stack(80);

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    
    print_stack(s);

    pop(s);
    pop(s);
    pop(s);

    print_stack(s);
    
    free_stack(s);

    return 0;
}