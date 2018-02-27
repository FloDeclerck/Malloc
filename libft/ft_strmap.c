/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:11:04 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/10 13:24:01 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *ptr;

	if (s)
	{
		str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str)
		{
			ptr = str;
			while (*s)
				*ptr++ = f(*s++);
			*ptr = '\0';
			return (str);
		}
	}
	return (NULL);
}
