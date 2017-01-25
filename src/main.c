/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 21:03:38 by obelange          #+#    #+#             */
/*   Updated: 2017/01/19 21:03:40 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"




void	t_context_print(t_context *context)
{
	int i;

	i = 0;
	printf("\n");
	printf("context->path: %s\n", context->path);
	printf("context->index: %d\n", context->index);
	printf("context->chr: %s\n", context->chr);
	printf("context->invalid: %s\n", context->invalid);
	if (context->invalid)
		while (context->invalid[i])
		printf("context->invalid[%d]: %s\n", i, context->invalid[i++]);
}




void	t_clip_print(t_clip *clip)
{


	printf("ssignal: %s\n", clip->ssignal);
	printf("lsignal: %s\n", clip->lsignal);



}


int	main(void)
{

	t_clip	*clip;
	char	**strlist;

	strlist = ft_strlist_add(strlist, "one\n");
	strlist = ft_strlist_add(strlist, "two\n");

	printf("len: %d\n", ft_strlist_len(strlist));
	ft_strlist_print(strlist);

	

	printf("index of two: %d\n", ft_strlist_find(strlist, "two\n"));

	// strlist = ft_strlist_minus(strlist);
	strlist = ft_strlist_remove(strlist, "one\n");

	ft_strlist_print(strlist);

	ft_strlist_del(&strlist);

	// clip = t_clip_build(ft_ls_cli_error);

	// t_clip_init(clip);

	

	// t_clip_destroy(&clip);


	// t_context	*context;
	// char		*str[3];
	// int			k;
	// t_file		**filelist;

	// str[0] = ".";
	// str[1] = "..";
	// str[2] = NULL;

	// context = t_context_init("0", -1, NULL, str);
	// t_context_print(context);
	// context = t_context_add_path(context, "abc");
	// t_context_print(context);
	// t_context_minus_path(context);
	// t_context_print(context);

	// filelist = filelist_init(context, "0/txt.txt");
	// printf("\n");

	// filelist_print(filelist);
	

	// t_context_free(&context);



	return (0);
}



