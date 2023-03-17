#include "minishell.h"

char *check_quot_double(char *ptr)
{
	int i;
	int count;

	i=0;
	count = 0;	
	if (!ptr)
		return ("no readline\n");
	while (ptr && ptr[i])
	{
		// printf("ptr[i] = %c\n", ptr[i]);
		if(ptr[i] == '\\'  && ptr[i + 1] == '\"' )
		{
			i++;
			//printf("i__ = %d off\n", i);
		}
		else
		{
			//printf("i*** = %d ij\n", i);
			if (ptr[i] == '"' /*&& ptr[i - 1] != 47) || ptr[0])*/ )
			{
				count++;
				
			}	
		}
		// printf("i = %d, count %d\n",i, count);
		i++;
	}
	if (count % 2 != 0)
	{
		printf("Syntax error1\n");
		exit(1);
	}
	return (ptr);
}

// echo 'hello \'| > "cat" lol.c'

char *check_quot_one(char *ptr)
{
	int i;
	int count;

	i = 0;
	count = 0;	
	while (ptr && ptr[i])
	{
		if(ptr[i]== '\\' && ptr[i + 1] == '\'' )
			i++;
		else
		{
			if (ptr[i] == '\'')
				count++;
		}
		i++;
		// printf("i = %d, count %d\n",i, count);
	}
	if (count % 2 != 0)
	{
		printf("Syntax error\n");
		exit(1);
	}
	return (ptr);
}


void split_string(char *input, t_data *data)
{
	int		i;
	t_pipe	*head;
	t_pipe	*node;
	int		len;
	int p;

	i = 0;
	data->pipe_count = 0;
	len = ft_strlen(input);
	head = ft_lstnew(&input[0], data->head_env);
	p = i;
	while (i < len)
	{
		if(input[i] == '"' && input[i-1] != '\\')
		{
			p = for_space(input, '"', i);	
			i = p;
		}
		if(input[i] == '\'' && input[i-1] != '\\')
		{
			p = for_space(input, '\'', i);	
			i = p;
		}
		if (input[i] == '|')
		{
			input[i] = '\0';
			data->pipe_count++;
			node = ft_lstnew(&input[i + 1], data->head_env);
			ft_lstadd_back(&head, node);
		}
		i++;
	}
	data->pipe = head;	
}

void print_lists(t_pipe *red)
{
	t_pipe *head;

	head = red;
	while (head)
	{
		printf("content: %s\n", head->content);
		head = head->next;
	}
}
