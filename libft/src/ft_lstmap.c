/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:09:31 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/17 10:56:41 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lst_del(t_list *lst)
{
	t_list	*next;

	if (lst)
	{
		while (lst)
		{
			next = lst->next;
			if (lst->content)
				free(lst->content);
			if (lst->next)
				free(lst->next);
			lst = next;
		}
		free(lst);
		lst = NULL;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*elem;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem = f(lst);
	first = elem;
	tmp = lst->next;
	while (tmp != NULL)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return (ft_lst_del(first));
		new = f(tmp);
		tmp = tmp->next;
		elem->next = new;
		elem = elem->next;
		new = NULL;
	}
	return (first);
}
