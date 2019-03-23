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

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list_el
{
	void				*data;
	size_t				size;
	struct s_list_el	*next;
}				t_list_el;

typedef struct	s_list
{
	t_list_el	*head;
	t_list_el	*last;
	size_t		size;
	size_t		count;
}				t_list;

#endif
