/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:13:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/18 21:49:56 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libasm.h"

static void	prnt_list(t_list *lst)
{
	printf ("_______________\nTotal size:%d\n", ft_list_size(lst));
	while (lst)
	{
		printf("\nLength:%d\nDir:%p\nElem:%s\nNext:%p\n",
				ft_list_size(lst), lst, (char *)(lst->data), lst->next);
		lst = lst->next;
	}
}

static int	strcmp_vwrap(void *s1, void *s2)
{
	return (ft_strcmp((char *)s1, (char *)s2));
}

static int	zero(void *s1, void *s2)
{
	return (0);
}

int main(void)
{
	t_list	*lst;

	ft_list_push_front(NULL, "haha");
	lst = ft_create_elem(ft_strdup(""));
	prnt_list(lst);
	ft_list_push_front(&lst, ft_strdup(""));
	ft_list_push_front(&lst, ft_strdup(""));
	ft_list_push_front(&lst, ft_strdup(""));
	ft_list_push_front(&lst, ft_strdup(""));
	ft_list_push_front(&lst, ft_strdup(""));
	ft_list_push_front(&lst, ft_strdup("lololololololo"));
	prnt_list(lst);
	ft_list_push_front(&lst, ft_strdup("hola_bludo"));
	prnt_list(lst);
	ft_list_remove_if(&lst,"",zero,free);
	prnt_list(lst);
	system("leaks -q a.out");

	return (0);
}
