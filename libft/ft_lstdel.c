/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:28:49 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/03 16:49:56 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *copy;
	t_list *nextlist;

	copy = *alst;
	while (copy)
	{
		nextlist = copy->next;
		del(copy->content, copy->content_size);
		free(copy);
		copy = nextlist;
	}
	*alst = NULL;
}
