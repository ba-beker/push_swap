/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:17 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/25 19:39:45 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	commands(char *instraction, t_list **a, t_list **b)
{
	if (!(ft_strcmp(instraction, "sa"))
		|| !(ft_strcmp(instraction, "sb"))
		|| !(ft_strcmp(instraction, "ss")))
		return (sabs(instraction, a, b));
	if (!(ft_strcmp(instraction, "pa"))
		|| !(ft_strcmp(instraction, "pb")))
		return (pab(instraction, a, b));
	if (!(ft_strcmp(instraction, "ra"))
		|| !(ft_strcmp(instraction, "rb"))
		|| !(ft_strcmp(instraction, "rr")))
		return (rabr(instraction, a, b));
	if (!(ft_strcmp(instraction, "rra"))
		|| !(ft_strcmp(instraction, "rrb"))
		|| !(ft_strcmp(instraction, "rrr")))
		return (rrabr(instraction, a, b));
	return (1);
}

void	output_result(t_list **a, t_list **b)
{
	if (is_sort(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (*a)
		free_ab(a);
	if (*b)
		free_ab(b);
}

static void	init_llist(t_list **a_b, int argc, char **argv)
{
	t_list	*temp;
	char	**arg;
	int		i;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		arg = argv;
		i = 1;
	}
	while (arg[i])
	{
		temp = init_new_node(ft_atoi(arg[i]));
		add_to_llist(a_b, temp);
		i++;
	}
	index_node(a_b);
	if (argc == 2)
		get_free(arg);
}

int	main_part(char	*l, t_list **a, t_list **b)
{
	while (1)
	{
		l = get_next_line(0);
		if (l == NULL)
			break ;
		if (commands(l, a, b))
		{
			get_error("Error");
			return (-1);
		}
		free(l);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	*l;

	if (argc < 2)
		return (0);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	l = NULL;
	check_ar(argc, argv);
	init_llist(a, argc, argv);
	main_part(l, a, b);
	output_result(a, b);
	return (0);
}
