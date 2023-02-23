/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:27:29 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/22 14:51:50 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	includes(char **argv, int num, int i);
static int	is_valid_number(char *number);
void	check_ar(int argc, char **argv)
{
	char	**ar;
	int		j;
	long	t;

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
		t = ft_atoi(ar[j]);
		if (!is_valid_number(ar[j]))
			get_error("Error");
		if (includes(ar, t, j))
			get_error("Error");
		if (t < -2147483648 || t > 2147483647)
			get_error("Error");
		j++;
	}
	if (argc == 2)
		get_free(ar);
}
static int	includes(char **argv, int num, int i)
{
	i++;
	while(argv[i])
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
	int i;
	
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