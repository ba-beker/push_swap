/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:44:07 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 10:38:34 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ret;
	size_t		i;
	size_t		length;

	if (!s)
		return (0);
	length = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < length)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
