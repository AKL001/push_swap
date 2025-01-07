#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft/libft.h"

typedef struct s_push_swap
{
    int num;
    struct s_push_swap  *prev;
    struct s_push_swap  *next;
} t_push_swap;

/* LIBFT */
t_push_swap	*ft_lstnew(int num);
t_push_swap	*ft_lstlast(t_push_swap *lst);
void	ft_lstadd_prev_next(t_push_swap **lst, t_push_swap *new);
int	ft_lstlen(t_push_swap *lst);

/* utils */
void ft_push_to_a(t_push_swap **a, t_push_swap **b);

#endif 