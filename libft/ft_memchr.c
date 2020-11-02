/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:10:55 by haseo             #+#    #+#             */
/*   Updated: 2020/11/01 15:01:45 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char *	uc_b;

	uc_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		if (uc_b[i] == (unsigned char)c)
			return ((void *)(uc_b + i));
		i++;
	}
	return (NULL);
}
