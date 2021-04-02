/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:44:18 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/02 11:26:25 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include "libasm.h"

int	main(void)
{
	char	buf[12];

	bzero(buf, 12);
	while (0 < ft_read(0, buf, 11))
	{
		printf("Here you go: %s\n", buf);
		bzero(buf, 12);
	}
	return (0);
}
