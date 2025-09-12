#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void linked_list_traversal(struct node *head) {
    struct node *current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    }
    while(current != head);
    printf("\n");
} 

void insert_at_start(struct node *head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *current_node = head;

    while(current_node->next != head) {
        current_node = current_node->next;
    }

    new_node->data = data;
    new_node->next = head;
    current_node->next = new_node;
}

// Function to free a circular linked list
void free_list(struct node* head) {
    if (head == NULL) return;

    struct node* current = head->next;
    struct node* temp;

    // Traverse until we reach the head again
    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }

    // Finally free the head node
    free(head);
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
    third->next = head;

    printf("Initial traversal\n");
    linked_list_traversal(head);

    free_list(head);
    return 0;
}