/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 10:11:41 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/09 13:07:03 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_env *env = NULL;

t_env		*ft_prealloc_tiny(void)
{
	env = mmap(NULL, sizeof(t_env) + getpagesize() * 100 
			* 8 + getpagesize() * 100 * 32, PROT_READ |
					PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (env == MAP_FAILED)
		return (NULL);
	env->tiny_max = getpagesize() * 100 * 8;
	env->tiny = (t_block*)(env + 1);
	env->tiny->max = env->tiny + 2;
	env->tiny->next = NULL;
	return (env);
}


t_env		*ft_prealloc_small(void)
{
	env = mmap(NULL, sizeof(t_env) + getpagesize() * 100
			* 8 + getpagesize() * 100 * 32, PROT_READ |
			 PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (env == MAP_FAILED)
		return (NULL);
	env->small_max = getpagesize() * 100 * 32;
	env->small = (t_block *)(env->tiny + env->tiny_max);
	env->small->max = env->small + 1;
	env->small->next = NULL;
	return (env);
}

t_env		*ft_prealloc_large(void)
{
	env = mmap(NULL, sizeof(t_env) + getpagesize() * 100 * 8
			+ getpagesize() * 100 * 32, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (env == MAP_FAILED)
		return (NULL);
	env->large = (t_block*)(env->tiny + 1);
	env->large->max = env->large + 1;
	env->large->next = NULL;
	return (env);
}