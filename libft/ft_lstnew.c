/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:36:10 by ablabib           #+#    #+#             */
/*   Updated: 2024/11/03 15:43:40 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_push_swap	*ft_lstnew(int num)
{
	t_push_swap	*new_node;

	new_node = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}