/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:36:57 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/27 16:48:42 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Used libraries */
# include <unistd.h> /* usleep(), write() */
# include <stdlib.h> /* malloc() */
# include <pthread.h> /* pthread_*(), mutex */
# include <stdio.h> /* printf() */
# include <sys/time.h> /* gettimeofday() */
/* -------------- */

/*--------------- Constants ----------------*/

/* Actions */
# define LEFT "has taken the left fork🍴"
# define RIGHT "has taken the right fork🍴"
# define EAT "is eating🍝"
# define SLEEP "is sleeping😴"
# define THINK "is thinking🤔"
# define DEATH "is dead😵"
/* ------ */

/* Colours */
# define RED "\033[1;31m"
# define BLUE "\033[34m"
# define ORANGE "\033[38;5;208m"
# define GREEN "\033[32m"
# define WHITE "\033[0m"
/* ------- */

/* Errors */
# define ERR_MALLOC "Error: Could't allocate memory\n"
# define ERR_ARG "Error: Invalid arguments!\n"
/* ----- */

/* ------------------------------------------ */

/* --------------- Philo structs ---------------- */

typedef pthread_mutex_t		t_mutex;

typedef struct s_data
{
	int				num_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_must_eat;
	long			start_time;
	long			cur_time;
	t_mutex			print_lock;
	t_mutex			l_eat_lock;
	t_mutex			death_lock;
}					t_data;

typedef struct s_philo
{
	int				index;
	int				last;
	double			last_eat;
	pthread_t		pid;
	t_mutex			*right_fork;
	t_mutex			*left_fork;
	t_data			*data;
}					t_philo;

typedef struct s_main
{
	t_mutex			*forks;
	t_philo			*p;
	t_data			data;
}					t_main;

/* ---------------------------------------------- */

/* --------------- Functions ---------------- */

/* Argument parsing --- args_validation.c */
int			ft_atoi(const char *str);
int			check_arg(char **v, int c);
/* -------------------------------------- */

/* utils --- ft_utils.c */
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *s);
int			ft_isspace(char c);
int			ft_isdigit(int c);

/* Init --- init.c */
int			init_mutexes(t_main *main);
int			init(t_main *main, int argc, char **argv);
void		create_thread(t_main *main);
/* --------------- */

/* time management --- time.c */
void		ft_usleep(long ms);
long double	get_time(void);
/* -------------------------- */

/* Error handling --- error.c */
void		error(char *msg);
/* -------------------------- */

/* death check --- death.c */
int			check_death(t_philo *p);
int			death_cond(t_main *main);
/* ----------------------- */

/* print */
void		print(t_philo *p, char *str, char *col);
/*-------------------------------------------*/
#endif