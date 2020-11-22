/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:13:40 by haseo             #+#    #+#             */
/*   Updated: 2020/11/23 01:00:38 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list *tmp;
	
	if (!lst)
		return (NULL);
	tmp = lst;
	while(tmp->next)
		tmp = tmp->next;
	return (tmp);
}
