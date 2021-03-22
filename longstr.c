/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:56:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/22 12:41:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "libasm.h"

int	main(void)
{
	char	*longstr;

	longstr = calloc(SIZE_T_MAX / 0xFFFFFFFF, sizeof(char));
	if (!longstr)
	{
		printf("lolailo");
		exit(1);
	}
	memset(longstr, 'a', SIZE_T_MAX / 0xFFFFFFFF - 42);
	printf("Long:\n%lu\n", strlen(longstr));
	return (0);
}
