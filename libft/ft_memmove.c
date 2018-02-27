/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:40:40 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 12:15:32 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dstp;

	dstp = dst;
	if (dst > src)
		while (len > 0)
		{
			len--;
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
		}
	else if (dst < src)
		while (len > 0)
		{
			len--;
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst++;
			src++;
		}
	return (dstp);
}
