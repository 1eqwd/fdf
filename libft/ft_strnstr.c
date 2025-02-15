/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:03:14 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:04:07 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] && i + j < len)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	if (little[0] == '\0')
		return ((char *)big);
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!big || !little)
		return (NULL);
	return (ft_check(big, little, len));
}

// int main(void)
// {
//     printf("%s\n",ft_strnstr("lorem ipsum dolor sit amet", "", 10));
//     printf("%s\n",strnstr("lorem ipsum dolor sit amet", "", 10));
// 	return (0);
// }
