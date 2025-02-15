/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:58:17 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:04:21 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mstr;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	i = 0;
	mstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!mstr)
		return (NULL);
	while (s[start] && i < len)
		mstr[i++] = s[start++];
	mstr[i] = '\0';
	return (mstr);
}

// int main()
// {
// 	char a[] = "hola";
//     printf("%d\n",);
//     return (0);
// }
// int main(void)
// {

//     char *str = "01234";
//  	size_t size = 10;
//  	char *ret = ft_substr(str, 10, size);

//  	if (!strncmp(ret, "", 1))
//  	{
//         printf("TEST_SUCCESS");
//  		free(ret);
//     }
//     else
//     {
//         printf("TEST_FAILED");
//  			free(ret);
//     }
//     return(0);
// }