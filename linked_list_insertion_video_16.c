#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void linked_list_traversal(struct node *head) {
    struct node *current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct node* insert_at_first(struct node *head, int data) {
    struct node *new_head = (struct node*)malloc(sizeof(struct node));
    new_head->data = data;
    new_head->next = head;

    return new_head;
}

void insert_at_index(struct node *head, int index, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *current_node = head;
    int i = 0;

    while(i != index - 1 && current_node->next != NULL) {
        current_node = current_node->next;
        i++;
    }
    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void insert_at_end(struct node *head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *current_node = head;
    
    while(current_node->next != NULL) {
        current_node = current_node->next;
    }

    new_node->data = data;
    new_node->next = NULL;
    current_node->next = new_node;
}

void insert_after_node(struct node *head, struct node *insert_after, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = insert_after->next;
    insert_after->next = new_node;
}

// Function to free entire linked list
void free_list(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;         // store current node
        head = head->next;   // move to next node
        free(temp);          // free current node
    }
}

int main() {
struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 24;
    third->next = NULL;

    printf("Initial traversal\n");
    linked_list_traversal(head);

    head = insert_at_first(head, 50);
    printf("Insert at first\n");
    linked_list_traversal(head);

    insert_at_index(head, 3, 70);
    printf("Insert at index %d\n", 3);
    linked_list_traversal(head);

    insert_at_end(head, 170);
    printf("Insert at end\n");
    linked_list_traversal(head);

    insert_after_node(head, second, 270);
    printf("Insert after node\n");
    linked_list_traversal(head);


    free_list(head);
    return 0;
}