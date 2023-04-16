/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:41 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	built_in_creat(char **str1, t_pipe *pipe)
{
	t_env	*tmp;

	ft_t_env_add_back(&pipe->head_env, new_t_env(str1[0], str1[1]));
	if (str1[1] == NULL)
	{
		tmp = ft_t_env_last(pipe->head_env);
		free(tmp->val);
		tmp->val = NULL;
	}
}

static void	export_plus(char **str1, t_pipe *pipe, int len)
{
	char	*str;
	t_env	*head;

	str = str1[0];
	str[len - 1] = '\0';
	head = pipe->head_env;
	while (head)
	{
		if (ft_strcmp(str, head->key) == 0)
		{
			str = head->val;
			head->val = ft_strjoin(head->val, str1[1]);
			free(str);
			return ;
		}
		head = head->next;
	}
	built_in_creat(str1, pipe);
}

int	hendl_export_var(char *str1)
{
	int	k;

	k = 0;
	if (ft_isalpha(str1[k]) == 0 && str1[k] != '_')
	{
		return (1);
	}
	k++;
	while (str1[k])
	{
		if (str1[k] == '+' && str1[k + 1] == '\0')
			break ;
		if (ft_isalpha(str1[k]) == 0 && str1[k] != '_'
			&& ft_isdigit(str1[k]) == 0)
			return (1);
		k++;
	}
	return (0);
}

void	buildin_export_all(t_pipe *pipe, int fd)
{
	t_env	*head;

	head = pipe->head_env;
	while (head)
	{
		if (ft_strcmp(head->key, "?") == 0)
		{
			head = head->next;
			continue ;
		}
		if (head->val == NULL)
			ft_printf(fd, "declare -x %s\n", head->key);
		else
			ft_printf(fd, "declare -x %s=\"%s\"\n", head->key, head->val);
		if (head->next == NULL)
			return ;
		head = head->next;
	}
}

int	builtin_export(t_pipe *pipe, int fd)
{
	int		i;
	int		ret;
	char	**str1;

	i = 1;
	ret = 0;
	if (!pipe->argv[1] && buildin_export_sort_by_alphabet(pipe))
		return (buildin_export_all(pipe, fd), 0);
	while (pipe->argv[i])
	{
		str1 = ft_split_for_export(pipe->argv[i], '=');
		if ((str1[0] == NULL && free_matrix(str1))
			|| (hendl_export_var(str1[0]) != 0 && free_matrix(str1)))
		{	
			ret = 1;
			ft_printf(2, "minishell: export: `%s' not a valid\
identifier\n", pipe->argv[i++]);
			continue ;
		}
		if (++i && str1[0][ft_strlen(str1[0]) - 1] == '+')
			export_plus(str1, pipe, ft_strlen(str1[0]));
		else
			built_in_creat(str1, pipe);
		free_matrix(str1);
	}
	return (ret);
}
