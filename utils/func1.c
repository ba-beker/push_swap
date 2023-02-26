/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:30:22 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/25 19:26:24 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list **s)
{
	t_list	*head;

	head = *s;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_ab(t_list **stack)
{
	t_list	*start;
	t_list	*t;

	start = *stack;
	while (start)
	{
		t = start;
		start = start->next;
		free(t);
	}
	free(stack);
}

int	stack_size(t_list *head)
{
	size_t	i;
	t_list	*temp;

	temp = head;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// creates a new node and returns its pointer
t_list	*init_new_node(int num)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = num;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// this function adds a new node to the linked list
void	add_to_llist(t_list **a_b, t_list *new)
{
	t_list	*temp;

	if (*a_b)
	{
		temp = stack_last(*a_b);
		temp->next = new;
		new->next = NULL;
	}
	else
	{
		*a_b = new;
		(*a_b)->next = NULL;
	}
}
