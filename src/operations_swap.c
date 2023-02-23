/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:54:02 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/15 09:50:31 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swapping the first two elements of the list (a & b)
// Do nothing if there is only one or no elements).
int swap(t_list **a_b)
{
	t_list	*head;
	t_list	*next;
	int		temp_index;
	int		temp_value;

	if (stack_size(*a_b) < 2)
		return (-1);
	head = *a_b;
	next = head->next;
	if (!head && !next)
		return (-1);
	temp_index = head->index;
	temp_value = head->value;
	head->index = next->index;
	head->value = next->value;
	next->index = temp_index;
	next->value = temp_value;
	return (0);
}
// swap a - swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements).
int sa(t_list **a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}
// swap b - swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements).
int sb(t_list **b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}
// sa and sb at the same time.
int ss(t_list **a, t_list **b)
{
	if ((stack_size(*a) < 2)  || (stack_size(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}
