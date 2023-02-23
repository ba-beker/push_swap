/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:21:28 by mobabeke          #+#    #+#             */
/*   Updated: 2022/12/24 18:53:33 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	const unsigned char	*source;
	unsigned char		*destination;

	if (!dest && !src)
		return (0);
	if (dest < src)
		return (ft_memcpy(dest, src, num));
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	while (num--)
		destination[num] = source[num];
	return (dest);
}
