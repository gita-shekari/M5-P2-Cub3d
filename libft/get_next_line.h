/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdong <jdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 14:39:33 by jdong         #+#    #+#                 */
/*   Updated: 2026/02/13 18:36:07 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//include functions in get_next_line_utils
size_t	ft_gstrlen(const char *str);
void	*ft_gcalloc(size_t nmemb, size_t size);
size_t	ft_gstrlcpy(char *dst, const char *src, size_t size);
size_t	ft_gstrlcat(char *dst, const char *src, size_t size);
int		ft_gstrchr(char *s, int c);
//get next line functions.
char	*combine_buffers(char *buffer, char *temp_buf, size_t temp_len);
char	*get_contents(char *buffer, int fd);
char	*get_curr_line(char *buffer);
char	*new_line_pointer(char	*buffer);
char	*get_next_line(int fd);

#endif