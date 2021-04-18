/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:13:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/19 00:23:02 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //TODO: Deleteme
#include "libasm.h"

static void	prnt_list(t_list *lst)
{
	printf ("_______________\nTotal size:%d\n", ft_list_size(lst));
	while (lst)
	{
		printf("\nLength:%d\nDir:%p->Next:%p\nElem:%s\n",
				ft_list_size(lst), lst, lst->next, (char *)(lst->data));
		lst = lst->next;
	}
}

static int	strcmp_vwrap(void *s1, void *s2)
{
	return (strcmp((char *)s1, (char *)s2));
}

static int	zero(void *s1, void *s2)
{
	return (0);
}

int main(void)
{
	t_list	*lst;

	ft_list_push_front(NULL, "haha");
	lst = ft_create_elem(ft_strdup("a"));
	prnt_list(lst);
	ft_list_push_front(&lst, ft_strdup("lololololololo"));
	prnt_list(lst);
	ft_list_push_front(&lst, ft_strdup("hola_bludo"));
	ft_list_push_front(&lst, ft_strdup("a"));
	ft_list_push_front(&lst, ft_strdup("a"));
	ft_list_push_front(&lst, ft_strdup("a"));
	ft_list_push_front(&lst, ft_strdup("a"));
	ft_list_push_front(&lst, ft_strdup("a"));
	prnt_list(lst);
	ft_list_remove_if(&lst, lst->data, strcmp_vwrap, free);
	prnt_list(lst);
	system("leaks -q a.out");

	return (0);
}
