/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:30:58 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_env(t_data	*data, char **envp)
{
	int		i;
	t_env	*tmp_first_node;
	char	**split_env;

	i = 0;
	tmp_first_node = (t_env *)malloc(sizeof(t_env));
	if (!tmp_first_node)
		return (0);
	data->head_env = tmp_first_node;
	while (envp[i])
	{
		split_env = ft_split(envp[i], '=');
		tmp_first_node->key = ft_strdup(split_env[0]);
		tmp_first_node->val = ft_strdup(split_env[1]);
		tmp_first_node->next = NULL;
		free_matrix(split_env);
		if (!envp[i + 1])
			break ;
		tmp_first_node->next = (t_env *)malloc(sizeof(t_env));
		if (!tmp_first_node->next)
			return (0);
		tmp_first_node = tmp_first_node->next;
		i++;
	}
	return (0);
}

void	struct_zeroed(t_data *data, char **env)
{
	init_env(data, env);
	data->pipe = NULL;
	data->env = env;
	data->pipe_count = 0;
	data->len_key_sum = 0;
	data->len_val_sum = 0;
	ft_t_env_add_back(&data->head_env, new_t_env("?", "0"));
}

void	send_env(t_data *data)
{
	t_env	*head;
	char	*str;
	char	*str1;

	str1 = ft_strdup(" ");
	head = data->head_env;
	while (head)
	{
		str = ft_strjoin(head->key, "=");
		str = ft_strjoin(str, head->val);
		str = ft_strjoin(str, " ");
		str1 = ft_strjoin(str1, str);
		head = head->next;
	}
	data->env = ft_split(str1, ' ');
}

char	*ft_get_value(char *key, t_data *ptr)
{
	t_env	*head_env;

	head_env = ptr->head_env;
	while (head_env)
	{
		if (ft_strcmp(key, head_env->key) == 0)
			return (head_env->val);
		head_env = head_env->next;
	}
	return (NULL);
}
