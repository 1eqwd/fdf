/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:59:02 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:01:22 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && 126 >= c)
		return (1);
	else
		return (0);
}
/*#include<ctype.h>
#include <stdio.h>

int	main(void)
{
    printf("%d\n",isprint('\0'));
    printf("%d", ft_isprint('\0'));
    return(0);
}*/
