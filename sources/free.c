/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:43:23 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/13 16:58:48 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block		*ft_block_fusion(t_block *b)
{
	if (b->next && b->next->free)
	{
		b->size += BLOCK_SIZE + b->next->size;
		b->next = b->next->next;
		if (b->next)
			b->next->prev = b;
	}
	return (b);
}

t_block		*ft_get_block(void *ptr)
{
	t_area	*a;
	t_block	*tmp;

	a = g_base;
	while (a)
	{
		tmp = a->block;
		while (tmp)
		{
			if (tmp->data == ptr)
				return (tmp);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (NULL);
}

int			ft_valid_addr(t_area *a)
{
	int		i;
	t_area	*tmp;

	i = 0;
	tmp = g_base;
	if (a->type == 2)
		return (0);
	while (tmp)
	{
		if (tmp->type == a->type)
			i++;
		tmp = tmp->next;
	}
	if (i > 1)
		return (0);
	return (1);
}

void		ft_end_free(t_area *a)
{
	size_t	size;

	size = a->size;
	if (a->next)
		a->next->prev = a->prev;
	if (a->prev)
		a->prev->next = a->next;
	else
		g_base = a->next;
	if (munmap(a, size) == -1)
		ft_putstr("FREE ERROR\n");
}

void		free(void *ptr)
{
	t_area	*a;
	t_block	*b;

	b = ft_get_block(ptr);
	if (b)
	{
		a = b->area;
		b->free = 1;
		if (b->prev && b->prev->free)
			b = ft_block_fusion(b->prev);
		if (b->next)
			ft_block_fusion(b);
		else if (!(b->prev) && ft_valid_addr(a) == 0)
			ft_end_free(a);
	}
}
