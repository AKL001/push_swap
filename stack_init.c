#include "push_swap.h"
#include <limits.h>
#include <stdio.h>


static long ft_atol(char  *str)
{
    long    res;
    int     i;
    int     sign;

    i = 0;
    res = 0;
    sign = 1;

    while(str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }    
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;    
    }
    return (res * sign);
}

void    stack_init(t_stack **a,char **argv)
{
    long    nbr;
    int     i;
    int     j;
    char    **av;
    i = 0;
    while(argv[i])
    {
        av = ft_split(argv[i], ' ');
        j = 0;
        while(av[j])
        {
            if(error_syntax(av[j]))
                ft_error(a,av);
            nbr = ft_atol(av[j]);
            if (nbr > INT_MAX || nbr < INT_MIN)
                ft_error(a,av);
            if (error_repetition(*a , (int)nbr))
                ft_error(a,av);
            append_node(a,(int)nbr);
            j++;
        }
        free_av(av);
        i++;
    }
    free_av(argv);
}
