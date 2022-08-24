/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 20:34:46 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/21 09:37:09 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*addlst;

	if (!lst)
		return (0);
	newlst = 0;
	while (lst)
	{
		addlst = ft_lstnew(f(lst->content));
		if (!addlst)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, addlst);
		lst = lst->next;
	}
	return (newlst);
}
