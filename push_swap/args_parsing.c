/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:45:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:45:03 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argv_parsing(int argc, char **argv)
{
	int		i;
	char	**str;
	char	*join;
	char	*arr_to_free;

	i = 1;
	join = ft_strdup("");
	while (i < argc)
	{
		arr_to_free = join;
		join = ft_strjoin(join, argv[i]);
		free(arr_to_free);
		arr_to_free = join;
		join = ft_strjoin(join, " ");
		free(arr_to_free);
		i++;
	}
	str = ft_split(join, ' ');
	free(join);
	return (str);
}
