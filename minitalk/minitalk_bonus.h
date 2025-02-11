/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:36:01 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/11 09:06:15 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# define EPPY 100

//in client_utils.c
size_t	ft_strlen(const char *str);
int		ft_iswhitespace(char c);
int		ft_isdigit(int a);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);

//in server_utils.c
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

//in common_file.c
void	handler(int sig);
int		ft_recursive_power(int nb, int power);
int		print_str(pid_t pid, char *str, int *cur_bit_pos, int sig);

#endif