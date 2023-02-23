/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:21:34 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 10:32:50 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char chr, const char *c)
{
	while (*c)
		if (*c++ == chr)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*finish;
	char	*returned;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	finish = start + ft_strlen(s1);
	while (*start && check(*start, set))
		start++;
	while (finish && check(*(finish - 1), set))
		finish--;
	returned = ft_substr(start, 0, finish - start);
	return (returned);
}
