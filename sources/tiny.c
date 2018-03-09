/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/09 17:31:23 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void *base = NULL;

void		ft_split_tiny(t_area *a, size_t size, size_t alloc)
{
	t_block *new;

	new = (void *)a->block->data + size;
	new->size = alloc - size - BLOCK_SIZE;
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
	a->type = 0;
	a->size = TINY;
	a->next = NULL;
	a->prev = last;
	a->block = ft_new_block(a, size);
	if (a->type < 2)
		ft_split_tiny(a, size, TINY - BLOCK_SIZE - AREA_SIZE);
	if (last)
		last->next = a;
	return (a);
}


void		*ft_tiny(size_t size)
{
	t_area *a;
	t_block *b;

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
			a = ft_init_tiny(a, size);
			if (!a)
				return (NULL);
			b = a->next->block;
		}
		return (b->data);
	}
	a = ft_init_tiny(NULL, size);
	if (!a)
		return (NULL);
	base = a;
	b = a->block;
	return (b->data);
}

/*t_tiny		*ft_find_block(t_tiny *last, size_t size)
{
	t_tiny *t;

	t = base;
	while (t && !(t->free && t->size >= size))
	{
		last = t;
		t = t->next;
	}
	return (t);
}

void		ft_split_tiny(t_tiny *t, size_t size)
{
	t_tiny *new;

	new = (void *)t->data + size;
	new->size = t->size - size - TINY_SIZE;
	new->next = t->next;
	new->prev = t;
	new->free = 1;
	new->ptr = t->data + size;
	new->tiny = t->tiny;
	t->next = new;
}
t_tiny		*ft_extend_tiny(t_tiny *last, size_t size)
{
	t_tiny *t;

	t = (t_tiny *)mmap(NULL, TINY, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (t == MAP_FAILED)
		return (NULL);
	t->size = getpagesize() * 100 * 8;
	t->next = NULL;
	t->prev = last;
	t->tiny = t + TINY_SIZE;
	ft_split_tiny(t, size);
	if (last)
		last->next = t;
	t->free = 0;
	return (t);

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
	t_tiny *t, *last = NULL;

	size = ALIGN4(size);
	if (base)
	{
		last = base;
		t = ft_find_block(last, size);
		if (t)
		{
			if ((t->size - size) >= (TINY_SIZE + 4))
				ft_split_tiny(t, size);
			t->free = 0;
		}
		else
		{
			t = ft_extend_tiny(last, size);
			if (!t)
				return (NULL);
		}
	}
	else
	{
		t = ft_extend_tiny(last, size);
		if (!t)
			return (NULL);
		base = t;
	}
	return (t->data);
}

int main()
{
	int i = 0;
	char *addr;

	while (i < 1)
	{
		addr = (char*)ft_tiny(32000);
		addr[0] = 4;
		printf("%d", *addr);
		i++;
	}
	return (0);
}*/
