/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:10:56 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 16:25:33 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cmd_apply(char *cmd, t_stacks *ss)
{
	int len;
	int ret;

	len = ft_strlen(cmd);
	ret = 0;
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'a'))
		ret = ft_cmd_apply_s(&ss->a);
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'b'))
		ret = ft_cmd_apply_s(&ss->b);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'a')
		ret = ft_cmd_apply_p(&ss->b, &ss->a);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'b')
		ret = ft_cmd_apply_p(&ss->a, &ss->b);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'a'))
		ret = ft_cmd_apply_r(&ss->a);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'b'))
		ret = ft_cmd_apply_r(&ss->b);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' &&
		(cmd[2] == 'r' || cmd[2] == 'a'))
		ret = ft_cmd_apply_rr(&ss->a);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' &&
		(cmd[2] == 'r' || cmd[2] == 'b'))
		ret = ft_cmd_apply_rr(&ss->b);
	return (ret == 0 ? 0 : 1);
}

static void	ft_print_val(t_stack *s, int flag)
{
	ft_putstr(flag == 0 ? "  " : "   ");
	ft_putnbr(s->val);
}

void		ft_print_stack(t_stacks *ss)
{
	t_stack *a;
	t_stack *b;

	a = ss->a;
	b = ss->b;
	ft_putstr("Stack A | Stack B\n");
	while (a || b)
	{
		if (a)
			ft_print_val(a, 0);
		else
			ft_putstr(" -");
		ft_putstr(" | ");
		if (b)
			ft_print_val(b, 1);
		else
			ft_putstr("   -");
		ft_putchar('\n');
		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
	}
	ft_putchar('\n');
}

void		ft_how_much_usage_cmd(char *cmd, int cnt, t_stacks *ss)
{
	int i;

	i = ft_abs(cnt);
	while (i)
	{
		if (ft_cmd_apply(cmd, ss))
		{
			if (ss->print == 1)
				ft_putendl(cmd);
			if (ss->print == 0 && ss->flag_v == 1)
				ft_print_stack(ss);
			ss->cmds_cnt++;
		}
		else
			ft_put_error(&ss, 0);
		i--;
	}
}
