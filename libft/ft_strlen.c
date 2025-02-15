/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:02:56 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:03:49 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include<string.h>
// #include<stdio.h>
// int main(void)
// {
//     char *a = "asdfb";
//     int s = 0;
//     s = strlen(a);
//     printf("%d\n", s);
//     printf("%zu\n", ft_strlen(a));
// }
