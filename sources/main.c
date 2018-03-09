/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:50:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/09 18:01:58 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*ft_malloc(size_t size)
{
	void *ret;

	ret = NULL;
	if (size <= TINY_MAX)
		ret = ft_tiny(size);
	if (size <= SMALL_MAX)
		ret = ft_small(size);
	ret = ft_large(size);
	return (ret);

}
/*
void		*ft_malloc(size_t size)
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
			if (size <= TINY_MAX)
				a = ft_init_tiny(a, size);
			else if (size <= SMALL_MAX)
				a = ft_init_small(a, size);
			else
				a = ft_init_large(a, size);
			if (!a)
				return (NULL);
			b = a->next->block;
		}
		return (b->data);
	}
	if (size <= TINY_MAX)
		a = ft_init_tiny(NULL, size);
	else if (size <= SMALL_MAX)
		a = ft_init_small(NULL, size);
	else 
		a = ft_init_large(NULL, size);
	if (!a)
		return (NULL);
	base = a;
	b = a->block;
	return(b->data);
}*/
