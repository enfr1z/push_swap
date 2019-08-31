/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:59:46 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/06 18:46:39 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	if (ft_strchr(str, ch) == NULL)
		return (NULL);
	while (*str)
		str++;
	while (*str != ch)
		str--;
	return ((char*)str);
}
