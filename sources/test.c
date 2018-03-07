/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:18:47 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/07 16:36:17 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"


void *base = NULL;

size_t		get_page_size(size_t s)
{
	if (s <= TINY_MAX)
		return (TINY);
	if (s <= SMALL_MAX)
		return (SMALL);
	return (s + BLOCK_SIZE + AREA_SIZE);
}

int			get_page_type(size_t s)
{
	if (s <= TINY_MAX)
		return (IS_TINY);
	if (s <= SMALL_MAX)
		return (IS_SMALL);
	return (IS_LARGE);
}

t_block		*add_new_block(t_area *a, size_t s)
{
	t_block		*b;

	b = (void *)a + AREA_SIZE;
	b->size = s;
	b->next = NULL;
	b->prev = NULL;
	b->free = 0;
	b->ptr = a + AREA_SIZE;
	b->area = a;
	return (b);
}

void		split_new_page(t_area *a, size_t s, size_t alloc_size)
{
	t_block		*new;

	new = (void *)a->block->data + s;
	new->size = alloc_size - s - BLOCK_SIZE;
	new->next = NULL;
	new->prev = a->block;
	new->free = 1;
	new->ptr = a->block->data + s;
	new->area = a;
	a->block->next = new;
}

t_area		*add_new_page(t_area *last, size_t s)
{
	t_area		*a;
	size_t		alloc_size;

	alloc_size = get_page_size(s);
	if ((a = (t_area *)mmap(0, alloc_size,
		PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	a->type = get_page_type(s);
	a->size = alloc_size;
	a->next = NULL;
	a->prev = last;
	a->block = add_new_block(a, s);
	if (a->type < 2)
		split_new_page(a, s, alloc_size - BLOCK_SIZE - AREA_SIZE);
	if (last)
		last->next = a;
	return (a);
}


void		split_block(t_block *b, size_t s)
{
	t_block	*new;

	new = (void *)b->data + s;
	new->size = b->size - s - BLOCK_SIZE;
	new->next = b->next;
	new->prev = b;
	new->free = 1;
	new->ptr = b->data + s;
	new->area = b->area;
	b->size = s;
	b->next = new;
}

t_block		*find_block_in_page(t_area *p, size_t size)
{
	t_block	*b;

	b = p->block;
	while (b && !(b->free && b->size >= size))
		b = b->next;
	return (b);
}

t_block		*find_block(size_t s)
{
	t_area	*a;
	t_block	*b;

	a = base;
	b = NULL;
	while (a)
	{
		if (get_page_type(s) == a->type)
			b = find_block_in_page(a, s);
		if (b)
			return (b);
		a = a->next;
	}
	return (b);
}

void		*new_malloc(size_t s)
{
	t_area	*a;
	t_block	*b;

	if (!(a = add_new_page(NULL, s)))
		return (NULL);
	base = a;
	b = a->block;
	return (b->data);
}

void		*ft_malloc(size_t s)
{
	t_area	*a;
	t_block	*b;

	s = ALIGN4(s);
	if (base)
	{
		a = base;
		b = find_block(s);
		if (b)
		{
			if ((b->size - s) >= (BLOCK_SIZE + 4))
				split_block(b, s);
			b->free = 0;
		}
		else
		{
			while (a->next)
				a = a->next;
			if (!(a->next = add_new_page(a, s)))
				return (NULL);
			b = a->next->block;
		}
		return (b->data);
	}
	return (new_malloc(s));
}
