/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:10:25 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/02 17:47:19 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_MALLOC_H__
# define __FT_MALLOC_H__
# define align4(x) (((((x) - 1) >> 2) << 2) + 4)
# define BLOCK_SIZE (sizeof(t_block))
# define TINY (4096)

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/mman.h>

void *base = NULL;

typedef struct			s_block
{
	struct s_block		*next;
	struct s_block		*prev;
	struct s_block		*end;
	size_t				size;
	int					free;
	void				*ptr;
	char				data[1];
}						*t_block;

typedef struct		s_data
{
	t_block			*tiny;
	size_t			tiny_max;
	t_block			*small;
	size_t			small_max;
	t_block			*large;
}					t_data;


t_block		ft_find_block(t_block *last, size_t size);

#endif
