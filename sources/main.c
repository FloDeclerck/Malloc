/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:50:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/04 10:17:03 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <stdlib.h>

void		*ft_find_block(t_block *last, long size)
{
	t_block *block;
	t_block *new;

	block = last;
	while (block->next != NULL)
	{
		if (block->next - block->last >= size)
			return (NULL);
		block = block->next;
	}
	new = block->next;
	block->next = block->last;
	block->next->last = (t_block*)(block->next + size);
	block->next->next = new;
	return (block->next + 1);
}

void		*ft_tiny(size_t size)
{
	t_block		*block;

	size += sizeof(t_block);
	block = ft_prealloc_tiny()->tiny;
	return (block);
}

int main ()
{
	int i;
	int  *p;

	i = 0;
	while (i < 1024)
	{
		p = ft_tiny(100000);
		printf("%p\n", p);
		i++;
	}
	return (0);
}
