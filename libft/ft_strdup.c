/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:46:32 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 13:46:00 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*dup;
	char	*ptd;
	int		len;

	len = ft_strlen(str);
	dup = (char*)malloc(sizeof(char) * (len + 1));
	ptd = dup;
	if (dup != NULL)
	{
		while (*str)
			*ptd++ = *str++;
		*ptd = '\0';
		return (dup);
	}
	else
		return (NULL);
}
