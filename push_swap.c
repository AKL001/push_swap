#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    
    if (argc < 2)
        return 1;
    stack_init(&a, argv + 1);
    if (!is_sorted(a))
    {
        if (stack_len(a) == 3)
            tiny_sort(&a);
        if (stack_len(a) == 5)
            holy_sort(&a,&b);   
        else
            sort_stack(&a, &b);
    }
    // printf("-------STACK A LEFT--------\n");
    // while(a){
    //     printf("%d\n",a->value);
    //     a = a->next;
    // }
    // printf("-------STACK B SORTED--------\n");
    // while(b){
    //     printf("%d\n",b->value);
    //     b = b->next;
    // }
    // Cleanup
    free_stack(&a);
    free_stack(&b);
    return 0;
}