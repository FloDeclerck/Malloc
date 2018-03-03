/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:50:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/03 10:21:42 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <stdlib.h>

t_data *data = NULL;

t_block		ft_find_tiny(t_block *last, size_t s)
{
	t_block b;

	b = base;
	if (s <= TINY)
		s = ft_prealloc_tiny(s);
	else if (s <= SMALL)
		s = ft_prealloc_small(s);
	while (b && !(b->free && b->size >= s))
	{
		*last = b;
		b = b->next;
	}
	return (b);
}

t_block		ft_extend_tiny(t_block last, size_t s)
{
	t_block b;

	if (s <= TINY)
		s = ft_prealloc_tiny(s);
	else if (s <= SMALL)
		s = ft_prealloc_small(s);
	b = mmap(NULL, s, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE, -1, 0);
	if (b == MAP_FAILED)
		return (NULL);
	b->size = s;
	b->next = NULL;
	if (last)
		last->next = b;
	b->free = 0;
	return (b);
}

void		ft_tiny_split(t_block b, size_t s)
{
	t_block tmp;

	if (s <= TINY)
		s = ft_prealloc_tiny(s);
	else if (s <= SMALL)
		s = ft_prealloc_small(s);
	tmp = (t_block)(b->data + s);
	tmp->size = b->size - s - BLOCK_SIZE;
	tmp->next = b->next;
	tmp->free = 1;
	b->size = s;
	b->next = tmp;
}

void		*ft_tiny(size_t size)
{
	t_block b, last;
	size_t		s;

	if (s <= TINY)
		size = ft_prealloc_tiny(size);
	else if (s <= SMALL)
		size = ft_prealloc_small(size);
	s = align4(size);
	if (base)
	{
		last = base;
		b = ft_find_tiny(&last, s);
		if (b)
		{
			if ((b->size - s) >= BLOCK_SIZE + 4)
				ft_tiny_split(b, s);
			b->free = 0;
		}
		else
		{
			b = ft_extend_tiny(last, s);
			if (!b)
				return (NULL);
		}
	}
	else
	{
		b = ft_extend_tiny(NULL, s);
		if (!b)
			return (NULL);
		base = b;
	}
	return (b->data);
}

int main ()
{
	int i;
	char *addr;

	i = 0;
	while (i < 10000)
	{
		addr = (char*)ft_tiny(10000);
		addr[0] = 42;
		printf("%d\n", *addr);
		free(addr);
		i++;
	}
	return (0);
}
