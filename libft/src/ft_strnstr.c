/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:35:37 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/12 18:42:21 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len;
	char	*str1;
	char	*to_find1;

	str1 = (char*)str;
	to_find1 = (char*)to_find;
	len = ft_strlen((char*)to_find1);
	if (*to_find1 == '\0')
		return (str1);
	while (*str1 != '\0' && n-- >= len)
	{
		if (*str1 == *to_find1 && ft_memcmp(str1, to_find1, len) == 0)
			return (str1);
		str1++;
	}
	return (NULL);
}
