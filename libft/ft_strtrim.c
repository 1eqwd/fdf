/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:06:22 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:04:14 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_str_cut(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;
	size_t	i;

	i = 0;
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (!trimmed_str)
		return (NULL);
	while (i < (end - start))
	{
		trimmed_str[i] = s1[start + i];
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1 || !set)
		return (NULL);
	return (ft_str_cut(s1, set));
}

// int main(void)
// {
//     char *a = "asdfsffgas";
//     char *b = "sa";
//     char *c = ft_strtrim(a,b);
//     printf("%s\n",c);
//     free(c);
//     return(0);
// }