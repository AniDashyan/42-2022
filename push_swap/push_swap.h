#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct stack
{
	int				data;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

void	fake_atoi(char *str);
void	skip_zero(char	*str);
void	check_duplicates(char *str);
int		zero_count(char *str);
t_stack	fill_stack(char **str);
#endif
