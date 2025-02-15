/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:45:10 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:02:03 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d_cpy;
	const char	*s_cpy;
	size_t		i;

	i = 0;
	d_cpy = (char *)dest;
	s_cpy = (const char *)src;
	if (!d_cpy && !s_cpy)
		return (dest);
	while (i < len)
	{
		d_cpy[i] = s_cpy[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
//     char a[] = "AAAAAAAAA";
//     char b[] ={0,0};
//     char *result;

//    result = memcpy(a,b,2);
//     printf("%s\n",result);
//     printf("%s\n",ft_memcpy(a,b,2));
//     return(0);
// }
