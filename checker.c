/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:17 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/23 10:55:09 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int commands(char *instraction, t_list **a, t_list **b)
{
	if (!(ft_strcmp(instraction, "sa")))
	{
		swap(a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "sb")))
	{
		swap(b);
		return (0);
	}	
	if (!(ft_strcmp(instraction, "ss")))
	{
		swap(a);
		swap(b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "pa")))
	{
		push(a, b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "pb")))
	{
		push(b, a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "ra")))
	{
		rotate(a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "ra")))
	{
		rotate(a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rb")))
	{
		rotate(b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rr")))
	{
		rotate(a);
		rotate(b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rra")))
	{
		reverse_rotate(a);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rrb")))
	{
		reverse_rotate(b);
		return (0);
	}
	if (!(ft_strcmp(instraction, "rrr")))
	{
		reverse_rotate(a);
		reverse_rotate(b);
		return (0);
	}
	return (1);
}
void	output_result(t_list **a, t_list **b)
{
	if (is_sort(a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*a)
		free_ab(a);
	if (*b)
		free_ab(b);
}
static void init_llist(t_list **a_b, int argc, char **argv)
{
	t_list	*temp;
	char	**arg;
	int		i;

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
int main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	*l;
	
	if (argc < 2)
		return (-1);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	check_ar(argc, argv);
	init_llist(a, argc, argv);
	while (1)
	{
		l = get_next_line(0);
		
		if (l == 0)
			break;
		if (commands(l, a, b))
		{
			get_error("Error");
			return (-1);
		}
		free(l);
	}
	output_result(a, b);
}