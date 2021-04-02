/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:44:18 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/02 16:19:02 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include "libasm.h"

int	main(void)
{
	int		err_org;
	int		err_lib;
	ssize_t	rout_org;
	ssize_t	rout_lib;
	char	buf[12];

	memset(buf, 42, 12);
	errno = 0;
	while (0 < (rout_lib = ft_read(0, buf, 11)))
	{
		buf[rout_lib] = 0;
		printf("Here you go: %s\n", buf);
		if (errno)
			printf("ERRNO KO\n");
		else
			printf("ERRNO OK\n");
		errno = 0;
		memset(buf, 42, 12);
	}
	rout_org = read(-42, buf, 11);
	err_org = errno;
	errno = 0;
	rout_lib = ft_read(-42, buf, 11);
	err_lib = errno;
	if (rout_org != rout_lib)
		printf("Wrong return:%ld|%ld\n", rout_org, rout_lib);
	else
		printf("Right return\n");
	if (err_org != err_lib)
		printf("ERRNO KO\n");
	else
		printf("ERRNO OK\n");
	return (0);
}
