/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:21:17 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/14 11:22:18 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/malloc.h"

int			main(void)
{
	char	*addr1;
	char	*addr2;

	addr1 = (char *)malloc(16 * 1024 * 1024);
	strcpy(addr1, "First Adress\n");
	write(1, addr1, strlen(addr1));
	addr2 = (char *)realloc(addr1, 128 * 1024 * 1024);
	addr2[127 * 1024 * 1024] = 42;
	write(1, addr2, strlen(addr2));
	return (0);
}
