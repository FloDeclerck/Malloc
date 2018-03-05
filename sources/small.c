/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:32:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/05 11:33:11 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_small		*ft_find_small(t_small *last, size_t size)
{
	t_small *s;

	s = base;
	while (s && !(s->free && s->size >= size))
	{
		last = s;
		s = s->next;
	}
	return (s);
}

void		ft_split_small(t_small *s, size_t size)
{
	t_small *new;
	new = (void *)s->data + size;
	new->size = s->size - size - SMALL_SIZE;
	new->next = s->next;
	new->prev = s;
	new->free = 1;
	new->ptr = s->data + size;
	new->small = s->small;
	s->next = new;
}

t_small		*ft_extend_small(t_small *last, size_t size)
{
	t_small *s;

	s = (t_small *)mmap(NULL, SMALL, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (s == MAP_FAILED)
		return (NULL);
	s->size = getpagesize() * 100 * 32;
	s->next = NULL;
	s->prev = last;
	s->small = s + SMALL_SIZE;
	ft_split_small(s, size);
	if (last)
		last->next = s;
	s->free = 0;
	return (s);
}

void		*ft_small(size_t size)
{
	t_small *s, *last = NULL;

	size = ALIGN4(size);
	if (base)
	{
		last = base;
		s = ft_find_small(last, size);
		if (s)
		{
			if ((s->size - size) >= (SMALL_SIZE + 4))
				ft_split_small(s, size);
			s->free = 0;
		}
		else
		{
			s = ft_extend_small(last, size);
			if (!s)
				return (NULL);
		}
	}
	else
	{
		s = ft_extend_small(last, size);
		if (!s)
			return (NULL);
		base = s;
	}
	return (s->data);
}

/*
int main()
{
	int i = 0;
	char *addr;

	while (i < 1)
	{
		addr = (char *)ft_small(130984);
		addr[0] = 42;
		printf("%d\n", *addr);
		i++;
	}
	return (0);
}*/
