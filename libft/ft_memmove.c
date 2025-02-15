/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:08:17 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/22 21:37:43 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (dst == src)
		return (dst);
	if (dst > src)
	{
		index = len;
		while (index > 0)
		{
			index--;
			((char *)dst)[index] = ((char *)src)[index];
		}
	}
	else
	{
		index = 0;
		while (index < len)
		{
			((char *)dst)[index] = ((char *)src)[index];
			index++;
		}
	}
	return (dst);
}
//  int main(void)
//  {
//      char a[] = "abc";
//      char *b =ft_memmove(a+4,a,4);
//      char *c = memmove(a+4,a,4);
//      printf("%s\n",b);
//      printf("%s\n",c);
//      return(0);
// }
