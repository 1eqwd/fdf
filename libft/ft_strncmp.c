/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:29 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:04:00 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)str1;
	s2_cpy = (unsigned char *)str2;
	i = 0;
	while ((s1_cpy[i] && s2_cpy[i]) && i < len)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		i++;
	}
	if (i == len)
		return (0);
	return (s1_cpy[i] - s2_cpy[i]);
}

// int main(void)
// {
//     int size = 8539;

//  	void * d1 = ft_calloc(size, sizeof(int));
//  	void * d2 = calloc(size, sizeof(int));
//    if (memcmp(d1, d2, size * sizeof(int)))
//  		printf("TEST_FAILED");
//     free(d1);
//  	free(d2);
//     printf("TEST_SUCCESS");
//     return(0);
// }
