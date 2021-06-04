/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:13:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/04 21:52:16 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"

static void	tstatoi_base(char *str, char *base, int result)
{
	int	output = ft_atoi_base(str, base);
	if(result == output)
		printf("OK");
	else
		printf("KO");
	printf("[%d<->%d]\n", result, output);
}

static void	prnt_list(t_list *lst)
{
	printf ("_______________\nTotal size:%d\n", ft_list_size(lst));
	while (lst)
	{
		printf("-->|Elem:%s|", (char *)(lst->data));
		lst = lst->next;
	}
	printf("\n");
}

static int	strcmp_vwrap(void *s1, void *s2)
{
	return (strcmp((char *)s1, (char *)s2));
}

int main(void)
{
	t_list	*lst = NULL;
	char	*aux;

	aux = strdup("nope");
	printf("Add element to an NULL list shouldn't crash\n");
	ft_list_push_front(NULL, aux);
	free(aux);
	printf("NULL list should have 0 length.\n");
	prnt_list(lst);
	aux = strdup("aaa");
	printf("Create element /%s/ as the start of a new list.\n", aux);
	lst = ft_create_elem(aux);
	prnt_list(lst);
	aux = strdup("abc");
	printf("Add a list node with element /%s/ at the start of it.\n", aux);
	ft_list_push_front(&lst, aux);
	prnt_list(lst);
	printf("Add more elements.\n");
	ft_list_push_front(&lst, ft_strdup("acb"));
	ft_list_push_front(&lst, ft_strdup("caa"));
	ft_list_push_front(&lst, ft_strdup("a"));
	ft_list_push_front(&lst, ft_strdup("aaa"));
	ft_list_push_front(&lst, ft_strdup("baa"));
	ft_list_push_front(&lst, ft_strdup("aaa"));
	prnt_list(lst);
	printf("Remove from a NULL list should not crash.\n");
	ft_list_remove_if(NULL, "aaa", strcmp_vwrap, free);
	printf("Remove usinf NULL function should not crash.\n");
	ft_list_remove_if(&lst, "aaa", NULL, free);
	prnt_list(lst);
	printf("Remove all nodes with the string \"aaa\", first element.\n");
	ft_list_remove_if(&lst, "aaa", strcmp_vwrap, free);
	prnt_list(lst);
	printf("Remove all nodes with the string \"aaa\" again.\n");
	ft_list_remove_if(&lst, "aaa", strcmp_vwrap, free);
	prnt_list(lst);
	printf("Remove all nodes with the string \"caa\", not first element.\n");
	ft_list_remove_if(&lst, "caa", strcmp_vwrap, free);
	prnt_list(lst);
	//printf("Sort with a NULL function, no crash.\n");
	//ft_list_sort(&lst, NULL);
	prnt_list(lst);
	printf("Sort a NULL list, no crash.\n");
	ft_list_sort(NULL, strcmp_vwrap);
	printf("Sort the list alphabetically.\n");
	ft_list_sort(&lst, strcmp_vwrap);
	prnt_list(lst);
	
	printf("ATOIBASE\n");
	printf("Invalid base tests:\n");
	tstatoi_base("aaaaaaa","",0);
	tstatoi_base("aaaaaaa","a",0);
	tstatoi_base("aaaaaaa","aa",0);
	tstatoi_base("aaaaaaa","abcdeefga",0);
	tstatoi_base("404","01234 ",0);
	tstatoi_base("404"," 01234",0);
	tstatoi_base("404","01 34",0);
	tstatoi_base("404","0123\n",0);
	tstatoi_base("404","0\n34",0);
	tstatoi_base("404","\n01234",0);
	tstatoi_base("404","0123\t",0);
	tstatoi_base("404","0\t34",0);
	tstatoi_base("404","\t01234",0);
	tstatoi_base("404","0123\v",0);
	tstatoi_base("404","0\v34",0);
	tstatoi_base("404","\v01234",0);
	tstatoi_base("404","0123\f",0);
	tstatoi_base("404","0\f34",0);
	tstatoi_base("404","\f01234",0);
	tstatoi_base("404","0123\r",0);
	tstatoi_base("404","0\r34",0);
	tstatoi_base("404","\r01234",0);
	printf("Simple conversions:\n");
	tstatoi_base("0","0123456789",0);
	tstatoi_base("193","0123456789",193);
	tstatoi_base("9932","0123456789",9932);
	tstatoi_base("1234567890","0123456789",1234567890);
	tstatoi_base("000000000193","0123456789",193);
	tstatoi_base("11111111","01",255);
	tstatoi_base("ff","0123456789abcdef",255);
	tstatoi_base("ffff","0123456789abcdef",65535);
	tstatoi_base("ffffffff","0123456789abcdef",(int)4294967295);
	tstatoi_base("7fffffff","0123456789abcdef",(int)2147483647);
	tstatoi_base("2147483647","0123456789",2147483647);
	printf("Larger strings:\n");
	tstatoi_base("300 spartans", "0123456789", 300);
	tstatoi_base("The film about 300 spartans", "0123456789", 0);
	tstatoi_base("3 2 1 0 GO!", "0123456789", 3);
	tstatoi_base("123\0987heh", "0123456789", 123);
	printf("Signs:\n");
	tstatoi_base("+193","0123456789",193);
	tstatoi_base("++++193","0123456789",193);
	tstatoi_base("+++193","0123456789",193);
	tstatoi_base("++-+++193","0123456789",-193);
	tstatoi_base("-193","0123456789",-193);
	tstatoi_base("--193","0123456789",193);
	tstatoi_base("-+-193","0123456789",193);
	tstatoi_base("-----193","0123456789",-193);
	tstatoi_base("--+---+-+---+193","0123456789",-193);
	tstatoi_base("--+---+-+---+aa193","0123456789",0);
	printf("Spaces:\n");
	tstatoi_base(" 193","0123456789",193);
	tstatoi_base("           193","0123456789",193);
	tstatoi_base("   \t193","0123456789",193);
	tstatoi_base("   \v193","0123456789",193);
	tstatoi_base("   \n193","0123456789",193);
	tstatoi_base("   \f193","0123456789",193);
	printf("Mixed:\n");
	tstatoi_base("\n\f\n    \n\t\n\n+--++---+daa spartans", "abcdefghij", -300);

	system("leaks -q btest");
	return (0);
}
