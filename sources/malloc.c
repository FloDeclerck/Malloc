/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/04 17:40:49 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block		*ft_find_block(t_area *a, size_t size)
{
	t_block *b;

	b = a->block;
	while (b && !(b->free && b->size >= size))
		b = b->next;
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
	b->next = new;
}


void		*ft_tiny(size_t size)
{
	t_area *a;
	t_block *b;

	size = ALIGN4(size);
	if (base)
	{
		a = base;
		b = ft_find_block(a, size);
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
			if (!(a->next = ft_init_area(a, size)))
				return (NULL);
			b = a->next->block;
		}
		return (b->data);
	}
	if (!(a = ft_init_area(NULL, size)))
		return (NULL);
	base = a;
	b = a->block;
	return (b->data);
}

int main()
{
	int i = 0;
	char *addr;

	while (i < 1)
	{
		addr = (char*)ft_test(3000);
		addr[0] = 4;
		printf("%d", *addr);
		i++;
	}
	return (0);
}
