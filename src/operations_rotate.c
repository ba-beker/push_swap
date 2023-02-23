/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:59:38 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/22 17:26:15 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function shift up all the nodes of the
// linked list  of a or b and the first element becomes the last one.
int	rotate(t_list **a_b)
{
	t_list	*head;
	t_list	*l;

	if (stack_size(*a_b) < 2)
		return (-1);
	head = *a_b;
	l = stack_last(head);
	*a_b = head->next;
	head->next = NULL;
	l->next = head;
	return (0);
}

// rotate a - shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ra(t_list **a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

// rotate b - shift up all elements of stack b by 1.
// The first element becomes the last one.
int	rb(t_list **b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

// ra and rb at the same time.
int	rr(t_list **a, t_list **b)
{
	if (stack_size(*a) < 2 || stack_size(*b) < 2)
		return (-1);
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}
