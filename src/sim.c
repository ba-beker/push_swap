/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:03 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/23 10:53:06 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min(t_list **stack, int value)
{
	t_list *head;
	int min;

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
static void sort_3(t_list **a)
{
	t_list *head;
	int min;
	int n_min;
	
	head = *a;
	min = find_min(a, -1);
	n_min = find_min(a, min);
	if (is_sort(a))
		return ;
	if (head->index == min && head->next->index != n_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (head->index == n_min)
	{
		if(head->next->index == min)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if (head->next->index == min)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}
static void sort_4(t_list **a, t_list **b)
{
	int length;

	if (is_sort(a))
		return;
	length = get_length(a,find_min(a, -1));
	if (length == 1)
		ra(a);
	else if (length == 2)
	{
		ra(a);
		ra(a);
	}
	else if (length == 3)
		rra(a);
	if (is_sort(a))
		return;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void sort_5(t_list **a, t_list **b)
{
	int	length;
	length = get_length(a, find_min(a, -1));
	if (length == 1)
		ra(a);
	else if (length == 2)
	{
		ra(a);
		ra(a);
	}
	else if (length == 3)
	{
		rra(a);
		rra(a);
	}
	else if (length == 4)
		rra(a);
	if (is_sort(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}
int get_length(t_list **a_b, int index)
{
	t_list	*head;
	int		length;
	
	length = 0;
	head = *a_b;
	while (head)
	{
		if (head->index == index)
			break ;
		length++;
		head = head->next;
	}
	return (length);
}

void simple_sort(t_list **a, t_list **b)
{
	int size;

	if (is_sort(a) || stack_size(*a) == 0
		|| stack_size(*a) == 1)
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}