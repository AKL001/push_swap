#include "push_swap.h"

/* determinating what and who should go first or be executed 
    1- {arraylen}/2 
    // comparint the possition of the number with half of the array
    // 
    2- number possition if >= (arraylen)/2 
    // meaning if the  possition of 10-> 2 and 2 >= 50 meaning not gonna execute it
    3- check  if the number  is bigger or smaller than the numbers in stack b;
    

*/
t_stack *find_highest(t_stack *a)
{
    t_stack *max;

    if (!a)  // Check if the list is empty
        return NULL;

    max = a;  // Initialize max to the first node

    while (a != NULL)  // Iterate through the list
    {
        if (a->value > max->value)  // If the current node has a higher value
            max = a;  // Update max to the current node
        a = a->next;  // Move to the next node
    }

    return max;  // Return the node with the highest value
}



void tiny_sort(t_stack **a)
{
    t_stack *big_node;

    big_node = find_highest(*a);
    if (*a == big_node)
        rotate_a(a);
    else if ((*a)->next == big_node)
        r_rotate_a(a);
    if ((*a)->value > (*a)->next->value)
        swap_a(a);
}

int main(int argc, char *argv[])
{
    t_stack *a = NULL; // Initialize a to NULL

    /* testing parssing */
    stack_init(&a, argv + 1);
    // int *array = sort_list(a);
    // tiny_sort(&a);
    // printf("-------stack A with list --------\n");
    // while(a)
    // {
    //     printf("%d\n",a->value);
    //     a = a->next;
    // }
    // int len = stack_len(a);
    // // int i = 0;
    // while(len--)
    // {                           
    //     printf("%d\n",(*array));

    //     array++;
    // }
    // while(*array)
    // {
    //     printf("%d\n",(*array));
    //     array++;
    // }

    // free_stack(&a);
    return 0;
}