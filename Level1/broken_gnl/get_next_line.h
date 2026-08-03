/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.h                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/03 09:42:05 by username         #+#    #+#              */
/*   Updated: 2026/08/03 09:42:40 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *ft_strchr(char *s, int c);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t ft_strlen(char *s);
int str_append_mem(char **s1, char *s2, size_t size2);
int str_append_str(char **s1, char *s2);
void *ft_memmove(void *dest, const void *src, size_t n);
char *get_next_line(int fd);



#endif
