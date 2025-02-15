/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:15:57 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:01:41 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*s_cpy;
	size_t			i;

	i = 0;
	if (!src && c == 0 && !len)
		return (NULL);
	s_cpy = (unsigned char *)src;
	while (i < len)
	{
		if (s_cpy[i] == (unsigned char)c)
			return (&s_cpy[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//    // char s[] = {0, 1, 2 ,3 ,4 ,5};
//     char c[] = ft_memchr(((void *)0), '\0', 0x20);//ft_memchr(s,2 + 256,3);
//     char d[] = memchr(((void *)0), '\0', 0x20);//memchr(s,2 +256,3);
//    printf("%s\n", c);
//    printf("%s\n",d);
//    return(0);
// }
