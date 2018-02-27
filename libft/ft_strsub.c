/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:11:23 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/10 16:17:17 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (s)
	{
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			ptr = str;
			while (len-- > 0 && *s != '\0')
				*ptr++ = s[start++];
			*ptr = '\0';
			return (str);
		}
		else
			return (NULL);
	}
	return (NULL);
}
