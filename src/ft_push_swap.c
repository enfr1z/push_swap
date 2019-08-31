/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:25:48 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:46:27 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three_elem(t_stacks *ss)
{
	if (ss->a->val > ss->a->next->val &&
		ss->a->val < ss->a->next->next->val)
		ft_how_much_usage_cmd("sa", 1, ss);
	else if (ss->a->val > ss->a->next->next->val)
		ft_how_much_usage_cmd("ra", 1, ss);
}

static void	ft_sort_five_elem(t_stacks *ss)
{
	if (ss->max_sort->sort < 3)
	{
		ft_how_much_usage_cmd("pb", 2, ss);
		ft_sort_three_elem(ss);
	}
	else
		ft_stack_a_to_b(ss);
	ft_stack_b_to_a(ss);
	ft_stack_a_min_to_top(ss);
}

static void	ft_main_sort(t_stacks *ss)
{
	ft_stack_a_to_b(ss);
	ft_stack_b_to_a(ss);
	ft_stack_a_min_to_top(ss);
}

int			main(int ac, char **av)
{
	t_stacks *ss;

	ss = ft_create_stacks(ac, av);
	if (ss->a == NULL)
		exit(ft_stacks_free(&ss, 0));
	ss->print = 1;
	ss->len_a = ft_get_count_nodes(ss->a);
	ft_norm_stack_a(ss);
	if (ss->len_a == 3)
		ft_sort_three_elem(ss);
	else if (ss->len_a == 5)
		ft_sort_five_elem(ss);
	else
		ft_main_sort(ss);
	return (ft_stacks_free(&ss, 0));
}
