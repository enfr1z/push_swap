/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:40:03 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:46:51 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_nbr(int val_a, char *val_b)
{
	char	*cur_val;
	int		ret;

	ret = 0;
	cur_val = ft_itoa(val_a);
	if (ft_strcmp(cur_val, val_b) == 0)
		ret = 1;
	if (cur_val)
		free(cur_val);
	return (ret);
}

int	ft_check_repeat(t_stack *s, int val)
{
	while (s)
	{
		if (s->val == val)
			return (0);
		s = s->next;
	}
	return (1);
}

int	ft_is_sort_stacks(t_stacks *ss)
{
	t_stack	*a;
	int		last_val;

	if (ss->b != NULL)
		return (0);
	a = ss->a;
	last_val = a->val;
	while (a)
	{
		if (last_val > a->val)
			return (0);
		last_val = a->val;
		a = a->next;
	}
	return (1);
}
