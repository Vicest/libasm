/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:13:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/16 20:46:50 by vicmarti         ###   ########.fr       */
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


int main(void)
{
	t_list	*lst;

	ft_list_push_front(NULL, "haha");
	lst = ft_create_elem(ft_strdup("tururu"));
	prnt_list(lst);
	ft_list_push_front(&lst, ft_strdup("lololololololo"));
	prnt_list(lst);
	ft_list_push_front(&lst, ft_strdup("hola_bludo"));
	prnt_list(lst);
	system("leaks -q a.out");

	return (0);
}
