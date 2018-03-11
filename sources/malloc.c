/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:50:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/11 17:31:34 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*g_base = NULL;

int			ft_block_type(size_t size)
{
	if (size <= TINY_MAX)
		return (IS_TINY);
	if (size <= SMALL_MAX)
		return (IS_SMALL);
	return (IS_LARGE);
}

void		*ft_malloc_reducer(size_t size)
{
	t_block *b;

	b = ft_find_block(size);
	if ((b->size - size) >= (BLOCK_SIZE + 4))
		ft_split_block(b, size);
	b->free = 0;
	return (b);
}

void		*ft_malloc(size_t size)
{
	t_area	*a;
	t_block	*b;

	if (g_base)
	{
		a = g_base;
		b = ft_find_block(size);
		if (b)
			ft_malloc_reducer(size);
		else
		{
			while (a->next)
				a = a->next;
			if (!(a->next = ft_init_next(a, size)))
				return (NULL);
			b = a->next->block;
		}
		return (b->data);
	}
	if (!(a = ft_init_all(NULL, size)))
		return (NULL);
	g_base = a;
	b = a->block;
	return (b->data);
}
