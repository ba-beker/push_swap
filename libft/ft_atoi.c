/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:27:23 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 00:24:23 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	check_space(char c)
{
	return (c == '\f' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\t' || c == ' ');
}

int	ft_atoi(const char *str)
{
	size_t	index;
	int		multiplier;
	int		symbol;

	index = 0;
	multiplier = 0;
	symbol = 1;
	while (check_space(str[index]))
		++index;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			symbol = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		multiplier = multiplier * 10 + (str[index] - 48);
		++index;
	}
	return (symbol * multiplier);
}
