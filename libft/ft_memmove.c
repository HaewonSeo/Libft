/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:16:17 by haseo             #+#    #+#             */
/*   Updated: 2020/11/02 15:46:19 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	i = 0;
	char_dst = dst;
	char_src = (unsigned char *)src;
	if (char_dst < char_src)
	{
		while (i < len)
		{
			char_dst[i] = char_src[i];
			i++;
		}
	}
	else
	{
		i++;
		while (i <= len)
		{
			char_dst[len - i] = char_src[len - i];
			i++;
		}
	}
	return (dst);
}
