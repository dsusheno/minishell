/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:19:52 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 17:19:12 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *copy;
	t_list *start;

	if (lst && f)
	{
		copy = ft_lstnew(lst->content, lst->content_size);
		if (!copy)
			return (NULL);
		copy = f(lst);
		start = copy;
		while (lst->next)
		{
			copy->next = f(lst->next);
			copy = copy->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
