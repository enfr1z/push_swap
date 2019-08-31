/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:27:57 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 15:46:44 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_create_stack_a(int ac, char **av, t_stacks *ss)
{
	int i;
	int cur_val;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (ft_strcmp(av[i], "-v") == 0)
			ss->flag_v = 1;
		else
		{
			cur_val = ft_atoi(av[i]);
			if (ft_is_valid_nbr(cur_val, av[i]) == 0 ||
				ft_check_repeat(ss->a, cur_val) == 0)
				ft_put_error(&ss, ft_free_array(ac == 2 ? av : NULL, 1));
			if ((ft_push_back_int(&ss->a, cur_val)) == NULL)
				ft_put_error(&ss, ft_free_array(ac == 2 ? av : NULL, 1));
		}
		i++;
	}
	ft_free_array(ac == 2 ? av : NULL, 1);
}

int				ft_get_count_nodes(t_stack *s)
{
	int	count;

	count = 0;
	while (s)
	{
		s = s->next;
		count++;
	}
	return (count);
}

t_stack			*ft_create_new_node(int val)
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack			*ft_get_last_node(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

t_stacks		*ft_create_stacks(int ac, char **av)
{
	t_stacks *ss;

	if (!(ss = (t_stacks*)malloc(sizeof(t_stacks))))
		ft_put_error(&ss, 1);
	ss->a = NULL;
	ss->b = NULL;
	ss->flag_v = 0;
	ss->cmds_cnt = 0;
	ss->print = 0;
	ft_create_stack_a(ac, av, ss);
	return (ss);
}
