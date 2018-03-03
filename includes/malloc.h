/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:25 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/03 17:37:26 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# define align4(x) (((((x) - 1) >> 2) << 2) + 4)
//# define BLOCK_SIZE (sizeof(t_block))
# define TINY 256
# define SMALL 4096

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/mman.h>

typedef struct			s_block
{
	struct s_block		*next;
	struct s_block		*last;
}						t_block;

typedef struct			s_data
{
	t_block				*tiny;
	size_t				end_tiny;
	t_block				*small;
	size_t				end_small;
}						t_data;
void		*ft_find_block(t_block *last, long size);
t_block		ft_extend_tiny(t_block last, size_t s);
void		ft_tiny_split(t_block b, size_t s);
void		*ft_tiny(size_t size);
t_data		*ft_prealloc_tiny(void);
//size_t		ft_prealloc_small(size_t size);

#endif
