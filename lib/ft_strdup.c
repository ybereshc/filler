/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:00:27 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 14:00:28 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	return (ft_strsub(str, 0, n));
}

char	*ft_strdup(char *str)
{
	return (str ? ft_memcpy(0, str, ft_strlen(str) + 1) : 0);
}
