/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:04:48 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/10 16:30:49 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t	i;

	if (!dest && !source)
		return (NULL);
	i = 0;
	if (source < dest)
		while (++i <= n)
			((unsigned char*)dest)[n - i] = ((unsigned char*)source)[n - i];
	else
		ft_memcpy(dest, source, n);
	return (dest);
}
