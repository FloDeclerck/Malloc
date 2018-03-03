/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 10:11:41 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/03 17:26:11 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_data *data = NULL;

t_data		*ft_prealloc_tiny(void)
{
	if (data == NULL)
	{
		if ((TINY + sizeof(t_data)) * 100 % getpagesize() == 0)
		{
			data = mmap(NULL, (TINY + sizeof(t_data) * 100), PROT_READ |
					PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		}
		else
		{
			data = mmap(NULL, (((((TINY + sizeof(t_data)) * 100) /
								getpagesize()) + 1) * getpagesize()),
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		}
		data->end_tiny = getpagesize() * 100 * 8;
		data->tiny = (t_block*)(data + 1);
		data->tiny->last = data->tiny + 2;
		data->tiny->next = NULL;
	}
	return (data);
}

/*
size_t		ft_prealloc_small(size_t size)
{
	if ((SMALL + BLOCK_SIZE) * 100 % getpagesize() == 0)
		size = ((SMALL + BLOCK_SIZE) * 100);
	else
	{
		size = (((((SMALL + BLOCK_SIZE) * 100) / getpagesize()) + 1) *
				getpagesize());
	}
	return (size);
}*/
