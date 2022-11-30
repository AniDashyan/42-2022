/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:46:51 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:46:52 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack *lst, void *(*f)(int))
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->data);
		tmp = tmp -> next;
	}
}
