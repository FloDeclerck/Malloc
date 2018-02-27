/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:11:48 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 13:20:09 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memchr(const void *b, int c, size_t len)
{
	const unsigned char		*ptr;

	ptr = b;
	while (len > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		len--;
		ptr++;
	}
	return (NULL);
}
