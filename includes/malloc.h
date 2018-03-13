/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/30 10:10:25 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/13 16:58:28 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define BLOCK_SIZE sizeof(struct s_block)
# define AREA_SIZE sizeof(struct s_area)
# define ALIGN4(x) (((((x) - 1) >> 2) << 2) + 4)

# define TINY (489 * getpagesize())
# define IS_TINY 0
# define TINY_MAX 992
# define SMALL (3907 * getpagesize())
# define IS_SMALL 1
# define SMALL_MAX 127000
# define IS_LARGE 2

# include <sys/mman.h>
# include "../libft/libft.h"

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

extern void				*g_base;

t_area					*ft_init_tiny(t_area *last, size_t size);
t_area					*ft_init_small(t_area *last, size_t size);
t_area					*ft_init_large(t_area *last, size_t size);

void					*malloc(size_t size);
void					free(void *ptr);
void					*realloc(void *ptr, size_t size);

t_block					*ft_new_block(t_area *a, size_t size);
t_block					*ft_find_block(size_t size);
void					ft_split_block(t_block *b, size_t size);
int						ft_block_type(size_t size);

t_area					*ft_init_next(t_area *a, size_t size);
t_area					*ft_init_all(t_area *a, size_t size);
t_block					*ft_get_block(void *ptr);
t_block					*ft_block_fusion(t_block *b);

#endif
