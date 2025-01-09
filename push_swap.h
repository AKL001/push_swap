#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft/libft.h"

typedef struct s_push_swap
{
    int value;
    struct s_push_swap  *prev;
    struct s_push_swap  *next;
} t_stack;


/* STACK INIT */
void    stack_init(t_stack **a,char **argv);


/* error handling && free*/
int	error_repetition(t_stack *a, int nbr);
int	error_syntax(char *str_nbr);
void ft_error(t_stack **stack,char **av);
void free_stack(t_stack **stack);
void free_av(char **av);
// void free_cur_stack(t_stack **a);


/* LIBFT */
t_stack	*ft_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_prev_next(t_stack **lst, t_stack *new);
int	ft_lstlen(t_stack *lst);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*--------------------utils----------------------*/
// PUSH 
void ft_push_to_a(t_stack **a, t_stack **b);
void ft_push_to_b(t_stack **a, t_stack **b);
// ROTATE 
void rotate_a_b(t_stack **a,t_stack **b);
void rotate_a(t_stack **a);
void rotate_b(t_stack **b);
// Reverse ROTATE
void r_rotate_a(t_stack **a);
void r_rotate_b(t_stack **b);
void r_rotate_a_b(t_stack **a);




/* stack  utils */
int     stack_len(t_stack *stack);
int    append_node(t_stack **stack,int nbr);
t_stack     *find_last_node(t_stack *head);



#endif 