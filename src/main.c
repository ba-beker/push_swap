/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:01:54 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/25 19:42:55 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	sort_stack(t_list **a, t_list **b)
{
	if (stack_size(*a) <= 5)
		simple_sort(a, b);
	else
		comp_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (-1);
	check_ar(argc, argv);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	init_llist(a, argc, argv);
	if (is_sort(a))
	{
		free_ab(b);
		free_ab(a);
		return (0);
	}
	sort_stack(a, b);
	free_ab(a);
	free_ab(b);
	return (0);
}
