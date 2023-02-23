/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:55:10 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 20:53:26 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_devider(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

void	membook(char **tab, char const *s, char sep)
{
	char		**returned;
	char const	*temp;

	temp = s;
	returned = tab;
	while (*temp)
	{
		while (*s == sep)
			s++;
		temp = s;
		while (*temp && *temp != sep)
			++temp;
		if (*temp == sep || temp > s)
		{
			*returned = ft_substr(s, 0, temp - s);
			s = temp;
			++returned;
		}
	}
	*returned = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (0);
	size = count_devider(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (0);
	membook(new, s, c);
	return (new);
}
