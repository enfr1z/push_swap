/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:33:42 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 16:26:03 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stacks	*ss;
	char		*cur_com;

	cur_com = NULL;
	ss = ft_create_stacks(ac, av);
	ss->print = 0;
	if (ss->a == NULL)
		exit(ft_stacks_free(&ss, 0));
	while (get_next_line(0, &cur_com))
	{
		ft_how_much_usage_cmd(cur_com, 1, ss);
		if (cur_com)
			free(cur_com);
	}
	if (ft_is_sort_stacks(ss))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (ft_stacks_free(&ss, 0));
}
