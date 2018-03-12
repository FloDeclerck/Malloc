/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:25 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/12 15:42:22 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define BLOCK_SIZE sizeof(struct s_block)
# define AREA_SIZE sizeof(struct s_area)

# define TINY (8 * 4096)
# define IS_TINY 0
# define TINY_MAX 992
# define SMALL (32 * 4096)
# define IS_SMALL 1
# define SMALL_MAX 127000
# define IS_LARGE 2

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct			s_area
{
	int					size;
	int					type;
	struct s_area		*next;
	struct s_area		*prev;
	struct s_block		*block;
}						t_area;

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

extern void *g_base;

t_area		*ft_init_tiny(t_area *last, size_t size);
t_area		*ft_init_small(t_area *last, size_t size);
//long			ft_total_size(t_area *a);
t_area		*ft_init_large(t_area *last, size_t size);
void		*ft_malloc(size_t size);
void		ft_free(void *ptr);
void		*ft_tiny(size_t size);
void		*ft_small(size_t size);
void		*ft_large(size_t size);
t_block		*ft_new_block(t_area *a, size_t size);
t_block		*ft_find_block(size_t size);
void		ft_split_block(t_block *b, size_t size);
int			ft_block_type(size_t size);
t_area		*ft_init_next(t_area *a, size_t size);
t_area		*ft_init_all(t_area *a, size_t size);

#endif
