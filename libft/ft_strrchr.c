/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:15:03 by haseo             #+#    #+#             */
/*   Updated: 2020/11/02 16:10:39 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char	*begin;

	begin = (char *)s;
	while (*s++);
	while (s >= begin)
	{
		if(*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
