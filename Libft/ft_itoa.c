/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:21:24 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 11:36:59 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	n_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (n == 0)
		len = 1;
	return (len);
}

static char	*int_min(char	*ptr)
{
	int		i;
	char	*int_min;

	i = 0;
	int_min = "-2147483648";
	while (int_min[i] != '\0')
	{
		ptr[i] = int_min[i];
		i++;
	}
	return (ptr);
}

static void	write(char *ptr, int len, int ex)
{
	while (len--)
	{
		ptr[len] = ex % 10 + '0';
		ex /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		ex;

	ex = n;
	len = n_len(n);
	if (n < 0)
	{
		ex *= -1;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (n == -2147483648)
	{
		ptr = int_min(ptr);
		return (ptr);
	}
	write(ptr, len, ex);
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

/* int	main(void)
{
	int	a = 0;
	int b = -2147483648;
	char	*aptr;
	char	*bptr;
	aptr = ft_itoa(a);
	bptr = ft_itoa(b);
	printf("%s", aptr);
	printf("\n%s", bptr);
	free(aptr);
	free (bptr);
} */
