/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:49:14 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/17 10:54:31 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *str, size_t size)
{
	char *newstr;

	if (!size && str)
	{
		if (!(newstr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&str);
		return (newstr);
	}
	if (!(newstr = (char *)malloc(size)))
		return (NULL);
	if (str)
	{
		ft_memcpy(newstr, str, size);
		ft_memdel(&str);
	}
	return (newstr);
}
