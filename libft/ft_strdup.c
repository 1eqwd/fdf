/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:17:52 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:03:10 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	return (ft_substr(str, 0, ft_strlen(str)));
}

// int main(void)
// {
//     char *a ="asdfkljaskd";
//     char *b = ft_strdup(a);
//     printf("%s\n",b);
//     free(b);

//     return(0);
// }
