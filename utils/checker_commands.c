/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:16:11 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/25 20:51:39 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sabs(char *instraction, t_list **a, t_list **b)
{
	if (!(ft_strcmp(instraction, "sa")))
	{
		swap(a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "sb")))
	{
		swap(b);
		return (0);
	}	
	if (!(ft_strcmp(instraction, "ss")))
	{
		swap(a);
		swap(b);
		return (0);
	}
	return (1);
}

int	pab(char *instraction, t_list **a, t_list **b)
{
	if (!(ft_strcmp(instraction, "pa")))
	{
		push(a, b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "pb")))
	{
		push(b, a);
		return (0);
	}
	return (1);
}

int	rabr(char *instraction, t_list **a, t_list **b)
{
	if (!(ft_strcmp(instraction, "ra")))
	{
		rotate(a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rb")))
	{
		rotate(b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rr")))
	{
		rotate(a);
		rotate(b);
		return (0);
	}
	return (1);
}

int	rrabr(char *instraction, t_list **a, t_list **b)
{
	if (!(ft_strcmp(instraction, "rra")))
	{
		reverse_rotate(a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rrb")))
	{
		reverse_rotate(b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rrr")))
	{
		reverse_rotate(a);
		reverse_rotate(b);
		return (0);
	}
	return (1);
}

int	find_min(t_list **stack, int value)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != value)
			min = head->index;
	}
	return (min);
}
