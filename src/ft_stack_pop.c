/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:53:37 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:46:33 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*ft_pop_front(t_stack **s)
{
	t_stack *tmp;

	if (*s == NULL)
		return (NULL);
	tmp = *s;
	if ((*s)->next == NULL)
		*s = NULL;
	else
		*s = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack			*ft_pop_back(t_stack **s)
{
	t_stack *last;
	t_stack *tmp;

	last = *s;
	tmp = *s;
	if (*s == NULL)
		return (NULL);
	if ((*s)->next == NULL)
		*s = NULL;
	else
	{
		while (last->next && last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
	}
	return (tmp);
}
