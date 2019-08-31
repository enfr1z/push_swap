/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:19:09 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/12 18:41:26 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j] && j < n)
		j++;
	while (src[i] && (i + j + 1) < n)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (i + j < n)
		dest[i + j] = '\0';
	return (j + ft_strlen((char*)src));
}
