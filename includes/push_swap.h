/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:51:03 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/15 10:27:31 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// this include will import all the prototyres from the libft project
# include "../libft/libft.h"

// here we are initializing our linked list
typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;
// those are the prototypes for the current project
int			is_sort(t_list **stack);
void		free_ab(t_list **stack);
void		simple_sort(t_list **a, t_list **b);
// static int	find_min(t_list **stack, int value);
int			swap(t_list **a_b);
int			stack_size(t_list *head);
void		index_stack(t_list a_b);
void		check_ar(int argc, char **argv);
void		get_error(char *message);
void		get_free(char **string);
int			get_length(t_list **a_b, int index);
t_list		*init_new_node(int num);
int			is_sort(t_list **s);
t_list	*stack_last(t_list *a_b);
// static int	max_bit(t_list **a_b);
void		comp_sort(t_list **a, t_list **b);
void		index_node(t_list **a_b);
//					operations
int			push(t_list **to, t_list **from);
int			pa(t_list **a, t_list **b);
int			pb(t_list **a, t_list **b);
int			swap(t_list **a_b);
int			sa(t_list **a);
int			sb(t_list **b);
int			ss(t_list **a, t_list **b);
int			rotate(t_list **a_b);
int			ra(t_list **a);
int			rb(t_list **b);
int			rr(t_list **a, t_list **b);
int			reverse_rotate(t_list **a_b);
int			rra(t_list **a);
int			rrb(t_list **b);
int			rrr(t_list **a, t_list **b);
void		add_to_llist(t_list **a_b, t_list *new);
#endif