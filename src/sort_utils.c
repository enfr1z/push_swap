/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:01:53 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:46:40 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_set_index(t_stack *s)
{
	int i;

	i = 0;
	while (s)
	{
		s->i = i++;
		s = s->next;
	}
}

int			ft_node_iter_to_up(int st_len, int node_i)
{
	if (st_len / 2 >= node_i)
		return (node_i);
	else
		return ((st_len - node_i) * -1);
}

int			ft_node_b_to_a_count(int a, int b, int place_b)
{
	if (a > 0 && b > 0 && place_b != -1)
		return (a > b ? a : b);
	if (a < 0 && b < 0 && place_b != -1)
		return (ft_abs(a) > ft_abs(b) ? ft_abs(a) : ft_abs(b));
	else
		return (ft_abs(a) + ft_abs(b));
}

int			ft_get_node_place_i(t_stack *s, int val)
{
	t_stack	*optim;
	int		last_min;

	optim = NULL;
	last_min = 0;
	while (s)
	{
		if ((last_min == 0) || (last_min < 0 && s->val - val < 0 &&
			s->val - val > last_min) ||
			(last_min > 0 && s->val - val < last_min))
		{
			last_min = s->val - val;
			optim = s;
		}
		if (s->next == NULL)
			break ;
		s = s->next;
	}
	if (optim == s && last_min < 0)
		return (-1);
	return (last_min < 0 ? optim->i + 1 : optim->i);
}

t_stack		*ft_get_max_sort(t_stack *s)
{
	t_stack *tmp;
	t_stack	*first;
	t_stack *max;
	int		nodes;
	int		i;

	first = s;
	max = s;
	nodes = ft_get_count_nodes(s);
	while (s)
	{
		tmp = s;
		i = 0;
		while (i < nodes)
		{
			if ((tmp->next == NULL ? first : tmp->next)->val < tmp->val)
				break ;
			s->sort++;
			i++;
			tmp = tmp->next == NULL ? first : tmp->next;
		}
		max = s->sort >= max->sort ? s : max;
		s = s->next;
	}
	return (max);
}
