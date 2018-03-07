/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 09:10:41 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/07 16:23:58 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		ft_split_large(t_area *a, size_t size)
{
	t_block *new;
	new = (void *)a->block->data + size;
	new->size = (size + BLOCK_SIZE + AREA_SIZE) - size - BLOCK_SIZE;
	new->next = NULL;
	new->prev = a->block;
	new->free = 1;
	new->ptr = a->block->data + size;
	new->area = a;
	a->block->next = new;
}

t_area		*ft_init_large(t_area *last, size_t size)
{
	t_area *a;

	a = (t_area *)mmap(0, size + BLOCK_SIZE + AREA_SIZE, PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (a == MAP_FAILED)
		return (NULL);
	a->type = IS_LARGE;
	a->size = size + BLOCK_SIZE + AREA_SIZE;
	a->next = NULL;
	a->prev = last;
	a->block = ft_new_block(a, size);
	if (last)
		last->next = a;
	return (a);
}

void		*ft_large(size_t size)
{
	t_area *a;
	t_block *b;

	size = ALIGN4(size);
	if (base)
	{
		a = base;
		b = ft_find_block(size);
		if (b)
		{
			if ((b->size - size) >= (BLOCK_SIZE + 4))
				ft_split_block(b, size);
			b->free = 0;
		}
		else
		{
			while (a->next)
				a = a->next;
			a = ft_init_large(a, size);
			if (!a)
				return (NULL);
			b = a->next->block;
		}
		return (b->data);
	}
	a = ft_init_large(NULL, size);
	if (!a)
		return (NULL);
	base = a;
	b = a->block;
	return (b->data);
}
