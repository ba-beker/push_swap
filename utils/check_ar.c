/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:27:29 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/25 20:54:04 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	includes(char **argv, int num, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

// checks if the pointer to string passed 
static int	is_valid_number(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_ar(int argc, char **argv)
{
	long	tmp;
	char	**ar;
	int		j;

	j = 0;
	if (argc == 2)
		ar = ft_split(argv[1], ' ');
	else
	{
		j = 1;
		ar = argv;
	}
	while (ar[j])
	{
		tmp = ft_atoi(ar[j]);
		if (!is_valid_number(ar[j]))
			get_error("Error");
		if (includes(ar, tmp, j))
			get_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			get_error("Error");
		j++;
	}
	if (argc == 2)
		get_free(ar);
}

int	get_length(t_list **a_b, int index)
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
