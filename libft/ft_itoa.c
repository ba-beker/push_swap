/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:52:42 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 19:02:08 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(int a)
{
	int	i;

	i = 0;
	if (a <= 0)
		i = 1;
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		n_len;

	n_len = int_len(n);
	new = ft_calloc(n_len + 1, sizeof(char));
	if (!new)
		return (0);
	if (n == 0)
		new[0] = '0';
	if (n < 0)
	{
		new[0] = '-';
		if (n == INT_MIN)
		{
			new[--n_len] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (n_len && n != 0)
	{
		new[--n_len] = (n % 10) + 48;
		n /= 10;
	}
	return (new);
}
