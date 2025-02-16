/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:37:09 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/16 17:00:10 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*gnl_remove_trailing_chars(int fd);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*ft_save(char *str);
char	*ft_nextl(char *str);
char	*ft_memadd(char *s1, const char *s2, size_t size);
void	free_str(char **str, int x_len);
void	free_2d_memory(int **array, int height);

#endif
