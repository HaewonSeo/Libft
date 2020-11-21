/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:38:13 by haseo             #+#    #+#             */
/*   Updated: 2020/11/21 00:33:37 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_intlen(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		pos;

	pos = 1;
	len = ft_intlen(n);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		pos = -1;
		n = -n;
	}
	while(len)
	{
		str[--len] = '0' + (n % 10);
		n = n / 10;
	}
	if (pos == -1)
		str[0] = '-';
	return (str);
}
