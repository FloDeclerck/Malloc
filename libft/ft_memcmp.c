/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:20:43 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 13:31:01 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *str1p;
	const unsigned char *str2p;

	str1p = str1;
	str2p = str2;
	if (n == 0)
		return (0);
	while (n > 1 && *str1p == *str2p)
	{
		str1p++;
		str2p++;
		n--;
	}
	return (*str1p - *str2p);
}
