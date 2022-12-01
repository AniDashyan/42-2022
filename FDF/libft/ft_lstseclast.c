/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstseclast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:47:17 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:47:18 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstseclast(t_stack *lst)
{
	t_stack	*sec_last;

	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		sec_last = lst;
		lst = lst->next;
	}
	return (sec_last);
}
