/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:36:01 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/06 17:19:27 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# define EPPY 100

//in server
void	recive_from_client(int sig);
void	reset(int *len_recived, char **str, int *i);
void	count_len(int *cur_bit_pos, int *len_recived, char **str, int signal);
int	    ft_recursive_power(int nb, int power);

//in client
void	ft_send_str(int pid, char c);
void	ft_send_strlen(int pid, int len);
int 	ft_check_errors(int argc, char *argv[]);

#endif