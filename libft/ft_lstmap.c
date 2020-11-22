/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:55:13 by haseo             #+#    #+#             */
/*   Updated: 2020/11/22 22:20:29 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *cur;
	t_list *tmp;

	if (!lst || !f || !del)
		return (NULL);
	cur = lst;
	while(cur)
	{
		if (!(tmp = ft_lstnew((*f)(cur->content))))
		{
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		cur = cur->next;
	}
	return (new_lst);
}
