/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:35:03 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/11 21:03:09 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;

	if (!lst)
		return (NULL);
	new_lst = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}

void	*ft_capitalize(void *str)
{
	int		len;
	int		i;
	char	*origin;
	char	*str_cap;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	i = 0;
	origin = (char *)str;
	str_cap = (char *)malloc(len);
	if (!str_cap)
		return (NULL);
	while (origin[i])
	{
		if (origin[i] >= 'a' && origin[i] <= 'z')
		{
			str_cap[i] = origin[i] - 32;
		}
		i++;
	}
	str_cap[len] = '\0';
	return (str_cap);
}
