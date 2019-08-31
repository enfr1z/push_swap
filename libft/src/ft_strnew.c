/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:51:22 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/17 10:58:03 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;

	if (size == ((size_t)-1))
		return (NULL);
	newstr = (char*)malloc(sizeof(char) * size + 1);
	if (newstr == NULL)
		return (NULL);
	ft_memset(newstr, (int)'\0', size + 1);
	return (newstr);
}
