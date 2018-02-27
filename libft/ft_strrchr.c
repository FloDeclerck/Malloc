/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:58:14 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 15:15:57 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (c == *str)
		{
			s = (char*)str;
			i = 1;
		}
		str++;
	}
	if (i > 0)
		return (s);
	if (c == '\0')
		return ((char*)str);
	else
		return (NULL);
}
