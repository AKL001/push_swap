#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Stack operations (implement these based on the project requirements)
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

// Helper functions 
void push(t_stack *stack, int value);
int pop(t_stack *stack);
int peek(t_stack *stack);
int stack_size(t_stack *stack);

// Sorting functions
void sort_three(t_stack *a);
void insert_sorted(t_stack *a, t_stack *b);
void sort_stack(t_stack *a, t_stack *b);

int main(int argc, char **argv) {
    t_stack a, b;
    int i;

    // Initialize stacks
    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    // Parse arguments and push to stack a
    for (i = argc - 1; i > 0; i--) {
        push(&a, atoi(argv[i]));
    }

    // Sort the stack
    sort_stack(&a, &b);

    // Free memory and exit
    while (a.top) {
        t_node *temp = a.top;
        a.top = a.top->next;
        free(temp);
    }

    return 0;
}

void sort_three(t_stack *a) {
    int first = peek(a);
    ra(a);
    int second = peek(a);
    ra(a);
    int third = peek(a);
    rra(a);
    rra(a);

    if (first > second && second > third) {
        sa(a);
        rra(a);
    } else if (first > second && second < third && first > third) {
        ra(a);
    } else if (first > second && second < third && first < third) {
        sa(a);
    } else if (first < second && second > third && first < third) {
        sa(a);
        ra(a);
    } else if (first < second && second > third && first > third) {
        rra(a);
    }
}

void insert_sorted(t_stack *a, t_stack *b) {
    int to_insert = peek(b);
    int size_a = stack_size(a);
    int rotations = 0;

    while (size_a > 0 && peek(a) < to_insert) {
        ra(a);
        rotations++;
        size_a--;
    }

    pa(a, b);

    while (rotations > 0) {
        rra(a);
        rotations--;
    }
}

void sort_stack(t_stack *a, t_stack *b) {
    // Push all but 3 elements to b
    while (stack_size(a) > 3) {
        pb(a, b);
    }

    // Sort the remaining 3 elements in a
    sort_three(a);

    // Push elements back to a, inserting them in the correct position
    while (stack_size(b) > 0) {
        insert_sorted(a, b);
    }
}

// Implement stack operations and helper functions here