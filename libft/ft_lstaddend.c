/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:52:13 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/06 14:29:32 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*current;

	current = *alst;
	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}
