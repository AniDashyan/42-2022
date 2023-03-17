#include "minishell.h"

void unset_buildin(t_data *data, char *ptr)
{
    t_env *head;
    t_env *tmp;
    char **str;
    char **str1;
    int i;

    i = 1;
    str = ft_split(ptr,' ');
    while (str[i])
    {
        str1 = ft_split(str[i], '=');
        head = data->head_env;
        while (head)
        {
            // ft_list_remove_if(lst,a,strcmp);
            if (ft_strcmp(str1[0], head->next->key) == 0)
            {
                tmp= head->next;
                head=head->next->next;
                free(tmp);
                break;
            } 
            
            if(head->next == NULL)
                return;
            head = head->next;
        }
        i++;
    }
}
