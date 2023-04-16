/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:31:29 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

int	there_is_builtin(t_pipe *pipe)
{
	int		i;
	char	*build_in[10];

	build_in[0] = "cd";
	build_in[1] = "echo";
	build_in[2] = "pwd";
	build_in[3] = "exit";
	build_in[4] = "env";
	build_in[5] = "unset";
	build_in[6] = "export";
	build_in[7] = NULL;
	i = 0;
	if (pipe->argv && pipe->argv[0])
	{
		while (build_in[i])
		{
			if (ft_strcmp(pipe->argv[0], build_in[i]) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_readline(char *str, t_data *data)
{
	char	*ptr;

	set_term_attr(0);
	ptr = readline(str);
	set_term_attr(1);
	if (ptr == NULL && ft_printf(2, "exit\n"))
		exit(ft_atoi(get_dolar_val(data, "?")));
	return (ptr);
}

int	main(int ac, char **av, char **env)
{
	int		i;
	t_data	data;
	char	*ptr;

	ptr = NULL;
	i = 0;
	(void)(av + ac);
	struct_zeroed(&data, env);
	while (1)
	{
		handle_signal();
		free_data(&data);
		free(ptr);
		ptr = ft_readline("minishell-$ ", &data);
		if ((g_signal == SIGINT && add_exit_status_in_env(&data, 1))
			|| *ptr == '\0')
			continue ;
		add_history(ptr);
		if ((check_errors(ptr) != 0 && add_exit_status_in_env(&data, 258))
			|| (parsing(&data, ptr) != 0 && add_exit_status_in_env(&data, 1)))
			continue ;
		if (data.pipe)
			add_exit_status_in_env(&data, execute(&data));
	}
	return (0);
}
