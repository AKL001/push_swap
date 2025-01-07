#include "push_swap.h"


int main()
{
    t_push_swap *a = NULL; // Initialize a to NULL
    t_push_swap *b = NULL; // Initialize b to NULL
    
    // first stack a
    t_push_swap *a1 = ft_lstnew(1);
    t_push_swap *a2 = ft_lstnew(2);
    ft_lstadd_prev_next(&a, a1);
    ft_lstadd_prev_next(&a, a2);
    t_push_swap *b1 = ft_lstnew(5);
    t_push_swap *b2 = ft_lstnew(10);
    ft_lstadd_prev_next(&b, b1);
    ft_lstadd_prev_next(&b, b2);
    ft_push_to_a(&a,&b);
    // Check if a has at least 2 elements
    if (a && a->next) {
        printf("=========================\n");
        printf("stack a -> %d |-> a1 => %d\nStack a len is => %d\n", a->num, a->next->num, ft_lstlen(a));
        printf("=========================\n");
    }

    // first stack  b

    // Check if b has at least 2 elements
    if (b) {
        printf("=========================\n");

        printf("stack b -> %d\n Stack b len is => %d\n", b->num,ft_lstlen(b));
        printf("=========================\n");
    }

}