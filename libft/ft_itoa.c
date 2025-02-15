/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:39:36 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:01:31 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_make(char *put, int num, int len)
{
	int	i;

	i = len - 1;
	while (0 <= i && num != 0)
	{
		put[i--] = ('0' + (num % 10));
		num /= 10;
	}
	put[len] = '\0';
	return (put);
}

static char	*ft_itoaset(int num, int len)
{
	char	*put;

	if (num == INT_MIN)
		return (ft_strjoin("-", "2147483648"));
	put = (char *)malloc(sizeof(char) * (len + 1));
	if (!put)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		put[0] = '-';
	}
	if (num == 0)
	{
		put[0] = '0';
		put[1] = '\0';
	}
	ft_make(put, num, len);
	return (put);
}

char	*ft_itoa(int n)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		return (ft_itoaset(0, 1));
	if (n < 0)
	{
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (ft_itoaset(tmp, len));
}

// int	main(void)
// {
// 	char	*i1;

// 	i1 = ft_itoa(-3623);
// 	// char *i2 = ft_itoa(156);
// 	// char *i3 = ft_itoa(-0);
// 	printf("result = %s\n", i1);
// 	free(i1);
// 	return (0);
// }
