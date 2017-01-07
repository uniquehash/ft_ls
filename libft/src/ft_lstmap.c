/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 21:49:26 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 21:49:27 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*catch_leak(t_list *lst, t_list *(*f)(t_list *elem), int *flag)
{
	t_list *node;

	*flag = 0;
	if (lst != NULL)
	{
		if ((node = f(lst)))
		{
			node->next = catch_leak(lst->next, f, flag);
			if (*flag == 0)
				return (node);
			else
			{
				free(node->content);
				free(node);
				return (NULL);
			}
		}
		else
			*flag = 1;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	int flag;

	flag = 0;
	lst = catch_leak(lst, f, &flag);
	return (lst);
}
