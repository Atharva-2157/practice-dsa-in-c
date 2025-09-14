#include<stdio.h>
#include<stdlib.h>

struct my_array {
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct my_array *a, int t_size, int u_size) {
    // (*a).total_size = t_size;
    // (*a).used_size = u_size;
    // (*a).ptr = (int *)malloc(t_size * sizeof(int));

    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int));
}

void show(struct my_array *a) {
    for(int i = 0; i < a->used_size; i++) {
        printf("%d => %d\n", i, (a->ptr)[i]);
    }
}

void set_value(struct my_array *a) {
    int n;
    for(int i = 0; i < a->used_size; i++) {
        printf("Enter element %d = ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main() {
    struct my_array marks;
    create_array(&marks, 10, 2);

    printf("We are running set value now\n");
    set_value(&marks);

    printf("We are running show now\n");
    show(&marks);

    return 0;
}