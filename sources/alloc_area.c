/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:18:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/13 14:13:34 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_area		*ft_init_next(t_area *a, size_t size)
{
	if (size <= TINY_MAX)
		a->next = ft_init_tiny(a, size);
	else if (size <= SMALL_MAX)
		a->next = ft_init_small(a, size);
	else
		a->next = ft_init_large(a, size);
	return (a->next);
}

t_area		*ft_init_all(t_area *a, size_t size)
{
	if (size <= TINY_MAX)
		a = ft_init_tiny(a, size);
	else if (size <= SMALL_MAX)
		a = ft_init_small(a, size);
	else
		a = ft_init_large(a, size);
	return (a);
}

t_block		*ft_new_block(t_area *a, size_t size)
{
	t_block *b;

	b = (void *)a + AREA_SIZE;
	b->size = size;
	b->next = NULL;
	b->prev = NULL;
	b->free = 0;
	b->ptr = a + AREA_SIZE;
	b->area = a;
	return (b);
}

t_block		*ft_find_block(size_t size)
{
	t_area	*a;
	t_block *b;

	a = g_base;
	b = NULL;
	while (a)
	{
		if (ft_block_type(size) == a->type)
		{
			b = a->block;
			while (b && !(b->free && b->size >= size))
				b = b->next;
		}
		if (b)
			return (b);
		a = a->next;
	}
	return (b);
}

void		ft_split_block(t_block *b, size_t size)
{
	t_block *new;

	new = (void *)b->data + size;
	new->size = b->size - size - BLOCK_SIZE;
	new->next = b->next;
	new->prev = b;
	new->free = 1;
	new->ptr = b->data + size;
	new->area = b->area;
	b->size = size;
	b->next = new;
}
