/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:11:46 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:03:36 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	while (dest_len + i < dstsize - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int main(void)
// {
//     char a[8] = "asdv";
//     char b[] = "adc";
//     printf("%zu\n" ,strlcat(a,b,3));
//     printf("%zu\n", ft_strlcat(a,b,3));
//     return(0);
// }