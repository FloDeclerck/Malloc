/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 10:11:41 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/03 10:17:50 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t		ft_prealloc_tiny(size_t size)
{
	if ((TINY + BLOCK_SIZE) * 100 % getpagesize() == 0)
		size = ((TINY + BLOCK_SIZE) * 100);
	else
	{
		size = (((((TINY + BLOCK_SIZE) * 100) / getpagesize()) + 1) *
				getpagesize());
	}
	return (size);
}

size_t		ft_prealloc_small(size_t size)
{
	if ((SMALL + BLOCK_SIZE) * 100 % getpagesize() == 0)
		size = ((SMALL + BLOCK_SIZE) * 100);
	else
	{
		size = (((((SMALL + BLOCK_SIZE) * 100) / getpagesize()) + 1) *
				getpagesize());
	}
	return (size);
}
