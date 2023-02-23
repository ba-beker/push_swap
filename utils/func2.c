/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:21:25 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/14 19:16:59 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_error(char *message)
{
	ft_putendl_fd(message, 1);
	exit(0);
}
void	get_free(char **string)
{
	int i;
	
	i = 0;
	while (string[i])
		i++;
	while(i >= 0)
		free(string[i--]);
}
t_list	*stack_last(t_list *a_b)
{
	t_list	*temp;
	temp = a_b;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (temp);
	}
	return (temp);
}