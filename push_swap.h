/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:14:10 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/16 11:18:21 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	int					value;
	struct s_push_swap	*prev;
	struct s_push_swap	*next;
}						t_stack;

typedef struct s_chunk
{
	int					start;
	int					end;
}						t_chunk;

typedef struct s_cost
{
	int					index;
	int					moves;
	int					is_ra;
}						t_cost;

typedef struct s_max
{
	int					value;
	int					moves;
	int					poss;
}						t_max_cost;

typedef struct s_min
{
	int					value;
	int					moves;
	int					poss;
}						t_min_cost;

/* STACK INIT */
void					stack_init(t_stack **a, char **argv);
/* error handling && free*/
int						error_repetition(t_stack *a, int nbr);
int						error_syntax(char *str_nbr);
void					ft_error(t_stack **stack, char **av);
void					free_stack(t_stack **stack);
void					free_av(char **av);
/* LIBFT */
char					**ft_split(char const *s, char c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
/*--------------------utils----------------------*/
void					ft_push_to_a(t_stack **a, t_stack **b);
void					ft_push_to_b(t_stack **a, t_stack **b);
void					rotate_a_b(t_stack **a, t_stack **b);
void					rotate_a(t_stack **a);
void					rotate_b(t_stack **b);
void					r_rotate_a(t_stack **a);
void					r_rotate_b(t_stack **b);
void					rr_rotate(t_stack **a, t_stack **b);
void					swap_a(t_stack **a);
void					swap_b(t_stack **b);
void					swap_a_b(t_stack **a, t_stack **b);

/* sorted array */
int						*sort_list(t_stack *a);
t_max_cost				find_max(t_stack *stack, int size);
void					tiny_sort(t_stack **a);
void					holy_sort(t_stack **a, t_stack **b);

/* PUSH BACK TO A */
void					push_back_to_a(t_stack **b, t_stack **a);
/* additionals or tools */
void					sort_stack(t_stack **a, t_stack **b);
int						min_num(int a, int b);
int						is_in_chunk(int num, t_chunk chunk);

void					tiny_sort(t_stack **a);
int						*sort_array_copy(t_stack *stack, int size);
int						is_sorted(t_stack *stack);

/* stack  utils */
int						stack_len(t_stack *stack);
int						append_node(t_stack **stack, int nbr);
t_stack					*find_last_node(t_stack *head);
/* CHECKER  BONUS */
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
