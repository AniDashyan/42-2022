#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;
	char	*join;
	t_stack	a;

	i = 1;
	j = 0;
	if (argc >= 2)
	{
		join = "";
		while (i < argc)
		{
			join = ft_strjoin(join, argv[i]);
			join = ft_strjoin(join, " ");
			i++;
		}
		str = ft_split(join, ' ');
		while (str[j])
		{
			fake_atoi(str[j]);
			j++;
		}
		a = fill_stack_a(str);
	}
	else
		ft_printf("NO");
	return (0);
}
