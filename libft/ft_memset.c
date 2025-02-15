/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:32:39 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:02:18 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*d_cpy;
	size_t			i;

	i = 0;
	d_cpy = (unsigned char *)dest;
	while (i < len)
	{
		d_cpy[i] = (unsigned char)c;
		i++;
	}
	return (d_cpy);
}
