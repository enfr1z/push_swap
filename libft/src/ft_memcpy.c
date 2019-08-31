/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:13:21 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/10 15:57:54 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char *to_dest;
	char *from_source;

	if (!dest && !source)
		return (NULL);
	to_dest = dest;
	from_source = (char*)source;
	while (n)
	{
		*to_dest = *from_source;
		to_dest++;
		from_source++;
		n--;
	}
	return (dest);
}
