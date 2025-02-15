/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:39 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:05:06 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && 'z' >= c)
	{
		c -= 'a' - 'A';
		return (c);
	}
	else
		return (c);
}

// #include<ctype.h>
// #include<stdio.h>
// int main(void)
// {
//     printf("%c\n", toupper('B'));
//     printf("%c\n", ft_toupper('r'));
//     return(0);
// }
