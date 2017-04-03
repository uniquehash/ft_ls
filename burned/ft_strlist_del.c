/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:29:32 by obelange          #+#    #+#             */
/*   Updated: 2017/01/23 18:29:34 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_strlist_del(char	***strlist)
{
	size_t	i;

	printf("del:\n");
	if (strlist)
	{
		printf("0:\n");
		if (*strlist)
		{
			i = 0;
			printf("begin del:\n");
			while ((*strlist)[i])
				ft_strdel(&((*strlist)[i++]));			
			free(*strlist);
			*strlist = NULL;  
		}
	}
}