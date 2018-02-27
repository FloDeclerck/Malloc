/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:50:28 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/13 13:03:52 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;
	t_list	*next_list;

	if (alst && del)
	{
		next_list = *alst;
		while (next_list)
		{
			(*del)(next_list->content, (*next_list).content_size);
			temp = next_list->next;
			free(next_list);
			next_list = temp;
		}
		*alst = NULL;
	}
}
