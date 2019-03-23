/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:46:51 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:46:52 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unichr(int chr)
{
	char	res[5];

	ft_bzero(res, 5);
	if (chr < 128 || MB_CUR_MAX == 1)
		res[0] = chr;
	else if (chr < 2048)
	{
		res[0] = (chr >> 6) + 192;
		res[1] = (chr & 63) + 128;
	}
	else if (chr < 65536)
	{
		res[0] = (chr >> 12) + 224;
		res[1] = ((chr >> 6) & 63) + 128;
		res[2] = (chr & 63) + 128;
	}
	else if (chr < 2097152)
	{
		res[0] = (chr >> 18) + 240;
		res[1] = ((chr >> 12) & 63) + 128;
		res[2] = ((chr >> 6) & 63) + 128;
		res[3] = (chr & 63) + 128;
	}
	return (ft_strdup(res));
}
