/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:55:02 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/05 15:00:25 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}

// int main(void)
// {
//     char c[] = "asddcxz";
//     char d[] = "asddcxz";
//     bzero(c+3, 3);
//     ft_bzero(d+3, 3);
//     printf("%s\n",c );
//     printf("%s\n",d);
//     return(0);
// }
