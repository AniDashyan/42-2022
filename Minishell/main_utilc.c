#include "minishell.h"

int  for_space(char *ptr, char c, int i)
{
    if (ptr[i] == c)
    {
        i++;
        while(ptr[i] != c)
            i++;        
    }   
    i++;
    return (i);
}

// char    *hendl_dolar(t_data *data, char *str);
// void hendl_dolar(t_data *data)
// {
    
//     int i;
//     int j;
//     char *str;
//     char *str1;
//     int len;
       
//     i = 0;
//     j = 0;
//     // data->pipe->argv[0] = "$HOME";
//     // data->pipe->argv[1] = NULL;
//     while (data->pipe->argv[i])
//     {
//         str = data->pipe->argv[i];
//         len = 0;
        
//         printf("str = %s\n",str);
//         while (str[j])
//         {
//             if (str[j -1] != '\'' && str[j] == '$' && (ft_isalpha(str[j+1]) || str[j+1] == '_'))
//             {
//                 j++;
//                 len = j;
//                 while((ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
//                 {
//                     j++;
//                 }
//                 str1 = ft_substr(str,len,j - len);
//     // printf("barev\n");

//                 printf("str1 = %s\n",str1);
//                 fun1(data, str1, i);
//                 j--;
            
//             }
//             j++;

//         }
//         i++;
//         printf("j:%d\n",j);
//     }
// }

// void fun1(t_data *data, char *str1,int i)
// {
//     t_env *head;
//     int len;
//     // int k = 0;

//     head = data->head_env;    
//     while (head)
//     {       
//         if (ft_strcmp(head->key , str1) == 0)
//         {
//             len = ft_strlen(head->val);
//             data->pipe->argv[i] = malloc(sizeof(char) * (len + 1));
//             data->pipe->argv[i] = head->val;
//             printf("data->head_env->val%s\n",head->val);
//             printf("data->pipe->argv[i]%s\n",data->pipe->argv[i]);
//         }

//         head = head->next;           
//     }
// }















