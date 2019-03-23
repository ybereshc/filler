/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:04:27 by ybereshc          #+#    #+#             */
/*   Updated: 2018/11/24 19:04:38 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*list_new(void)
{
	return (ft_bzmalloc(sizeof(t_list)));
}

t_list_el	*list_push(t_list *list, void *data, size_t size)
{
	t_list_el	*el;

	if (!list)
		return (0);
	el = malloc(sizeof(t_list_el));
	el->data = data;
	el->size = size;
	el->next = 0;
	if (list->last)
		list->last->next = el;
	list->last = el;
	if (!list->head)
		list->head = el;
	list->size += size;
	list->count++;
	return (el);
}

t_list_el	*list_remove(t_list *list, void *ptr)
{
	t_list_el	**el;
	t_list_el	*tmp;
	t_list_el	*perent;

	if (!list)
		return (0);
	el = &list->head;
	perent = 0;
	while (*el)
	{
		if ((*el)->data == ptr)
		{
			if ((tmp = *el) == list->last)
				list->last = perent;
			*el = (*el)->next;
			list->size -= tmp->size;
			list->count--;
			free(tmp);
			return (ptr);
		}
		perent = *el;
		el = &(*el)->next;
	}
	return (0);
}

t_list_el	*list_get(t_list *list, intmax_t n)
{
	t_list_el	*el;

	n = n < 0 ? list->count + n : n;
	if (!list || n < 0 || (size_t)n >= list->count)
		return (0);
	el = list->head;
	while (n--)
		el = el->next;
	return (el);
}
