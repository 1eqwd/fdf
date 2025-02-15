/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:24:04 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:00:36 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	*arrge;

	if (!number || !size)
		return (malloc(0));
	if (number > LONG_MAX / size)
		return (NULL);
	arrge = (void *)malloc(number * size);
	if (!arrge)
		return (NULL);
	ft_bzero(arrge, number * size);
	return (arrge);
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
