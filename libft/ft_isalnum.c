/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:46:16 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:00:49 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && 'z' >= c) || (c >= 'A' && 'Z' >= c))
		return (1);
	else if (c >= '0' && '9' >= c)
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>

int	main(void)
{
    printf("%d\n", isalnum('3'));
    printf("%d\n", ft_isalnum('4'));
    return(0);
}*/
