/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:25:40 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/09 14:17:15 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

unsigned long    ft_ullen(unsigned long n)
{
    int        i;
    
    i = 0;
    while (n > 15)
    {
        n = n / 16;
        i++;
    }
    return (i);
}

void            ft_putaddr(unsigned long n)
{
    int            i;
    char        hex[13];
    static char    tab[] = "0123456789abcdef";
    
    i = ft_ullen(n);
    ft_putstr("0x");
    while (n > 0)
    {
        hex[i] = tab[n % 16];
        n /= 16;
        i--;
    }
    hex[12] = '\0';
    ft_putstr(hex);
}

long	print_blocks(t_area *a)
{
	long size;
	t_block		*b;

	b = a->block;
	while (b)
	{
		ft_putaddr((unsigned long)b->data);
		ft_putstr(" - ");
		ft_putaddr((unsigned long)(b->data + b->size));
		ft_putstr(" : ");
		size = b->size;
		ft_putnbr(b->size);
		ft_putstr(" octets\n");
	}
	return (size);
}

void	print_page(t_area *a)
{
	if (a->type == IS_TINY)
		ft_putstr("TINY : ");
	if (a->type == IS_SMALL)
		ft_putstr("SMALL : ");
	if (a->type == IS_LARGE)
		ft_putstr("LARGE : ");
	ft_putaddr((unsigned long)a);
	ft_putchar('\n');
	print_blocks(a);
}

int		ft_total_size(void)
{
	int		n;
	t_area	*a;

	n = 0;
	a = base;
	while (a)
	{
		n += print_blocks(a);
		a = a->next;
	}
	return (n);
}

void	show_alloc_mem(void)
{
	int		i;
	t_area	*a;

	i = 0;
	while (i < 3)
	{
		a = base;
		while (a)
		{
			if (a->type == i)
				print_page(a);
			a = a->next;
		}
		i++;
	}
	ft_putstr("Total : ");
	ft_putnbr(ft_total_size());
	ft_putendl(" octets");
}

int main()
{
	ft_malloc(800);
	ft_malloc(10000);
	show_alloc_mem();
	return (0);
}
