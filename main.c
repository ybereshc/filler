/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:50:21 by ybereshc          #+#    #+#             */
/*   Updated: 2018/12/10 19:50:32 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n <= -10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(-(n % 10));
		return ;
	}
	if (n < 0)
	{
		n = -n;
		c = '-';
		write(1, &c, 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = (n + '0');
		write(1, &c, 1);
	}
}

static void	f_gnl_join(t_gnl *g, t_str *s)
{
	size_t	size;
	char	*res;
	ssize_t	i;

	i = g->i;
	while (i < g->size && g->buff[i] != '\n')
		i++;
	size = i - g->i + s->len;
	res = malloc(sizeof(char) * (size + 1));
	i = -1;
	while (++i < (ssize_t)size)
	{
		if (i < (ssize_t)s->len)
			res[i] = s->str[i];
		else
			res[i] = g->buff[g->i++];
	}
	res[i] = '\0';
	free(s->str);
	s->str = res;
	s->len = size;
}

char		*f_gnl(int skip)
{
	static t_gnl	g;
	t_str			s;

	if (skip)
		free(f_gnl(skip - 1));
	s.str = 0;
	s.len = 0;
	if (g.i < g.size)
	{
		g.i++;
		f_gnl_join(&g, &s);
	}
	if (g.i >= g.size)
	{
		while ((g.size = read(0, g.buff, BUFF_SIZE)) > 0)
		{
			g.i = 0;
			f_gnl_join(&g, &s);
			if (g.i < g.size)
				break ;
		}
	}
	return (s.str);
}

int			main(void)
{
	g_f.own = 0;
	g_w.enemy_last = 0;
	g_w.enemy_kill = 0;
	while (g_f.dist != EXIT)
	{
		g_f.enemy_count = 0;
		f_get_map();
		f_get_piece();
		if (g_w.enemy_last == g_f.enemy_count)
			g_w.enemy_kill = 1;
		f_manhattan();
		f_work();
		g_w.enemy_last = g_f.enemy_count;
		free(g_f.piece);
		free(g_f.enemy_points);
		ft_putnbr(g_f.result.y);
		write(1, " ", 1);
		ft_putnbr(g_f.result.x);
		write(1, "\n", 1);
	}
	return (0);
}
