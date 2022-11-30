/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:43:20 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 21:44:55 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		fake_atoi(str[j]);
		j++;
	}
	check_duplicates(str, j);
	zeros_validation(str, j);
}

void	small_sort(int size, t_stack **a, t_stack **b)
{
	if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 5)
	{
		small_sort(size, a, b);
		ft_lstclear(a, del);
		ft_lstclear(b, del);
	}
	else
	{
		indexing(*a);
		butterfly(a, b);
		ft_lstclear(a, del);
		ft_lstclear(b, del);
	}
}

int	main(int argc, char **argv)
{
	char	**str;
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		str = argv_parsing(argc, argv);
		if (!str || !str[0])
			return (0);
		error_check(str);
		a = fill_stack(str);
		free_str(str);
		if (is_sorted(a))
		{
			ft_lstclear(&a, del);
			ft_lstclear(&b, del);
			return (0);
		}
		sort(&a, &b);
	}
	return (0);
}
