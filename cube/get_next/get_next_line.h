/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:28:27 by mballa            #+#    #+#             */
/*   Updated: 2023/10/03 17:20:11 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_data
{
	char			*buff;
	char			*line;
	int				rd;
}					t_data;

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_str_len_dup(const char *s1, size_t len);
char	*ft_strchr(char *s, char c);
char	*get(char *s1);
char	*get_remember(char *s1);
char	*ft_free(char *saver);
int		ft_first_check(int fd, t_data *data);
#endif