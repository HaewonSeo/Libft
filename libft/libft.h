#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

//for test
#include <string.h>
#include <stdio.h>

//Part 1
//memeory
void		*ft_memset(void *dest, int c, size_t len);
void		ft_bzero(void *b, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *b, int c, size_t len);
int			ft_memcmp(const void *b1, const void *b2, size_t len);
//string
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
//utilization
int			ft_atoi(const char *nptr);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
//malloc
void		*ft_calloc(size_t number, size_t size);
char		*ft_strdup(const char *str);


//Part 2


//Bonus


//Others
size_t		ft_isspace(char c);

#endif
