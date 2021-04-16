/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:02:40 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/16 20:37:45 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stdlib.h>
# include <sys/types.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
ssize_t		ft_read(int filedes, void *buf, size_t nbyte);
ssize_t		ft_write(int filedes, const void *buf, size_t nbyte);

t_list		*ft_create_elem(void *data);
int			ft_list_size(t_list *begin_list);
void		ft_list_push_front(t_list** begin_list, void *data);
#endif
