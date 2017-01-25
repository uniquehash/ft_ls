/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:46:05 by obelange          #+#    #+#             */
/*   Updated: 2017/01/24 21:46:08 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

size_t	ft_strlist_len(char	**strlist)
{
	size_t	i;

	i = 0;
	if (strlist)
	{
		while (strlist[i])
			i++;		
	}
	return (i);
}