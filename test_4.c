/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:22:31 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/14 11:22:48 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/malloc.h"

int			main(void)
{
	char	*addr1;
	char	*addr2;
	char	*addr3;

	addr1 = (char *)malloc(16 * 1024 * 1024);
	strcpy(addr1, "First Adress\n");
	write(1, addr1, strlen(addr1));
	addr2 = (char *)malloc(16 * 1024 * 1024);
	strcpy(addr2, "Second Adress\n");
	write(1, addr2, strlen(addr2));
	addr3 = (char *)realloc(addr1, 128 * 1024 * 1024);
	addr3[127 * 1024 * 1024] = 42;
	write(1, addr3, strlen(addr3));
	return (0);
}
