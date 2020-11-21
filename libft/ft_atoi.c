/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:39:32 by haseo             #+#    #+#             */
/*   Updated: 2020/11/21 00:50:49 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f');
}

int ft_atoi(const char *nptr)
{
	int		pos;
	int		num;
	int		len;

	pos = 1;
	num = 0;
	len = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			pos = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + *nptr++ - '0';
		len++;
	}
	if (len >= 20 && (pos == -1 || num == 0))
		return (0);
	else if (len >= 20 && pos == 1)
		return (-1);
	return (pos * num);
}
