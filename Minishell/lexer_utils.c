/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:11:18 by tumolabs          #+#    #+#             */
/*   Updated: 2023/01/15 10:14:40 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

bool	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

bool	is_redirect_in(char c)
{
	if (c == '<')
		return (1);
	return (0);
}

bool	is_redirect_out(char c)
{
	if (c == '>')
		return (1);
	return (0);
}

bool	is_append_in(char c, char d)
{
	return ((c == '<' && d == '<'));
}

bool	is_append_out(char c, char d)
{
	return ((c == '>' && d == '>'));
}