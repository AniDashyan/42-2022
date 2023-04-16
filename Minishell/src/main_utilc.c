/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:31:11 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	for_space(char *ptr, char c, int i)
{
	if (ptr[i] == c)
	{
		i++;
		while (ptr[i] && ptr[i] != c)
			i++;
		if (ptr[i])
			i++;
	}
	return (i);
}

bool	is_append_out(char c, char d)
{
	return ((c == '>' && d == '>'));
}
