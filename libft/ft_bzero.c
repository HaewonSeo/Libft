/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:59:18 by haseo             #+#    #+#             */
/*   Updated: 2020/10/31 20:03:23 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = b;
	while (i < len)
		str[i++] = 0;
}

int		main(void)
{
	char str[] = "aaa aaa1";

	printf("%s\n", str);
	bzero(str, 3);
	printf("%s\n", &str[4]);

	char str2[] = "bbb bbb2";
	printf("%s\n", str2);
	ft_bzero(str2, 3);
	printf("%s\n", &str2[4]);

	return (0);
}
