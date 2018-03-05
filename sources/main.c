/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:50:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/05 11:41:51 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <stdlib.h>

void		*ft_malloc(size_t size)
{
	if (size <= TINY_MAX)
		return (ft_tiny(size));
	else if (size <= SMALL_MAX)
		return (ft_small(size));
	else
		printf("LARGE ALLOC\n");
	return (0);
}

int main ()
{
	int i;
	char  *p;

	i = 0;
	while (i < 1)
	{
		p = (char *)ft_malloc(127000);
		p[0] = 42;
		printf("%d\n", *p);
		i++;
	}
	return (0);
}
