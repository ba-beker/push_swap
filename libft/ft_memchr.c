/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:46:31 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 00:30:44 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char			*t;

	t = (unsigned char *)str;
	c = (unsigned char)c;
	while (n && *t != c)
	{
		t++;
		n--;
	}
	if (n)
		return ((void *)t);
	return (0);
}
