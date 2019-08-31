/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:01:02 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:47:06 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_norm_stack_a(t_stacks *ss)
{
	int com;

	ft_set_index(ss->a);
	ss->max_sort = ft_get_max_sort(ss->a);
	ss->len_a = ft_get_count_nodes(ss->a);
	com = ss->len_a - ss->max_sort->i - ss->max_sort->sort > 0 ?
		ss->len_a - (ss->len_a - ss->max_sort->i - ss->max_sort->sort) :
		ft_abs(ss->len_a - ss->max_sort->i - ss->max_sort->sort);
	com = ft_node_iter_to_up(ss->len_a, com);
	ft_how_much_usage_cmd(com > 0 ? "ra" : "rra", com, ss);
}

void	ft_stack_a_to_b(t_stacks *ss)
{
	t_stack *a;

	a = ss->a;
	while (a && a->i != ss->max_sort->i)
	{
		a = a->next;
		ft_how_much_usage_cmd("pb", 1, ss);
	}
}

void	ft_node_b_to_a(t_stacks *ss)
{
	ss->tmp_b = ft_abs(ss->opt_b);
	ss->tmp_a = ft_abs(ss->opt_a);
	while (((ss->opt_b > 0 && ss->opt_a > 0) || (ss->opt_b < 0 &&
			ss->opt_a < 0)) && ss->tmp_b && ss->tmp_a && ss->opt_pl != -1)
	{
		ft_how_much_usage_cmd(ss->opt_b > 0 ? "rr" : "rrr", 1, ss);
		ss->tmp_b--;
		ss->tmp_a--;
	}
	ft_how_much_usage_cmd(ss->opt_b > 0 ? "rb" : "rrb", ss->tmp_b, ss);
	if (ss->opt_pl != -1)
		ft_how_much_usage_cmd(ss->opt_a > 0 ? "ra" : "rra", ss->tmp_a, ss);
	ft_how_much_usage_cmd("pa", 1, ss);
	if (ss->opt_pl == -1)
		ft_how_much_usage_cmd("ra", 1, ss);
}

void	ft_stack_b_to_a(t_stacks *ss)
{
	t_stack	*b;
	int		min_cmd;
	int		cmd;

	while (ss->b)
	{
		b = ss->b;
		ft_set_index(ss->a);
		ft_set_index(ss->b);
		ss->len_a = ft_get_count_nodes(ss->a);
		ss->len_b = ft_get_count_nodes(ss->b);
		min_cmd = ft_set_tmp_cmd(ss, b);
		ft_stack_copy_tmp_to_opt_cmd(ss);
		while (b)
		{
			cmd = ft_set_tmp_cmd(ss, b);
			if (min_cmd > cmd)
			{
				min_cmd = cmd;
				ft_stack_copy_tmp_to_opt_cmd(ss);
			}
			b = b->next;
		}
		ft_node_b_to_a(ss);
	}
}

void	ft_stack_a_min_to_top(t_stacks *ss)
{
	t_stack	*a;
	t_stack	*min_node;
	int		iter_to_up;

	a = ss->a;
	min_node = a;
	while (a)
	{
		min_node = a->val < min_node->val ? a : min_node;
		a = a->next;
	}
	ss->len_a = ft_get_count_nodes(ss->a);
	ft_set_index(ss->a);
	iter_to_up = ft_node_iter_to_up(ss->len_a, min_node->i);
	ft_how_much_usage_cmd(iter_to_up > 0 ? "ra" : "rra", iter_to_up, ss);
}
