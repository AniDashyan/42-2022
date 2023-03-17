#include "minishell.h"

t_redirect	*redirect_test(t_pipe *pipe)
{
	int i;
	t_pipe *top = pipe;
	t_redirect	*head = NULL;

	i = 0;
	while (top->content[i] != '\0')
	{
		if (is_redirect_in(top->content[i]) || is_redirect_out(top->content[i]))
			redirect_f_name_flag(top, &head, &i);
		else if (top->content[i] > 32)
			redirect_to_command(top,  &i);
	i++;
	}
	print_list(head);
	return (head);
}

void	redirect_to_command(t_pipe *top, int *i)
{
	int k;
	int l;
	char *tmp1 = ft_strdup(" ");
	char *tmp;
	char *arr;
	t_redirect	*head = NULL;
	
	k= 0;
	l = 0;
	if (*i < ft_strlen(top->content))
	{
		if (top->content[*i] == '\"')
		{
			(*i)++;
			// printf("in havasatr e = %d\n", *i);
			arr = fun(top->content, &(*i));
			top->argv = &arr;
			printf("arr = %s\n", arr);
			// printf("top->argv[%d] = %s\n",l-1, top->argv[l-1]);
			// printf("top->argv[%d] = %s\n", l, top->argv[l]);
		}
		else
		{
			k = (*i)++;
			while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
				(*i)++;
			if ((is_redirect_in(top->content[*i]) || is_redirect_out(top->content[*i])))
				redirect_f_name_flag(top, &head, i);
			tmp = ft_substr(top->content, k, *i - k + 1);
			tmp1 = ft_strjoin(tmp1,tmp);
			printf("TEMP1 = %s\n", tmp1);		
			// printf("top->argv[%d ] = %s\n",l-1, top->argv[l - 1]);
		}
	}
}

void	redirect_f_name_flag(t_pipe *top, t_redirect **head, int *i) 
{
	int x;
	int start;
	char	*tmp;
	x = 1;
	start = 0;
	if (is_append_in(top->content[*i], top->content[*i + 1]) || is_append_out(top->content[*i], top->content[*i + 1]))
		x++;
	tmp = ft_substr(top->content, *i, x);
	*i += x;
	while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
        (*i)++;
	start = *i;
	while (!ft_strchr(METACHARACTER, top->content[*i]))
        (*i)++;
	ft_t_redirect_add_back(head, new_t_redirect(ft_substr(top->content, start, *i - start), tmp));			
	x = 1;
	*i -= 1;
}

char *fun(char *top, int *i)
{
	int first = 0;
	char * str = malloc(sizeof(char));

	first = *i;
	while (top[*i] != '"')
		(*i)++;
	// printf("first %i\n ",first);
	str =  ft_substr(top, first, *i - first);
	// printf("str: %s\n ", str);
    return (str);
}
