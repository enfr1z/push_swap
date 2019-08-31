/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:44:51 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:46:37 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_push_back(t_stack **s, t_stack *new)
{
	t_stack *last;

	if (*s == NULL)
	{
		*s = new;
		return ;
	}
	last = ft_get_last_node(*s);
	last->next = new;
}

void			ft_push_front(t_stack **s, t_stack *new)
{
	if (*s == NULL)
		*s = new;
	else
	{
		new->next = *s;
		*s = new;
	}
}

t_stack			*ft_push_back_int(t_stack **stack, int val)
{
	t_stack *new;

	if (!(new = ft_create_new_node(val)))
		return (NULL);
	ft_push_back(stack, new);
	return (*stack);
}
