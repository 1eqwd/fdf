/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:12:41 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/22 14:24:26 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while(lst->next)
        lst = lst->next;
    return (lst);
}

// int main(void)
// {
//     t_list *l;
//  	t_list *expected;
//  	t_list *actual;

//  	l = ft_lstnew(strdup("1"));
//  	l->next = ft_lstnew(strdup("2"));
//  	l->next->next = ft_lstnew(strdup("3"));
//  	expected = l->next->next;
//  	actual = ft_lstlast(l);
//  	printf("expected=%p :actual=%p\n", expected, actual);
// }