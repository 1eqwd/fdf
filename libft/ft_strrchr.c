/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:47:57 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:00:01 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	if (!src)
		return (NULL);
	i = ft_strlen(src);
	while (i >= 0)
	{
		if ((unsigned char)src[i] == (unsigned char)c)
			return ((char *)&src[i]);
		i--;
	}
	return (NULL);
}

// int main(void)
// {

// 	char s[] = "tripouille";
// 	char s2[] = "ltripouiel";
// 	char s3[] = "";
// 	// /* 1 */ check(ft_strrchr(s, 't') == s); showLeaks();
// 	// /* 2 */ check(ft_strrchr(s, 'l') == s + 8); showLeaks();
// 	// /* 3 */ check(ft_strrchr(s2, 'l') == s2 + 9); showLeaks();
// 	// /* 4 */ check(ft_strrchr(s, 'z') == NULL); showLeaks();
// 	/* 5 */ check(ft_strrchr(s, 0) == s + strlen(s));
// 	// /* 6 */ check(ft_strrchr(s, 't' + 256) == s); showLeaks();
// 	char * empty = (char*)calloc(1, 1);
// 	//
// 	/* 8 */ check(ft_strrchr(s3, 0) == s3); showLeaks();
// 	write(1, "\n", 1);
// 	return (0);
// }