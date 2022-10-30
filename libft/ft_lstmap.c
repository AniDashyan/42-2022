/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:54:49 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/30 09:26:36 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int (f)(int), void (*del)(int))
{
	t_stack	*new_list;
	t_stack	*new_node;

	new_list = NULL;
	if (lst == NULL || f == NULL)
		return (new_list);
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->data));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
