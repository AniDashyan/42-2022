/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendl_doloar_comand.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:30:44 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_handle_dollar
{
	int		i;
	int		j;
	int		is_in_single;
	int		is_in_double;
	int		flag;
	char	*ptr;
	char	*str1;
	char	*str_line;
}	t_handle_dollar;

static void	adjust_stat(char c, t_handle_dollar *dollar)
{
	dollar->flag = 1;
	if (c == '\'' && !dollar->is_in_double)
	{
		dollar->flag = 0;
		(dollar->j)++;
		if (dollar->is_in_single == 1)
			dollar->is_in_single = 0;
		else
			dollar->is_in_single = 1;
	}
	if (c == '"' && !dollar->is_in_single)
	{
		dollar->flag = 0;
		(dollar->j)++;
		if (dollar->is_in_double == 1)
			dollar->is_in_double = 0;
		else
			dollar->is_in_double = 1;
	}
}

static void	init_t_handle_dollar(t_handle_dollar *dollar)
{
	dollar->i = 0;
	dollar->j = 0;
	dollar->is_in_single = 0;
	dollar->is_in_double = 0;
	dollar->flag = 1;
	dollar->str_line = ft_strdup("");
	dollar->ptr = NULL;
}

static void	hendl_doloar_comand_helper(t_data *data, char *test, \
t_handle_dollar *dollar)
{
	dollar->j++;
	dollar->i = dollar->j;
	while ((ft_isalpha(test[dollar->j]) || test[dollar->j] == '_'
			|| ft_isdigit(test[dollar->j]) || test[dollar->j] == '?'))
		dollar->j++;
	dollar->str1 = ft_substr(test, dollar->i, dollar->j - dollar->i);
	dollar->ptr = get_dolar_val(data, dollar->str1);
	free(dollar->str1);
	if (dollar->ptr)
		dollar->str_line = ft_strjon_free_arg1(dollar->str_line, dollar->ptr);
}

int	is_endof_line_barev(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(" \n\t\1", str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

char	*hendl_doloar_comand(t_data *data, char *test)
{
	t_handle_dollar	dollar;

	init_t_handle_dollar(&dollar);
	while (test[dollar.j])
	{
		adjust_stat(test[dollar.j], &dollar);
		if (!dollar.is_in_single && !is_endof_line_barev(test + dollar.j + 1)
			&& test[dollar.j] == '$')
			hendl_doloar_comand_helper(data, test, &dollar);
		else if (dollar.flag)
		{
			dollar.ptr = ft_substr(test, dollar.j, 1);
			dollar.str_line = ft_strjon_free_both(dollar.str_line, dollar.ptr);
		}
		if (dollar.flag == 1 && test[dollar.j]
			&& ((dollar.is_in_double || dollar.is_in_single)
				|| (!dollar.is_in_double && !dollar.is_in_single
					&& !ft_strchr("'\"", test[dollar.j]))))
			dollar.j++;
	}
	return (dollar.str_line);
}
