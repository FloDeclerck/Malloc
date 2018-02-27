/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:48:29 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/12 19:45:38 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && n-- > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}
