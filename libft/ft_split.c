/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:18:22 by sumedai           #+#    #+#             */
/*   Updated: 2024/11/21 17:08:42 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int indx)
{
	while (indx >= 0)
	{
		free (str[indx]);
		indx--;
	}
	free (str);
	return (NULL);
}

static	int	ft_len(const char *s, int start, char c)
{
	int	len;

	len = 0;
	while (s[start])
	{
		if (s[start] == c)
			return (len);
		len++;
		start++;
	}
	return (len);
}

static int	ft_indexcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

static char	**ft_mksplit(char **msplit, char const *s, char c, int count)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < count)
	{
		if (s[i] != c)
		{
			msplit[j] = ft_substr(s, i, ft_len(s, i, c));
			if (!msplit[j])
			{
				ft_free(msplit, j);
				return (NULL);
			}
			i += ft_len(s, i, c);
			j++;
		}
		i++;
	}
	msplit[j] = NULL;
	return (msplit);
}

char	**ft_split(char const *s, char c)
{
	char	**msplit;
	int		count;

	if (!s)
		return (NULL);
	count = ft_indexcount(s, c);
	msplit = (char **)malloc(sizeof(char *) * (count + 1));
	if (!msplit)
		return (NULL);
	return (ft_mksplit(msplit, s, c, count));
}

// int main(void)
// {
// 	// char a[] = "";
// 	// char b = ' ';
// 	char **c = ft_split("42",' ');
// 	int i = 0;
// 	while(c[i])
// 	{
// 		printf("%s\n",c[i]);
// 		free(c[i]);
// 		i++;
// 	}
// 	free(c);
// 	return(0);
// }