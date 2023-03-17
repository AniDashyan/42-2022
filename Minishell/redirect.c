#include "minishell.h"

void print_list(t_redirect *red)
{
	t_redirect *head;

	head = red;
	while (head)
	{
		// printf("flag: %s \n ", head->flag);
		printf("f_name: %s\n", head->f_name);
		// printf("type: %s\n", head->type); // miangaminic grel "char **argv" i mech
		head = head->next;
	}

	head = red;

	while (head)
	{
		printf("flag: %s\n", head->flag);
		// printf("f_name: %s \n ", head->f_name);
		// printf("type: %s\n", head->type); // miangaminic grel "char **argv" i mech
		head = head->next;
	}
}

void print_list_head_env(t_env *head_env)
{
	t_env *head;

	head = head_env;
	// printf("head->key:: %s\n", head->key);
	while (head)
	{
		printf("head->key: %s\n, head->val: %s\n, ", head->key, head->val);
		// printf("hey\n");
		if(head->next == NULL)
			return;
		head = head->next;
	}
	// printf("HEEELOO\n");
}
void send_env(t_data *data)
{
	t_env	*head;
	char	*str;
	char	*str1 = ft_strdup(" ");

	head = data->head_env;
	while (head->next)
	{
		str = ft_strjoin(head->key,"=");
		str = ft_strjoin(str,head->val);
		str = ft_strjoin(str," ");
		// data.env = &str;
		str1 = ft_strjoin(str1,str);
		head = head->next;
	}
printf("str1=%s\n", str1);
data->env = ft_split(str1, ' ');
}

void print_env(t_data *data)
{
	int i = 0;
	while (data->env[i])
	{
		printf("data.env = %s\n", data->env[i]);
		i++;
	}	

}
