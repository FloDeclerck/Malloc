/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/11 17:32:28 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		ft_split_tiny(t_area *a, size_t size)
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

t_area		*ft_init_tiny(t_area *last, size_t size)
{
	t_area *a;

	a = (t_area *)mmap(NULL, TINY, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
	if (a == MAP_FAILED)
		return (NULL);
	a->type = IS_TINY;
	a->size = TINY;
	a->next = NULL;
	a->prev = last;
	a->block = ft_new_block(a, size);
	ft_split_tiny(a, size);
	if (last)
		last->next = a;
	return (a);
}
