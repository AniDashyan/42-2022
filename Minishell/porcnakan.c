// #include "minishell.h"

// void hendl_dolar(t_data *data, char *str)
// {
    
//     int i;
//     int j;    
//     char *str1;
//     char *val;

//     i = 0;
//     j = 0;    
//     // int len_val = 0;
//     while (str[j])
//     {
//         if (str[j -1] != '\'' && str[j] == '$' && (ft_isalpha(str[j+1]) || str[j+1] == '_'))
//         {
//             j++;
//             i = j;
//             while((ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
//                 j++;
//             str1 = ft_substr(str,i,j - i);
//             data-> len_key_sum += ft_strlen(str1);
//             val = fun1(data, str1);
//             j--;
//             // printf("str1 = %s\n",  str1);
//             // printf("len_key_sum = %d\n",data->len_key_sum);
//         }
//         j++;
//     }    
//     // printf("len_key_sum = %d\n", data->len_key_sum);
// }

// char *fun1(t_data *data, char *str1)
// {
//     t_env *head;
//     char *str;
// //    /* static */ int len_val_sum;

//     // len_val_sum = 0;
//     str = NULL;
//     head = data->head_env;
//     while (head)
//     {       
//         if (ft_strcmp(head->key , str1) == 0)
//         {
//             str = head->val;
//             // printf("val = %s\n", str);
//             data->len_val_sum += ft_strlen(str);
//         }
//         head = head->next;
//     }
//     // printf("len_val_sum = %d\n", data->len_val_sum);
//     // printf("******\n");

//     return (str);
// }

// // t_redirect	*redirect_test(t_pipe *pipe) ;
// char *hendl_dolar_inline(t_data *data, char *str)
// {
    
//     int i;
//     int j;    
//     char *str1 = NULL;
//     char *val;

//     i = 0;
//     j = 0;    
//     // int len_val = 0;
//     while (str[j])
//     {
//         if (str[j -1] != '\'' && str[j] == '$' && (ft_isalpha(str[j+1]) || str[j+1] == '_'))
//         {
//             j++;
//             i = j;
//             while((ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
//                 j++;
//             str1 = ft_substr(str,i,j - i);
//             data-> len_key_sum += ft_strlen(str1);
//             val = fun1(data, str1);
//             j--;
//             // printf("str1 = %s\n",  str1);
//             // printf("len_key_sum = %d\n",data->len_key_sum);
//         }
//         j++;
//     }    
//     return (str1);
// }

// int main(int ac,  char **av,  char **env)//kaskaceli e Tatevi hamar u shaaat 
// {
// 	(void)(av+ac);
// 	int j;
//     int i;
// 	t_data	data;
    
// 	char *ptr;
//     char *str1;
//     int len;
//     int p;
// 	j = 0;
//     i = 0;
// 	 struct_zeroed(&data, env);
// 	// init(&data, env);
// 	// printf("%s\n", ft_get_value("PATH", &data));
// 	// char	*test = "la -la \"$PWD\"$HOME $SFAFSF biuhbui $PWD  '$HOME'  sdgsdg";
// 	char	*test = "la -la  'kshja' \"$OKK0M\" \"\"$PWD\"$HOME $SFAFSF biuhbui $PWD barev okokok '$HOME'  sdgsdg";

//     len = ft_strlen(test);
//     // printf("len%d\n", len);


//     hendl_dolar(&data, test);
//     ptr = malloc(sizeof(char)*(len - data.len_key_sum+data.len_val_sum + 1));    		
//     p = len - data.len_key_sum+data.len_val_sum;
//     printf("%d\n", p);
//     while(test[j])
// 	{
        
//         if (test[j -1] != '\'' && test[j] == '$' && (ft_isalpha(test[j+1]) || test[j+1] == '_'))
//         {
//             // printf("HE\n");
//             j++;
//             i = j;
//             while((ft_isalpha(test[j]) || test[j] == '_' || ft_isdigit(test[j])))
//                 j++;
//             str1 = ft_substr(test,i,j - i);
//             fun1(&data, str1);
//             // data-> len_key_sum += ft_strlen(str1);
//             if(fun1(&data, str1) != NULL)
//             {
//                 ptr = fun1(&data, str1);
//                 printf(" %s", ptr);
//             }
//             j--;
//             // printf("str1 = %s\n",  str1);
//             // printf("len_key_sum = %d\n",data->len_key_sum);
//         }
//        /*  if (test[j] != '\"' || test[j] != '$') */
//        else{
//             ptr = ft_substr(test, j, 1);
//               printf("%s", ptr);
//         // printf("j = %c", test[j]);
//         }
//         j++;
// 	}
// //    printf("ptr_verj = %s", ptr);
// 	return (0);
// }