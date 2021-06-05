/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:44:18 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/05 19:01:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "libasm.h"

int	main(int argc, char **argv)
{
	int		err_org;
	int		err_lib;
	int		src;
	int		dst;
	ssize_t	rout;
	char	buf[12];

	read(-42, buf, 11);
	err_org = errno;
	errno = 0;
	ft_read(-42, buf, 11);
	err_lib = errno;
	if (err_org != err_lib)
		printf("ERRNO KO\n");
	else
		printf("ERRNO OK\n");
	if (argc < 2)
		return (0);
	src = open(argv[1], O_RDONLY);
	dst = open("read_output", O_RDWR | O_CREAT, 0600);
	while ((rout = ft_read(src, buf, 11)) > 0)
	{
		buf[rout] = 0;
		write(dst, buf, rout);
	}
	close(dst);
	close(src);
	src = open(argv[1], O_RDONLY);
	dst = open("write_output", O_RDWR | O_CREAT, 0600);
	while ((rout = read(src, buf, 11)) > 0)
	{
		buf[rout] = 0;
		ft_write(dst, buf, rout);
	}
	close(dst);
	close(src);
	system("diff read_output write_output");
	return (0);
}
