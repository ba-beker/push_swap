/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:09:23 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 10:19:41 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = ft_strlen(s2);
	if (*s2 == 0)
		return ((char *) s1);
	while (*s1 && i <= n)
	{
		if (ft_strncmp(s1, s2, i) == 0 && *s1 == *s2)
			return ((char *)s1);
		n--;
		s1++;
	}
	return (NULL);
}
