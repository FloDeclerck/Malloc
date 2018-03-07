/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:18:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/07 16:39:27 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

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

t_block		*ft_find_block_test(t_area *a, size_t size)
{
	t_block *b;

	b = a->block;
	while (b && !(b->free && b->size >= size))
		b = b->next;
	return (b);
}

t_block		*ft_find_block(size_t size)
{
	t_area *a;
	t_block *b;

	a = base;
	b = NULL;
	while (a)
	{
		b = ft_find_block_test(a, size);
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
/*
int main()
{
	int i = 0;
	char *addr;

	while (i < 1)
	{
		addr = (char *)ft_malloc(35000);
		addr[0] = 42;
		printf("%d", *addr);
		i++;
	}
	return (0);
}*/
