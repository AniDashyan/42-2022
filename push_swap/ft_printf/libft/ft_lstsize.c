/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:45:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/29 18:46:33 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_stack	*ptr;

	count = 0;
	ptr = lst;
	if (lst == NULL)
		return (0);
	while (ptr != NULL)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}
