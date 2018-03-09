/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 11:51:57 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/09 17:51:56 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

unsigned long		ft_divide_hex(unsigned long num)
{
	int i;

	i = 0;
	while (num > 15)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

void		ft_print_hex(unsigned long num)
{
	int i;
	char hex[13];
	static char tab[] = "0123456789abcdef";
	
	i = ft_divide_hex(num);
	ft_putstr("0x");
	while (num > 0)
	{
		hex[i] = tab[num % 16];
		num /= 16;
		i--;
	}
	hex[12] = '\0';
	ft_putstr(hex);
}

void		ft_print_alloc(t_area *a)
{
	t_block *b;

	b = a->block;
	while (b)
	{
		ft_print_hex((unsigned long)(b->data));
		ft_putstr(" - ");
		ft_print_hex((unsigned long)(b->data + b->size));
		ft_putstr(" : ");
		ft_putnbr(b->size);
		ft_putstr(" octets\n");
		b = b->next;
	}
}

void		ft_print_string(t_area *a)
{
	if (a->type == IS_TINY)
		ft_putstr("TINY :");
	if (a->type == IS_SMALL)
		ft_putstr("SMALL :");
	if (a->type == IS_LARGE)
		ft_putstr("LARGE :");
	ft_print_hex((unsigned long)a);
	ft_putchar('\n');
	ft_print_alloc(a);
}

int			ft_total_size(void)
{
	t_area *a;
	int		total;

	total = 0;
	a = base;
	while (a)
	{
		total += a->block->size;
		a = a->next;
	}
	return (total);
}
/*
static void	print_hex(long num, int depth)
{
	if (depth == 0)
	{
		write(1, "0x", 2);
		return ;
	}
	print_hex(num >> 4, depth - 1) ;
	num-= (num >> 4) << 4;
	if (num < 10)
		num += '0';
	else
		num += 55;
	write(1, &num, 1);
}
static void	ft_print_title(char *str, t_area *a)
{
	ft_putstr(str);
	ft_putstr(" : ");
	print_hex(a, 9);
	write(1, "\n", 1);
}*/

/*
void	ft_print_blocks(t_area *a)
{
	t_block *b;
	
	b = a->block;
	while (b)
	{
		print_hex((long)b->data, 9);
		ft_putstr(" - ");
		print_hex((long)(b->data + b->size), 9);
		ft_putstr(" : ");
		ft_putnbr(b->size);
		ft_putstr(" octets\n");
		b = b->next;
	}
}

void		ft_print_string(t_area *a)
{
	ft_putstr("TEST :");
	print_hex((long)a, 9);
	ft_putchar('\n');
	ft_print_blocks(a);
}

static long	print_alloc(t_area *a)
{
	long size;

	print_hex((long)(a->block->data), 9);
	ft_putstr(" - ");
	print_hex((long)(a->block->data + a->block->size), 9);
	ft_putstr(" : ");
	size = a->block->size;
	ft_putnbr(size);
	ft_putstr(" octets\n");
	return (size);
}

long		ft_total_size(void)
{
	t_area *a;
	long total;

	a = base;
	total = 0;
	while (a)
	{
		total += a->size;
		a = a->next;
	}
	return (total);
}

void		ft_print_tiny(t_area *a)
{
	ft_putstr("TINY : ");
	print_hex((long)a, 9);
	ft_putchar('\n');
	ft_print_blocks(a);
}

void		ft_print_small(t_area *a)
{
	ft_putstr("SMALL : ");
	print_hex((long)a, 9);
	ft_putchar('\n');
	ft_print_blocks(a);
}

void		ft_print_large(t_area *a)
{
	ft_putstr("LARGE :");
	print_hex((long)a, 9);
	ft_putchar('\n');
	ft_print_blocks(a);
}

void		show_alloc_mem(void)
{
	t_block *b;
	long	total = 0;

	b = ;
	ft_print_string("TINY", (long)b);
	total += ft_total_size(b);
	b = ft_prealloc_small()->small;
	ft_print_string("SMALL", (long)b);
	total += ft_total_size(b);
	b = ft_prealloc_large()->large;
	ft_print_string("LARGE :", (long)b);
	total += ft_total_size(b);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
}*/

void		show_alloc_mem(void)
{
	t_area *a;
	int i;

	i = 0;
	while (i < 3)
	{
		a = base;
		while (a)
		{
			if (a->type == i)
					ft_print_string(a);
			a = a->next;
		}
		i++;
	}
	ft_putstr("Total :");
	ft_putnbr(ft_total_size());
	ft_putchar('\n');
}

int main()
{
	ft_malloc(5000);
	show_alloc_mem();
	return (0);
}
