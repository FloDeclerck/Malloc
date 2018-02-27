/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:41:22 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 14:42:38 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*tmp;

	tmp = dst;
	while (*src != '\0' && n > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dst = '\0';
		dst++;
		n--;
	}
	return (tmp);
}
