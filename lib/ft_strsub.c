/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:46:51 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:46:52 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *str, size_t pass, size_t n)
{
	char	*res;
	size_t	str_len;

	if (!n || !str)
		return (0);
	str_len = ft_strlen(str);
	if ((str + pass) > (str + str_len))
		return (0);
	str += pass;
	if (n > str_len)
		return (ft_strdup(str));
	res = ft_memcpy(malloc(n + 1), str, n);
	res[n] = '\0';
	return (res);
}
