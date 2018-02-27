/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:47:21 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/12 14:54:32 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr;

	if (s1 && s2)
	{
		str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str)
		{
			ptr = str;
			while (*s1)
				*ptr++ = *s1++;
			while (*s2)
				*ptr++ = *s2++;
			*ptr = '\0';
			return (str);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
