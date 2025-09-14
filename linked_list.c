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

    linked_list_traversal(head);

    free(head);
    free(second);
    free(third);
    
    return 0;
}