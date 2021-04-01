/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:40:39 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/01 18:01:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include "libasm.h"

static void	tstlen(const char *s)
{
	size_t	real;
	size_t	lasm;
	clock_t	step1;
	clock_t	step2;
	clock_t	step3;

	step1 = clock();
	real = strlen(s);
	step2 = clock() - step1;
	lasm = ft_strlen(s);
	step3 = clock() - step2 - step1;
	if (real != lasm)
		printf("KO\n");
	else
		printf("OK\nTicks:\nReal:%6ld\nLasm:%6ld\n", step2, step3);
}

static void	tstcpy(const char *s)
{
	char	*dst1;
	char	*dst2;
	char	*real;
	char	*lasm;
	clock_t	step1;
	clock_t	step2;
	clock_t	step3;

	dst1 = calloc((size_t)INT_MAX + 42, sizeof(char));
	dst2 = calloc((size_t)INT_MAX + 42, sizeof(char));

	memset(dst1, 42, (size_t)INT_MAX + 41);
	memset(dst2, 42, (size_t)INT_MAX + 41);



	step1 = clock();
	real = strcpy(dst1, s);
	step2 = clock() - step1;
	lasm = ft_strcpy(dst2, s);
	step3 = clock() - step2 - step1;
	if (lasm != dst2 || strcmp(dst1, dst2) || strcmp(dst2, lasm))
		printf("KO\n");
	else
		printf("OK\nTicks:\nReal:%6ld\nLasm:%6ld\n", step2, step3);
}

static void	tstcmp(char *s1, char *s2)
{
	int	real;
	int	lasm;
	clock_t	step1;
	clock_t	step2;
	clock_t	step3;

	step1 = clock();
	real = strcmp(s1, s2);
	step2 = clock() - step1;
	lasm = ft_strcmp(s1, s2);
	step3 = clock() - step2 - step1;

	if (real == lasm || (real > 0 && lasm > 0) || (real < 0 && lasm < 0))
		printf("OK\nTicks:\nReal:%6ld\nLasm:%6ld\n", step2, step3);
	else
	{
		printf("KO:%s<->%s\n", s1, s2);
		printf("Real out: %d\nLasm out: %d\n", real, lasm);
	}

}

int		main(void)
{
	char	*long_one;
	
	long_one = calloc((size_t)INT_MAX + 42, sizeof(char));
	memset(long_one, 42, (size_t)INT_MAX + 41);
	printf("Strlen tests:\n");
	tstlen("");
	tstlen("\0Hidden");
	tstlen("TE\0ST");
	tstlen("Say hello the world, son!!");
	tstlen("I like control \"chars\a\t\n\n\e\r\b, don't blame me.");
	tstlen("Also this:'|\\{[}]-=≈åß∂™£¢∞™••¶•£™¶∞¢¶ªºœ∑´ˆˆ†∑œ´®ƒß∂å…åß∂µ≤≥");
	tstlen(long_one);

	printf("Strcpy tests:\n");
	tstcpy("");
	tstcpy("\0Hidden");
	tstcpy("TE\0ST");
	tstcpy("Say hello the world, son!!");
	tstcpy("I like control \"chars\a\t\n\n\e\r\b, don't blame me.");
	tstcpy("Also this:'|\\{[}]-=≈åß∂™£¢∞™••¶•£™¶∞¢¶ªºœ∑´ˆˆ†∑œ´®ƒß∂å…åß∂µ≤≥");
	tstcpy(long_one);

	char	*s1 = "";
	char	*s2 = "12\0q789";
	char	*s3 = "12\0asqw";
	char	*s4 = "Such a wonderful hello world";
	char	*s5 = "aaabde";
	char	*s6 = "aaabdj";
	char	*s7 = "aaabd";
	printf("Strcmp tests:\n");
	tstcmp(s1, s1);
	tstcmp(s2, s2);
	tstcmp(s1, s2 + 2);
	tstcmp(s2, s3);
	tstcmp(s3, s4);
	tstcmp(s4, s3);
	tstcmp(s5, s6);
	tstcmp(s5, s5);
	tstcmp(s5, s7);
	tstcmp(s2 + 3, s3 + 3);



	free(long_one);



	return (0);
}

/*

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

}
*/

