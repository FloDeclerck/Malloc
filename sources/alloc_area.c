/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:18:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/04 17:40:03 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block		*ft_init_block(t_area *a, size_t size)
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

void		ft_split_area(t_area *a, size_t size)
{
	t_block *new;

	new = (void *)a->block->data + size;
	new->size = (TINY - BLOCK_SIZE - AREA_SIZE) - size - BLOCK_SIZE;
	new->next = NULL;
	new->prev = a->block;
	new->free = 1;
	new->ptr = a->block->data + size;
	new->area = a;
	a->block->next = new;
}

t_area		*ft_init_area(t_area *last, size_t size)
{
	t_area *a;

	a = (t_area *)mmap(NULL, TINY, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
	if (a == MAP_FAILED)
		return (NULL);
	a->size = size;
	a->next = NULL;
	a->prev = last;
	a->block = ft_init_block(a, size);
	ft_split_area(a, size);
	if (last)
		last->next = a;
	a->free = 0;
	return (a);
}

void		*ft_test(size_t size)
{
	t_area *a = NULL;
	t_area *last;

	size = ALIGN4(size);
	if (base)
	{
		last = base;
		ft_find_block(last, size);
		if (a)
		{
			if ((a->size - size) >= (BLOCK_SIZE + 4))
				ft_split_area(a, size);
			a->free = 0;
		}
		else
		{
			a = ft_init_area(last, size);
			if (!a)
				return (NULL);
		}
	}
	else
	{
		a = ft_init_area(NULL, size);
		if (!a)
			return (NULL);
		base = a;
	}
	return (a->data);
}
