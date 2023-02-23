/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:36:57 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/12 21:33:16 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// This function shifts down all elements of a_b by 1
// the last element becomes the first one.
int	reverse_rotate(t_list **a_b)
{
	t_list	*head;
	t_list	*last;
	if (stack_size(*a_b) < 2)
		return (-1);
	head = *a_b;
	last = stack_last(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break;
		}
		head = head->next;
	}
	last->next = *a_b;
	*a_b = last;
	return (0);
}

// 	reverse rotate a - shift down all elements of stack a by 1.
// The last element becomes the first one.
int	rra(t_list **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

// reverse rotate b - shift down all elements of stack b by 1.
// The last element becomes the first one.
int	rrb(t_list **b)
{
	if (reverse_rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

// rra and rrb at the same time.
int	rrr(t_list **a, t_list **b)
{
	if ((stack_size(*a) < 2) || (stack_size(*b) < 2))
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
