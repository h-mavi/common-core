/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:31:34 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/24 18:17:41 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' \
		|| c == '\v' || c == '\r' || c == '+')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	num = num * sign;
	return (num);
}
/* int main(void)
{
	char *test_cases[] = {
		"42",
		"-42",
		"  42",
		"  \t  42",
		"  -1234",
		"+1234",
		"0",
		"-0",
		"  \t +123abc",
		"abc123",
		"  +2147483647",
		"  -2147483648", 
		"  99999999999999", 
		NULL
	};

	
	for (int i = 0; test_cases[i] != NULL; i++) {
		int result = ft_atoi(test_cases[i]);
		int res = atoi(test_cases[i]);
		printf("Input: \"%s\", ft_atoi: %d  %d\n", test_cases[i], result, res);
	}
} */