/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:34:46 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 11:56:25 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstp;
	const unsigned char	*srcp;

	dstp = dst;
	srcp = src;
	while (n > 0)
	{
		*dstp = *srcp;
		if (*srcp == (unsigned char)c)
			return (++dstp);
		n--;
		dstp++;
		srcp++;
	}
	return (NULL);
}
