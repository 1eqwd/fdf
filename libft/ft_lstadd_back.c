/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:12:20 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/22 14:32:54 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    if (!new)
        return ;
    if (!*lst)
        *lst = new;
    else
    {
        tmp = *lst;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

// int main(void)
// {
//     t_list *begin = NULL;
//     t_list *elem = ft_lstnew(strdup("lorm"));
//     t_list *elem2 = ft_lstnew(strdup("chanc"));
//     t_list *elem3 = ft_lstnew(strdup("gds"));
//     ft_lstadd_back(&begin, elem);
//     ft_lstadd_back(&begin, elem2);
//     ft_lstadd_back(&begin, elem3);
    
//     while(begin)
//     {
//         printf("%s\n" ,(char *)begin->content);
//         begin = begin->next;
//     }
//     return (0);
//     ft_lstclear(&begin, free);
// }