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

typedef struct s_chunk {
    int start;
    int end;
} t_chunk;

typedef struct s_cost {
    int index;      // Position in stack
    int moves;      // Number of moves needed
    int is_ra;      // 1 for ra, 0 for rra
} t_cost;

typedef struct s_max {
    int value;
    int moves;      // Position in stack
    int poss;      // Number of moves needed
} t_max_cost;


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
void rr_rotate(t_stack **a,t_stack **b);

// SWAP 
void swap_a(t_stack **a);
void swap_b(t_stack **b);
void swap_a_b(t_stack **a,t_stack **b);

/* sorted array */
int    *sort_list(t_stack *a);
t_max_cost find_max(t_stack *stack,int size);

/* additionals or tools */
void sort_stack(t_stack **a, t_stack **b);
int MIN(int a, int b);
int is_in_chunk(int num, t_chunk chunk);


// int find_closest_chunk_number(t_stack *stack, int chunk_min, int chunk_max); 
// void execute_rotation(t_stack **stack, int moves, char stack_name);
void tiny_sort(t_stack **a);
int *sort_array_copy(t_stack *stack, int size);
int is_sorted(t_stack *stack);
// void sort_stack(t_stack **a, t_stack **b);


/* stack  utils */
int     stack_len(t_stack *stack);
int    append_node(t_stack **stack,int nbr);
t_stack     *find_last_node(t_stack *head);



#endif 