/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:29:08 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 17:05:19 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_free(t_stack **s)
{
	t_stack *next;

	while (*s)
	{
		next = (*s)->next;
		free(*s);
		*s = next;
	}
}

int			ft_stacks_free(t_stacks **ss, int ret)
{
	if (*ss && (*ss)->a)
		ft_stack_free(&(*ss)->a);
	if (*ss && (*ss)->b)
		ft_stack_free(&(*ss)->b);
	if (*ss)
		free(*ss);
	return (ret);
}

int			ft_set_tmp_cmd(t_stacks *ss, t_stack *b)
{
	ss->tmp_pl = ft_get_node_place_i(ss->a, b->val);
	ss->tmp_b = ft_node_iter_to_up(ss->len_b, b->i);
	ss->tmp_a = ft_node_iter_to_up(ss->len_a, ss->tmp_pl);
	return (ft_node_b_to_a_count(ss->tmp_a, ss->tmp_b, ss->tmp_pl));
}

void		ft_put_error(t_stacks **ss, int ret)
{
	ft_putendl("Error");
	ft_stacks_free(ss, ret);
	exit(ret);
}

void		ft_stack_copy_tmp_to_opt_cmd(t_stacks *ss)
{
	ss->opt_pl = ss->tmp_pl;
	ss->opt_b = ss->tmp_b;
	ss->opt_a = ss->tmp_a;
}
