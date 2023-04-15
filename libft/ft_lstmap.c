/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:43:06 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/26 15:38:34 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmp_lst;
	void	*tmp_f;

	newlist = NULL;
	if (!lst)
		return (0);
	while (lst)
	{
		tmp_f = f(lst->content);
		tmp_lst = ft_lstnew(tmp_f);
		if (!tmp_lst)
		{
			del(tmp_f);
			ft_lstclear(&newlist, del);
			newlist = NULL;
			return (0);
		}
		ft_lstadd_back(&newlist, tmp_lst);
		lst = lst->next;
	}
	return (newlist);
}
