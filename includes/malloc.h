/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:25 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/05 11:30:53 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define ALIGN4(x) (((((x) - 1) >> 2) << 2) + 4)
# define TINY_SIZE sizeof(struct s_tiny)
# define SMALL_SIZE sizeof(struct s_small)

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

typedef struct			s_tiny
{
	size_t				size;
	struct s_tiny		*next;
	struct s_tiny		*prev;
	void				*ptr;
	void				*tiny;
	int					free;
	char				data[0];
}						t_tiny;

typedef struct			s_small
{
	size_t				size;
	struct s_small		*next;
	struct s_small		*prev;
	void				*ptr;
	void				*small;
	int					free;
	char				data[0];
}						t_small;

t_tiny		*ft_extend_tiny(t_tiny *last, size_t s);
void		*ft_tiny(size_t size);
void		*ft_small(size_t size);
t_tiny		*ft_init_area(t_tiny *last, size_t size);
t_tiny		*ft_find_block(t_tiny *last, size_t size);

#endif
