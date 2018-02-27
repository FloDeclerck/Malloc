/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:59:19 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 11:39:37 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;

	ptr = dst;
	while (len--)
		*(unsigned char*)dst++ = *(unsigned char const*)src++;
	return (ptr);
}
