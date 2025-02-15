/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:17:40 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:01:54 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*b2_copy;
	unsigned char	*b1_copy;
	size_t			i;

	i = 0;
	b1_copy = (unsigned char *)b1;
	b2_copy = (unsigned char *)b2;
	if (!b1_copy && !b2_copy)
		return (0);
	while (i < len)
	{
		if (b1_copy[i] != b2_copy[i])
			return (b1_copy[i] - b2_copy[i]);
		i++;
	}
	if (i == len)
		return (0);
	return (b1_copy[i] - b2_copy[i]);
}

// int main(void)
// {
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};

//     int v = ft_memcmp(s2,s3,4);
//     int e = memcmp(s2,s3,4);
//     printf("%d\n",v);
//     printf("%d\n",e);

//     return(0);
// }
