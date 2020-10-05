#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>

//for test
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *dest, int c, size_t len);
void	ft_bzero(void *b, size_t len);
void	*memcpy(void *dst, const void *src, size_t len);
void	*memccpy(void *dst, const void *src, int c, size_t len);
size_t	ft_strlen(const char *s);

#endif
