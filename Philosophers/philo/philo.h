/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:46:50 by adashyan          #+#    #+#             */
/*   Updated: 2023/01/14 18:01:42 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philo_must_eat;
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
void	error(char *msg);
void	ft_putstr_fd(char *s, int fd);
int		check_arg(char **argv, int argc);
int		ft_atoi(const char *str);
void	sign_error(char *str, int *i, int *sign);
void	num_error(char *str);
void	fake_atoi(char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	print_philo(t_philo *philo, int argc);
void	fill_args(t_philo *philo, char **argv, int argc);

#endif
