/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:36:32 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/14 18:49:01 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int max_bit(t_list **a_b)
{
	t_list	*head;
	int		max;
	int		max_bits;
	
	head = *a_b;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
void comp_sort(t_list **a, t_list **b)
{
	t_list *head_a;
	int i;
	int j;
	int size;
	int max_bits;
	
	i = 0;
	head_a = *a;
	size = stack_size(head_a);
	max_bits = max_bit(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (stack_size(*b) != 0)
			pa(a, b);
		i++;
	}
}