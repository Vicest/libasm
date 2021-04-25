/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:40:39 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/25 19:28:51 by vicmarti         ###   ########.fr       */
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

	real = strlen(s);
	lasm = ft_strlen(s);
	if (real != lasm)
		printf("KO\n");
	else
		printf("OK\n");
}

static void	tstcpy(const char *s)
{
	char	*dst1;
	char	*dst2;
	char	*real;
	char	*lasm;

	dst1 = calloc((size_t)INT_MAX + 42, sizeof(char));
	dst2 = calloc((size_t)INT_MAX + 42, sizeof(char));

	memset(dst1, 42, (size_t)INT_MAX + 41);
	memset(dst2, 42, (size_t)INT_MAX + 41);



	real = strcpy(dst1, s);
	lasm = ft_strcpy(dst2, s);
	if (lasm != dst2 || strcmp(dst1, dst2) || strcmp(dst2, lasm))
		printf("KO\n");
	else
		printf("OK\n");
}

static void	tstcmp(char *s1, char *s2)
{
	int	real;
	int	lasm;

	real = strcmp(s1, s2);
	lasm = ft_strcmp(s1, s2);

	if (real == lasm || (real > 0 && lasm > 0) || (real < 0 && lasm < 0))
		printf("OK\n");
	else
	{
		printf("KO:%s<->%s\n", s1, s2);
		printf("Real out: %d\nLasm out: %d\n", real, lasm);
	}
}

static void	tstdup(const char *s)
{
	char	*real;
	char	*lasm;

	real = strdup(s);
	lasm = ft_strdup(s);
	if (!lasm || !real)
	{
		printf("Something's null: Lasm:%s|Real:%s\n", lasm, real);
		return ;
	}
	if (lasm == real)
		printf("KO/Cheeky btard.\n");
	else if (!strcmp(real,lasm))
		printf("OK\n");
	else
		printf("KO\n");
	free(real);
	printf("Free test, should not fail.\n");
	free(lasm);
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

	tstdup(s1);
	tstdup(s2);
	tstdup(s3);
	tstdup(s4);
	tstdup(s5);
	tstdup(s6);
	tstdup(s7);
	tstdup(long_one);

	free(long_one);



	return (0);
}
