/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:40:39 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/21 12:53:35 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libasm.h"

int		main(void)
{
	clock_t bgn;
	clock_t end;
	char	dst1[1024];
	char	dst2[1024];
/*
	bgn = clock();
	printf("Length:%ld\n", ft_strlen("TE\0ST")); //TODO: Add as side test.
	printf("Length:%ld\n", ft_strlen("TEST")); //TODO: Add as side test.
	printf("Length:%ld\n", ft_strlen("Hola, Mundo\n Lololailo\0")); //TODO: Add as side test.
	printf("Length:%ld\n", ft_strlen("\0")); //TODO: Add as side test.
	printf("Length:%ld\n", ft_strlen("")); //TODO: Add as side test.
	end = clock();

	printf("B:%lu\nE:%lu\nTICKS:%lu\n", bgn, end, end - bgn);

	memset(dst1, '1', 1024);
	memset(dst2, '2', 1024);

	bgn = clock();
	printf("Compares:%p|%s\n",ft_strcpy(dst1, "Simple test."), dst1);
	end = clock();
	printf("B:%lu\nE:%lu\nTICKS:%lu\n", bgn, end, end - bgn);

	bgn = clock();
	printf("Compares:%p|%s\n",strcpy(dst2, "Simple test."), dst2);
	end = clock();
	printf("B:%lu\nE:%lu\nTICKS:%lu\n", bgn, end, end - bgn);
*/
	bgn = clock();
	printf("MyCMP:%d\nTheCMP:%d\n", ft_strcmp("Simple \0plan", "Simple \0test."),
			strcmp("Simple \0plan", "Simple \0test."));
	end = clock();
	printf("B:%lu\nE:%lu\nTICKS:%lu\n", bgn, end, end - bgn);

	bgn = clock();
	printf("MyCMP:%d\nTheCMP:%d\n", ft_strcmp("Simple plan", "Simple test."),
			strcmp("Simple plan", "Simple test."));
	end = clock();
	printf("B:%lu\nE:%lu\nTICKS:%lu\n", bgn, end, end - bgn);

	return (0);
}

