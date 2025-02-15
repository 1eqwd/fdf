/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:52:55 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:00:58 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && 'Z' >= c) || (c >= 'a' && 'z' >= c))
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>

int	main(void)
{
    char a = '1';

    printf("%d\n" ,isalpha(a));
    printf("%d\n", ft_isalpha(a));
}*/
