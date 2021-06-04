/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:40:39 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/04 19:50:38 by vicmarti         ###   ########.fr       */
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
	printf("STRLEN: %lu|%lu\n", real, lasm);
	if (real < 80)
		printf("String: %s\n", s);
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
	size_t	len;

	len = strlen(s) + 42;
	dst1 = calloc(len, sizeof(char));
	dst2 = calloc(len, sizeof(char));
	memset(dst1, 42, (size_t)len - 1);
	memset(dst2, 42, (size_t)len - 1);
	real = strcpy(dst1 + 21, s);
	lasm = ft_strcpy(dst2 + 21, s);

	printf("Given string: %s\nReal mem with padding: %s\nLasm mem with padding: %s\n",
			s, dst1, dst2);

	if (lasm != dst2 + 21 || strcmp(dst1, dst2) || strcmp(real, lasm))
		printf("KO\n");
	else
		printf("OK\n");
	free(dst1);
	free(dst2);
}

static void	tstcmp(char *s1, char *s2)
{
	int	real;
	int	lasm;

	real = strcmp(s1, s2);
	lasm = ft_strcmp(s1, s2);

	printf("STRCMP: %s|%s\nReal out: %d\nLasm out: %d\n", s1, s2, real, lasm);
	if (real == lasm || (real > 0 && lasm > 0) || (real < 0 && lasm < 0))
		printf("OK\n");
	else
		printf("KO:%s<->%s\n", s1, s2);
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
	printf("Memory directions %p|%p\nString: %s\nReal dup: %s\nLasm dup: %s\n", real, lasm, s, real, lasm);
	if (lasm == real)
		printf("KO/Cheeky btard.\n");
	else if (!strcmp(real,lasm))
		printf("OK\n");
	else
		printf("KO\n");
//	fflush(stdout);
	free(real);
//	if (lasm)
		free(lasm);
}

int		main(void)
{
	char	*long_one;
	
	printf("Strlen tests:\n");
	tstlen("");
	tstlen("\0Hidden");
	tstlen("TE\0ST");
	tstlen("Say hello the world, son!!");
	tstlen("I like control \"chars\a\t\n\n\e\r\b, don't blame me.");
	tstlen("Also this:'|\\{[}]-=≈åß∂™£¢∞™••¶•£™¶∞¢¶ªºœ∑´ˆˆ†∑œ´®ƒß∂å…åß∂µ≤≥");

	printf("Strcpy tests:\n");
	tstcpy("");
	tstcpy("\0Hidden");
	tstcpy("TE\0ST");
	tstcpy("Say hello the world, son!!");
	tstcpy("I like control \"chars\a\t\n\n\e\r\b, don't blame me.");
	tstcpy("Also this:'|\\{[}]-=≈åß∂™£¢∞™••¶•£™¶∞¢¶ªºœ∑´ˆˆ†∑œ´®ƒß∂å…åß∂µ≤≥");

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

	printf("Strdup tests:\n");
	tstdup(s1);
	tstdup(s2);
	tstdup(s3);
	tstdup(s4);
	tstdup(s5);
	tstdup(s6);
	tstdup(s7);

	system("leaks test");

	printf("Long string tests:\n");
	long_one = calloc((size_t)INT_MAX + 42, sizeof(char));
	memset(long_one, 42, (size_t)INT_MAX + 41);
	tstlen(long_one);
	tstcpy(long_one);
	tstdup(long_one);
	free(long_one);
	return (0);
}
