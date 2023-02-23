/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:04:26 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/15 10:49:16 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gives index to each node from the list

static t_list	*find_nxt_min(t_list **a_b)
{
	int min;
	t_list *head;
	t_list *minimum;
	
	head = *a_b;
	min = 0;
	minimum = NULL;
	if (head)
	{
		while(head)
		{
			if ((head->index == -1) && (!min || head->value < minimum->value))
			{
				minimum = head;
				min = 1;
			}
			head = head->next;
		}
	}
	return (minimum);
}
void index_node(t_list **a_b)
{
	t_list	*head;
	int		i;
	
	i = 0;
	head = find_nxt_min(a_b);
	while (head)
	{
		head->index = i++;
		head = find_nxt_min(a_b);
	}
}
