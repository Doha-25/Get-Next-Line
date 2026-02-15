/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbani-ya <dbani-ya@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:06:49 by dbani-ya          #+#    #+#             */
/*   Updated: 2026/02/03 13:41:05 by dbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char	*s);
char	*get_next_line(int fd);

#endif
