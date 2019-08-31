/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:56:16 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/11 10:33:42 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, unsigned int len)
{
	int max;

	if (!len)
		return (0);
	max = tab[0];
	while (len--)
	{
		if (tab[len] > max)
			max = tab[len];
	}
	return (max);
}
