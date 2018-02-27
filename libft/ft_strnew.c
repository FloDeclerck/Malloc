/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:29:14 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/10 11:54:57 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc(size + 1);
	if (str)
	{
		ft_bzero(str, (size + 1));
		return (str);
	}
	else
		return (NULL);
}
