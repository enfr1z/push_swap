/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:14:11 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/15 13:23:24 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bubble_sort(int *tab, size_t len)
{
	size_t	i;
	size_t	j;
	int		swap;

	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			swap = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = swap;
			j--;
		}
		i++;
	}
	return (*tab);
}
