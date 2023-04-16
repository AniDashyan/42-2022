/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   porcnakan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:32:04 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hendl_dolar(t_data *data, char *str)
{
	int		i;
	int		j;
	char	*str1;
	char	*val;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '$' && (ft_isalpha(str[j + 1]) || str[j + 1] == '_'))
		{
			j++;
			i = j;
			while ((ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
				j++;
			str1 = ft_substr(str, i, j - i);
			data->len_key_sum += ft_strlen(str1);
			val = get_dolar_val(data, str1);
			free(str1);
			j--;
		}
		j++;
	}
}

char	*get_dolar_val(t_data *data, char *str1)
{
	t_env	*head;

	head = data->head_env;
	while (head)
	{
		if (ft_strcmp(head->key, str1) == 0)
			return (head->val);
		head = head->next;
	}
	return (NULL);
}
