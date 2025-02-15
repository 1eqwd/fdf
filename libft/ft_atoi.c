/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:11 by sumedai           #+#    #+#             */
/*   Updated: 2024/10/11 20:15:30 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		power;
	long	result;

	i = 0;
	power = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			power = -1;
	}
	while (str[i] >= '0' && '9' >= str[i])
	{
		if (result * power > (LONG_MAX - (str[i] - '0')) / 10)
			return ((int)LONG_MAX);
		if (result * power < (LONG_MIN + (str[i] - '0')) / 10)
			return ((int)LONG_MIN);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)result * power);
}

// int main(void)
// {
//    char *n = "+-85";
//  	int i1 = atoi("9223372036854775806");
//  	int i2 = ft_atoi("9223372036854775806");
//    printf("%d\n",i1);
//    printf("%d\n",i2);
//    return(0);
// }
