/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:21:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/09 13:19:37 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*ft_alloc_area(t_block *base, long size)
{
	t_block *b = NULL;
	t_block *new;

	b = base;
	while (b->next != NULL)
	{
		if (b->next - b->max >= size)
			break;
		b = b->next;
	}
	new = b->next;
	b->next = b->max;
	b->next->max = (t_block *)(b->next + size);
	b->next->next = new;
	return (b->next + 1);
}

void		*ft_malloc(size_t size)
{
	t_block *b = NULL;

	b += BLOCK_SIZE;
	if (size <= TINY)
		return (ft_alloc_area(ft_prealloc_tiny()->tiny, size));
	if (size <= SMALL)
		return (ft_alloc_area(ft_prealloc_small()->small, size));
	b = ft_prealloc_large()->large;
	while (b->next != NULL)
		b = b->next;
	b->next = mmap(NULL, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	b->next->max = (t_block *)(b->next + size);
	b->next->next = NULL;
	return (b->next + 1);
}
