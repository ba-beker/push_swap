/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:30:09 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 10:17:39 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*new1;
	unsigned char	*new2;

	new1 = (unsigned char *)str1;
	new2 = (unsigned char *)str2;
	while (*new1 == *new2 && *new1 && n)
	{
		++new1;
		++new2;
		--n;
	}
	if (n)
		return (*new1 - *new2);
	return (0);
}
