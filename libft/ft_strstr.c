/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:56:02 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 15:23:11 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char const *haystackb;
	char const *needleb;

	needleb = needle;
	while (*haystack != '\0')
	{
		haystackb = haystack;
		while (*needle != '\0' && *haystack == *needle)
		{
			++haystack;
			++needle;
		}
		if (*needle == '\0')
			return ((char*)haystackb);
		haystack = haystackb + 1;
		needle = needleb;
	}
	return (*needle == '\0' ? (char*)haystack : NULL);
}
