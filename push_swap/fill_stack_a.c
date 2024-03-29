/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:44:46 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:44:47 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(char **str)
{
	int		i;
	t_stack	*top;
	t_stack	*num;

	i = 0;
	top = ft_lstnew(ft_atoi(str[i]));
	top->pos = i;
	while (str[++i])
	{
		num = ft_lstnew(ft_atoi(str[i]));
		num->pos = i;
		ft_lstadd_back(&top, num);
	}
	return (top);
}
