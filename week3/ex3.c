#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void print_list(struct Node *lst) {
    while (lst != NULL) {
        printf("%d ", lst->value);
        lst = lst->next;
    }
    printf("\n");
}

struct Node *make_node(int value, struct Node *next) {
    struct Node *node = malloc(sizeof(struct Node));

    node->value = value;
    node->next = next;

    return node;
}

struct Node *get_node(struct Node *start, int index) {
    struct Node *current = start;
    int i = 0;
    while (i < index) {
        current = current->next;
        i++;
    }
    return current;
}


struct Node *insert_node(struct Node *start, int index, int value) {
    struct Node *inserted_node = make_node(value, NULL);

    // If we try to add to the beginning.
    if (index == 0) {
        inserted_node->next = start;
        return inserted_node;
    }

    // Find previous Node
    struct Node *current = get_node(start, index - 1);

    // Insert. UB if index >= length
    inserted_node->next = current->next;
    current->next = inserted_node;

    return start;
}

struct Node *delete_node(struct Node *start, int index) {
    // If we try to add to the beginning.
    if (index == 0) {
        return start->next;
    }

    // Find the previous node
    struct Node *current = get_node(start, index - 1);

    // Remove. UB if index >= length
    current->next = current->next->next;

    return start;
}

int main() {
    struct Node *lst = NULL;

    int N = 5;

    for (int i = 0; i < N; i++) {
        int index = rand() % (i + 1);
        int value = rand() % 100;
        lst = insert_node(lst, index, value);
        printf("Action: %d => %d\n", index, value);
        print_list(lst);
    }

    printf("\n");

    for (int i = 0; i < N - 1; i++) {
        int index = rand() % (N - i);
        lst = delete_node(lst, index);
        printf("Action: x %d\n", index);
        print_list(lst);
    }
}