#include<stdio.h>
#include<stdlib.h>

int OPERATORS[][2] = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3}
};

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
        return 0;
    } else {
        NODE* new_node = create_node(val);
        new_node->next = s->top;
        s->top = new_node;
        s->current_size++;
        // printf("Pushed %d to the stack\n", val);
        return 1;
    }
}

int pop(STACK* s, int* out_value) {
    if (is_empty(s)) {
        return 0;
    } else {
        NODE* temp = s->top;
        int popped_value = temp->data;
        s->top = s->top->next;
        free(temp);
        s->current_size--;
        *out_value = popped_value;
        return 1;
    }
}

int peek(STACK* s, int* out_value) {
    if (is_empty(s)) {
        return 0;
    } else {
        *out_value = s->top->data;
        return 1;
    }
}

int stack_top(STACK* s, int* out_value) {
    if (is_empty(s)) {
        // printf("Stack is empty! No top element\n");
        return 0;
    } else {
        *out_value = s->top->data;
        return 1;
    }
}

int stack_bottom(STACK* s, int* out_value) {
    if (is_empty(s)) {
        // printf("Stack is empty! No bottom element\n");
        return 0;
    } else {
        NODE* current = s->top;
        while (current->next != NULL) {
            current = current->next;
        }
        *out_value = current->data;
        return 1;
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
    // printf("Stack memory cleanup done\n");
}

int string_length(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
} 

int is_operator(char ch) {
    for (int i = 0; i < sizeof(OPERATORS) / sizeof(OPERATORS[0]); i++) {
        if (OPERATORS[i][0] == ch) {
            return 1;
        }
    }
    return 0;
}

int get_precedence(char ch) {
    for (int i = 0; i < sizeof(OPERATORS) / sizeof(OPERATORS[0]); i++) {
        if (OPERATORS[i][0] == ch) {
            return OPERATORS[i][1];
        }
    }
    return -1; // Return -1 for non-operators
}

char* infix_to_postfix(char* infix) {
    STACK* s = create_stack(string_length(infix));
    char* postfix = (char*) malloc((string_length(infix) + 1) * sizeof(char));
    int index;
    int popped_value;
    int top_value;
    int postfix_index = 0;

    for(index = 0; infix[index] != '\0'; index++) {
        if(infix[index] == ' ' || infix[index] == '\t') {
            continue;
        }

        if(infix[index] == '(') {
            push(s, infix[index]);
        } else if (infix[index] == ')') {
            while(pop(s, &popped_value) && popped_value != '(') {
                postfix[postfix_index++] = popped_value;
            }
        } else if (is_operator(infix[index])) {
            while(peek(s, &top_value) && 
                    (get_precedence(top_value) > get_precedence(infix[index]) ||
                        (get_precedence(top_value) == get_precedence(infix[index]) && infix[index] != '^')
            )) {
                pop(s, &popped_value);
                postfix[postfix_index++] = popped_value;
            }
            push(s, infix[index]);
        } else {
            postfix[postfix_index++] = infix[index];
        }
    }

    while(pop(s, &popped_value)) {
        postfix[postfix_index++] = popped_value;
    }

    free_stack(s);
    postfix[postfix_index] = '\0';

    return postfix;
}

void print_convertion(char* infix) {
    char* postfix = infix_to_postfix(infix);
    printf("%s => %s\n", infix, postfix);
    free(postfix);
}

int main() {
    printf("Infix to Postfix Conversion:\n");
    print_convertion("a+b");
    print_convertion("a+b*c");
    print_convertion("(a+b)*c");
    print_convertion("A*(B+C)/D");
    print_convertion("((A+B)*C-D)*E");
    print_convertion("x+y*z/w+u");
    print_convertion("p*q-r+s/t");
    return 0;
}