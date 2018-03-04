/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:25 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/04 17:32:34 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define ALIGN4(x) (((((x) - 1) >> 2) << 2) + 4)
# define BLOCK_SIZE sizeof(struct s_block)
# define AREA_SIZE sizeof(struct s_area)

# define TINY (8 * getpagesize())
# define TINY_MAX 992
# define SMALL (32 * getpagesize())
#define SMALL_MAX 127000

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *base;

typedef struct			s_block
{
	size_t				size;
	struct s_block		*next;
	struct s_block		*prev;
	int					free;
	void				*area;
	void				*ptr;
	char				data[1];
}						t_block;

typedef struct			s_area
{
	size_t				size;
	struct s_area		*next;
	struct s_area		*prev;
	struct s_block		*block;
	int					free;
	char				data[0];
}						t_area;

t_block		ft_extend_tiny(t_block last, size_t s);
void		ft_tiny_split(t_block b, size_t s);
void		*ft_test(size_t size);
t_area		*ft_init_area(t_area *last, size_t size);
t_block		*ft_find_block(t_area *a, size_t size);

#endif
