/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:00:07 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/23 10:50:18 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push the first node a --> b || b --> a
int	push(t_list **to, t_list **from)
{
	t_list	*head_from;
	t_list	*head_to;
	t_list	*temp;

	if (stack_size(*from) == 0)
		return (-1);
	head_from = *from;
	head_to = *to;
	temp = head_from;
	head_from = head_from->next;
	*from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*to = head_to;
	}
	else
	{
		temp->next = head_to;
		*to = temp;
	}
	return (0);
}

// push a - take the first element at the top of b
// and put it at the top of a. Do nothing if b is empty.
int	pa(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

// push b - take the first element at the top of a
// and put it at the top of b. Do nothing if a is empty.
int	pb(t_list **a, t_list **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
