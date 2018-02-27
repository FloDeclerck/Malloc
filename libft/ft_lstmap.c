/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:12:11 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/13 13:22:28 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*begin;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(result = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	begin = result;
	while (lst->next)
	{
		temp = f(lst->next);
		if (!(result->next = ft_lstnew(temp->content, temp->content_size)))
		{
			ft_lstdel(&begin, &ft_bzero);
			return (NULL);
		}
		lst = lst->next;
		result = result->next;
	}
	return (begin);
}
