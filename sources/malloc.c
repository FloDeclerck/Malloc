/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/02 15:49:48 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_block		ft_find_block(t_block *last, size_t size)
{
	t_block b;

	b = base;
	while (b && !(b->free && b->size >= size))
	{
		*last = b;
		b = b->next;
	}
	return (b);
}

t_block		ft_extend_heap(t_block last, size_t s)
{
	t_block b;

	b = TINY + sizeof(t_block) * 100
}


void		ft_tiny(size_t size, t_block )


void		*malloc(size_t size)
{
	if (size <= TINY)
		return (ft_tiny(size, t_data.tiny));
	else if (size <= SMALL)
		return (ft_small(size, t_data.small));
	else
		return (ft_large(size , t_data.large ));
	return (NULL);
}
