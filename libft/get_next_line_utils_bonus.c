/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:36:37 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/25 20:55:25 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*new_line(const char *str, int c)
{
	while (*str && *str != (unsigned char)c)
		str++;
	if (*str == (unsigned char)c)
		return ((char *) str);
	return (0);
}
