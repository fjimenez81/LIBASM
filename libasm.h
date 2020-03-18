/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 21:19:31 by fernando          #+#    #+#             */
/*   Updated: 2020/03/18 13:57:48 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# define BGREEN	    "\033[1;32m"
# define YELLOW	    "\033[0;33m"
# define MAGENTA	"\033[0;36m"
# define COLOR	    "\033[1;31m"
# define WHITE	    "\033[0m"

# include <string.h>
# include <stdio.h>
# include <unistd.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char * dst, const char * src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t read(int fildes, void *buf, size_t nbyte);

#endif