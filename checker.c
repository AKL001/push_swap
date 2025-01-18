/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:24:45 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/18 12:06:11 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

char	*ft_read_until_newline(int fd)
{
	char	*buffer;
	char	c;
	int		i;
	int		bytes_read;

	buffer = malloc(1024 * sizeof(char));
	i = 0;
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
		bytes_read = read(fd, &c, 1);
	}
	buffer[i] = '\0';
	if (bytes_read <= 0 && i == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

int	get_action(t_stack **a, t_stack **b, char *action)
{
	if (!ft_strncmp(action, "ra\n", 3))
		return (checker_rotate_a(a), 1);
	if (!ft_strncmp(action, "rb\n", 3))
		return (checker_rotate_b(b), 1);
	if (!ft_strncmp(action, "rr\n", 3))
		return (checker_rotate_a_b(a, b), 1);
	if (!ft_strncmp(action, "sa\n", 3))
		return (checker_swap_a(a), 1);
	if (!ft_strncmp(action, "sb\n", 3))
		return (checker_swap_b(b), 1);
	if (!ft_strncmp(action, "ss\n", 3))
		return (checker_swap_a_b(a, b), 1);
	if (!ft_strncmp(action, "pa\n", 3))
		return (checker_ft_push_to_a(a, b), 1);
	if (!ft_strncmp(action, "pb\n", 3))
		return (checker_ft_push_to_b(a, b), 1);
	if (!ft_strncmp(action, "rra\n", 4))
		return (checker_r_rotate_a(a), 1);
	if (!ft_strncmp(action, "rrb\n", 4))
		return (checker_r_rotate_b(b), 1);
	if (!ft_strncmp(action, "rrr\n", 4))
		return (checker_rr_rotate(a, b), 1);
	return (0);
}

int	get_next_line(t_stack **a, t_stack **b)
{
	char	*action;
	int		result;

	action = ft_read_until_newline(0);
	if (!action)
		return (0);
	result = get_action(a, b, action);
	if (result)
		free(action);
	else
		error_clean(a, b, action);
	return (result);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	stack_init(&a, argv + 1);
	while (get_next_line(&a, &b))
		;
	if (check_is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	exit(0);
}
