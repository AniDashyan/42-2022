#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>
t_redirect	*redirect_test(t_pipe *pipe) ;

/* void init_argv_test(t_data *data)
{
	char **argv;

	argv = calloc(2, sizeof(char *));
	argv[0] = "ls";
	ft_t_pipe_add_back(&data->pipe, new_t_pipe(argv));
	argv = calloc(2, sizeof(char *));
	argv[0] = "cat";
	ft_t_pipe_add_back(&data->pipe, new_t_pipe(argv));
	argv = calloc(2, sizeof(char *));
	argv[0] = "cat";
	ft_t_pipe_add_back(&data->pipe, new_t_pipe(argv));
} */
void pipe_in_out(int i,t_data *data,int count)
{
	if (i == 0)
	{
		close(data->pipe->fd[i][0]);
		dup2(data->pipe->fd[i][1], STDOUT_FILENO);
		close(data->pipe->fd[i][1]);
	}
	else if (i > 0 && i < count)
	{
		close(data->pipe->fd[i - 1][0]);
		dup2(data->pipe->fd[i - 1][1], STDIN_FILENO);
		close(data->pipe->fd[i - 1][1]);
		close(data->pipe->fd[i][0]);
		dup2(data->pipe->fd[i][1], STDOUT_FILENO);
		close(data->pipe->fd[i][1]);
	}				
	else
	{
		close(data->pipe->fd[i - 1][1]);
		dup2(data->pipe->fd[i - 1][0], STDIN_FILENO);
		close(data->pipe->fd[i - 1][0]);
	}
	lsh_launch(data);
	exit(0);
}

void pipe_exec(t_data *data)
{
	int		i;
	int		count;

	i = 0;
	count = data->pipe_count;
		while (i <= count)
		{
			data->pipe->fd[i] = malloc(sizeof(int) * 2);
			if(pipe(data->pipe->fd[i]) == -1)
			{
				printf("error\n");
				return ;
			}
			pid_t id = fork();
			if (id == -1)
				perror("Error: fork\n");
			if (id == 0)
				pipe_in_out(i,data,count);				
			i++;
		}
		i = 0;
		while (i != -1)
			i = waitpid(-1, NULL, 0);
}

int main(int ac,  char **av,  char **env)
{
	(void)(av + ac);
	char 	*ptr;
	t_data	data;
		
	struct_zeroed(&data, env);
    // init(&data, env);
	// printf("head->key:: %s\n", data.head_env->key);
	// printf("jdsh\n");
	// print_list_head_env(data.head_env);
	// printf("ij\n");
	
	while (1)
	{
		ptr = readline("minishell-$ ");
		split_string(ptr, &data);		
		if (*ptr)
			add_history(ptr);
		split_readline(ptr,/*  data.pipe, */ &data);
		pipe_exec(&data);
		heredoc(ptr);	
		// print_list_head_env(data.head_env);	
		// print_env(&data);
	}
	return (0);
}