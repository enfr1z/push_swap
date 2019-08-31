/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:15:54 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:46:20 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cmd_apply_s(t_stack **s)
{
	if (*s && (*s)->next)
	{
		ft_swap(&(*s)->val, &(*s)->next->val);
		return (1);
	}
	return (-1);
}

int	ft_cmd_apply_r(t_stack **s)
{
	if (*s && (*s)->next)
	{
		ft_push_back(s, ft_pop_front(s));
		return (1);
	}
	return (-1);
}

int	ft_cmd_apply_rr(t_stack **s)
{
	if (*s && (*s)->next)
	{
		ft_push_front(s, ft_pop_back(s));
		return (1);
	}
	return (-1);
}

int	ft_cmd_apply_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ft_push_front(to, ft_pop_front(from));
		return (1);
	}
	return (-1);
}
