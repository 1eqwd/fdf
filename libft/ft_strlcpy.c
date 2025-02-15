/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:13 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:03:43 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

// #include <string.h>
// int main(void)
// {
//     char src[] = "coucou";
//     char dest[]="AAAAAAAAAA";
//     // printf("%zu\n",ft_strlcpy(dest, src, 0));
//     // printf("%c",dest[0]);
// 	/* 2 */ printf("%zu\n",ft_strlcpy(dest, src, 1));
//     printf("%c %c", dest[0], dest[1]);
//     return (0);
// }
