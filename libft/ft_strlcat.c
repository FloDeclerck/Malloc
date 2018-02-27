/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:13:46 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/16 18:57:04 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t destl;
	size_t srcl;
	size_t len;

	destl = ft_strlen(dest);
	srcl = ft_strlen(src);
	if (size < destl)
		len = size + srcl;
	else
		len = destl + srcl;
	dest = dest + destl;
	destl += 1;
	while (destl < size && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		destl++;
	}
	*dest = '\0';
	return (len);
}
