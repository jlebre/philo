/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:16 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/30 19:36:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <sys/time.h> 
# include <pthread.h>
# include <bits/pthreadtypes.h>

# define INT_MAX    2147483647
# define INT_MIN    -2147483648

//Struct for Philo
typedef struct s_philo
{
	int				number_of_philo;
	struct timeval  time;
	pthread_mutex_t *fork;
	pthread_t		philo;
	//t_data		*global;
}   t_philo;

//Struct for General Info

typedef struct s_args
{
	int 			number_of_philo;
	int 			*fork;
	struct timeval  s_time;
	long long 		time_to_die;
	long long 		time_to_eat;
	long long 		time_to_sleep;
	long long 		start_time;
	long long 		last_meal;
	int				number_of_meals;
	int				temp;
	t_philo			*philo;
}   t_args;

//STRUCTS
t_args		*args(void);
t_args		*philos(void);

//START ARGS
int			start_args(int argc, char **argv);

//CHECK
int			check(char **argv);
int			check_limits(char **argv);
int			check_all_int(char **argv);

//CREATE PHILO
void		create_philo(void);

//DESTROY PHILO
void    	destroy_philo(void);

//ROUTINE
void		*routine(void *arg);
void		think(int nb);
void		nap(int nb);
void		eat(int nb);
int			check_fork(int nb);

//TIME
long long	time_ms();
long long	current_time();

//UTILS
int			is_dead(int i);
int			ft_isdigit(int i);
int			ft_atoi(const char *str);
long long	ft_atol(const char *str);

//COLORS
//Normal Colors
int			black(char *str);
int			red(char *str);
int			green(char *str);
int			yellow(char *str);
int			blue(char *str);
int			purple(char *str);
int			cyan(char *str);
int			white(char *str);
//Bold
int			bold_black(char *str);
int			bold_red(char *str);
int			bold_green(char *str);
int			bold_yellow(char *str);
int			bold_blue(char *str);
int			bold_purple(char *str);
int			bold_cyan(char *str);
int			bold_white(char *str);

#endif
