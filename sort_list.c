/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:26:00 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/16 11:26:08 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

static void	bubblesort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int	*sort_list(t_stack *a)
{
	int	len;
	int	*array;
	int	i;

	if (!a)
		return (NULL);
	len = stack_len(a);
	array = malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (a)
	{
		array[i++] = a->value;
		a = a->next;
	}
	bubblesort(array, len);
	return (array);
}

int	is_array_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
