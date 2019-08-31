/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:50:03 by pdiedra           #+#    #+#             */
/*   Updated: 2019/08/31 17:06:53 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_stack
{
	int				val;
	int				i;
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*max_sort;
	int				len_a;
	int				len_b;
	int				opt_a;
	int				opt_b;
	int				opt_pl;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				print;
	int				cmds_cnt;
	int				flag_v;
}					t_stacks;

void				ft_how_much_usage_cmd(char *cmd, int cnt, t_stacks *ss);
void				ft_print_stack(t_stacks *ss);
void				ft_stack_a_min_to_top(t_stacks *ss);
void				ft_stack_b_to_a(t_stacks *ss);
void				ft_node_b_to_a(t_stacks *ss);
void				ft_stack_a_to_b(t_stacks *ss);
void				ft_norm_stack_a(t_stacks *ss);
void				ft_push_front(t_stack **s, t_stack *new);
void				ft_push_back(t_stack **s, t_stack *new);
void				ft_set_index(t_stack *s);
void				ft_put_error(t_stacks **ss, int ret);
void				ft_stack_copy_tmp_to_opt_cmd(t_stacks *ss);
void				ft_set_index(t_stack *s);

int					ft_cmd_apply_p(t_stack **from, t_stack **to);
int					ft_cmd_apply_rr(t_stack **s);
int					ft_cmd_apply_r(t_stack **s);
int					ft_cmd_apply_s(t_stack **s);
int					ft_get_node_place_i(t_stack *s, int val);
int					ft_node_iter_to_up(int st_len, int node_i);
int					ft_get_count_nodes(t_stack *s);
int					ft_stacks_free(t_stacks **ss, int ret);
int					ft_set_tmp_cmd(t_stacks *ss, t_stack *b);
int					ft_is_valid_nbr(int val_a, char *val_b);
int					ft_check_repeat(t_stack *s, int val);
int					ft_node_b_to_a_count(int a, int b, int place_b);
int					ft_is_sort_stacks(t_stacks *ss);

t_stack				*ft_pop_front(t_stack **s);
t_stack				*ft_pop_back(t_stack **s);
t_stack				*ft_push_back_int(t_stack **stack, int val);
t_stack				*ft_get_max_sort(t_stack *s);
t_stack				*ft_create_new_node(int val);
t_stack				*ft_get_last_node(t_stack *s);

t_stacks			*ft_create_stacks(int ac, char **av);

#endif
