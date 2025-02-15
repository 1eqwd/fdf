/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:54:21 by sumedai           #+#    #+#             */
/*   Updated: 2024/09/21 15:54:30 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *centent)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = centent;
    new_node->next = NULL;
    return(new_node);
}