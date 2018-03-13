/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:00:46 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/13 16:59:22 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		ft_copy_block(t_block *src, t_block *dst)
{
	int		*sdata;
	int		*ddata;
	size_t	i;

	i = 0;
	sdata = (void *)src->data;
	ddata = (void *)dst->data;
	while (i * 4 < src->size && i * 4 < dst->size)
	{
		ddata[i] = sdata[i];
		i++;
	}
}

void		*ft_new_realloc(void *ptr, t_block *b, size_t s)
{
	t_block *new;
	void	*newptr;

	newptr = malloc(s);
	if (!newptr)
		return (NULL);
	new = ft_get_block(newptr);
	ft_copy_block(b, new);
	free(ptr);
	return (newptr);
}

void		*ft_next_fusion(void *ptr, t_block *b, size_t s)
{
	if (b->size >= s)
	{
		if (b->size - s >= (BLOCK_SIZE + 4))
			ft_split_block(b, s);
	}
	else
	{
		if (b->next && b->next->free &&
			(b->size + BLOCK_SIZE + b->next->size) >= s)
		{
			ft_block_fusion(b);
			if (b->size - s >= (BLOCK_SIZE + 4))
				ft_split_block(b, s);
		}
		else
			return (ft_new_realloc(ptr, b, s));
	}
	return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
	size_t	s;
	t_block	*b;

	if (!ptr)
		return (malloc(size));
	b = ft_get_block(ptr);
	if (b)
	{
		s = size;
		return (ft_next_fusion(ptr, b, s));
	}
	return (NULL);
}
