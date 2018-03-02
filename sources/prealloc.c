/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:50:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/02 18:04:50 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <stdlib.h>

t_data *data = NULL;

size_t		ft_prealloc_tiny(size_t size)
{
	if ((TINY + BLOCK_SIZE) * 100 % getpagesize() == 0)
		size = ((TINY + BLOCK_SIZE) * 100);
	else
	{
		size = (((((TINY + BLOCK_SIZE) * 100) / getpagesize()) + 1) *
			getpagesize());
	}
	return (size);
}

t_block		ft_find_tiny(t_block *last, size_t s)
{
	t_block b;

	b = base;
	s = ft_prealloc_tiny(s);
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

	s = ft_prealloc_tiny(s);
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

	s = ft_prealloc_tiny(s);
	tmp = (t_block)(b->data + ft_prealloc_tiny(s));
	tmp->size = b->size - ft_prealloc_tiny(s) - BLOCK_SIZE;
	tmp->next = b->next;
	tmp->free = 1;
	b->size = ft_prealloc_tiny(s);
	b->next = tmp;
}

void		*ft_tiny(size_t size)
{
	t_block b, last;
	size_t		s;

	size = ft_prealloc_tiny(size);
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
