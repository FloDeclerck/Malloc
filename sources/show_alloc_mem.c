/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 11:51:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/14 10:38:27 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void				ft_print_addr(unsigned long addr, int size)
{
	if (size == 0)
	{
		ft_putstr("0x");
		return ;
	}
	ft_print_addr(addr >> 4, size - 1);
	addr -= (addr >> 4) << 4;
	if (addr < 10)
		addr += '0';
	else
		addr += 55;
	write(1, &addr, 1);
}

unsigned long		ft_print_alloc(t_area *a)
{
	t_block			*b;
	unsigned long	size;

	b = a->block;
	while (b->next != NULL)
	{
		ft_print_addr((unsigned long)(b->data), 9);
		ft_putstr(" - ");
		ft_print_addr((unsigned long)(b->data + b->size), 9);
		ft_putstr(" : ");
		size = b->size;
		ft_putnbr(size);
		ft_putstr(" octets\n");
		b = b->next;
	}
	return (size);
}

void				ft_print_title(t_area *a)
{
	if (a->type == IS_TINY)
		ft_putstr("TINY : ");
	if (a->type == IS_SMALL)
		ft_putstr("SMALL : ");
	if (a->type == IS_LARGE)
		ft_putstr("LARGE : ");
	ft_print_addr((unsigned long)a, 9);
	ft_putchar('\n');
	ft_print_alloc(a);
}

unsigned long		ft_total_size(t_area *a)
{
	unsigned long	total;

	total = 0;
	while (a->block->next != NULL)
	{
		total += a->block->size;
		a->block = a->block->next;
	}
	return (total);
}

void				show_alloc_mem(void)
{
	t_area			*a;
	int				i;
	unsigned long	total;

	total = 0;
	i = 0;
	while (i < 3)
	{
		a = g_base;
		while (a)
		{
			if (a->type == i)
			{
				ft_print_title(a);
				total += ft_total_size(a);
			}
			a = a->next;
		}
		i++;
	}
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putchar('\n');
}
