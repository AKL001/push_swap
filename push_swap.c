#include "push_swap.h"

/* determinating what and who should go first or be executed 
    1- {arraylen}/2 
    // comparint the possition of the number with half of the array
    // 
    2- number possition if >= (arraylen)/2 
    // meaning if the  possition of 10-> 2 and 2 >= 50 meaning not gonna execute it
    3- check  if the number  is bigger or smaller than the numbers in stack b;
    

*/

int main(int argc, char *argv[])
{
    t_stack *a = NULL; // Initialize a to NULL
    t_stack *b = NULL; // Initialize b to NULL
    
    // first stack a
    // t_stack *a1 = ft_lstnew(1);
    // t_stack *a2 = ft_lstnew(2);
    // ft_lstadd_prev_next(&a, a1);
    // ft_lstadd_prev_next(&a, a2);
    // t_stack *b1 = ft_lstnew(5);
    // t_stack *b2 = ft_lstnew(10);
    // ft_lstadd_prev_next(&b, b1);
    // ft_lstadd_prev_next(&b, b2);
    // ft_push_to_a(&a,&b);
    // // Check if a has at least 2 elements
    // if (a && a->next) {
    //     printf("=========================\n");
    //     printf("stack a -> %d |-> a1 => %d\nStack a len is => %d\n", a->num, a->next->num, ft_lstlen(a));
    //     printf("=========================\n");
    // }

    // // first stack  b

    // // Check if b has at least 2 elements
    // if (b) {
    //     printf("=========================\n");

    //     printf("stack b -> %d\n Stack b len is => %d\n", b->num,ft_lstlen(b));
    //     printf("=========================\n");
    // }
    // argv = ft_split(argv[1], ' ');
    
    /* testing parssing */
    stack_init(&a, argv + 1);
    // ft_push_to_b(&a,&b);
    // ft_push_to_b(&a,&b);
    // ft_push_to_b(&a,&b);
    // printf("-------stack B--------\n");
    // while(b)
    // {
    //     printf("%d\n",b->value);
    //     b = b->next;
    // }  
    r_rotate_a(&a);
    printf("-------stack A--------\n");
    while(a)
    {                           
        printf("%d\n",a->value);
        a = a->next;
    }

    // printf("-------stack AFTER A--------\n");
    // rotate_a(&a);
    // while(a)
    // {                           
    //     printf("%d\n",a->value);
    //     a = a->next;
    // }
    // printf("-------stack AFTER B--------\n");
    // // rotate_b(&b);
    // while(b)
    // {
    //     printf("%d\n",b->value);
    //     b = b->next;
    // }  
    free_stack(&a);
    // free_stack(&b);

    return 0;
    // free_split(argv);
    /* problem leaks */
    // char *nbr =  "-24";
    // char *dup = ft_substr(nbr, 0 ,3);
    // if (dup)
    // {
    //     printf("%s\n",dup);
    //     free(dup);
    // }
    // else
    //     printf("error\n");
    // char *number[5] = {"13 37", "12" , "22" , NULL};
    // char **res = ft_split(number[1], ' ');
    // printf("%s\n%s\n", res[0],res[1]);
    // char *av[] = ft_split(number[1], ' ');

    // printf("%s\n",av[0]);

    /* SPLIT TEST */
    // int i;
    // // char *test = "13 37 99";
    // char **av = ft_split(argv[1], ' ');

    // i = 0;
    // while (av[i])  // While the pointer to the current element is not NULL
    // {
    //     printf("%s\n", av[i]);  // Dereference the pointer to get the string
    //     i++;  // Move to the next element in the array
    // }
    // free_split(av);



}