/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:51:03 by ybereshc          #+#    #+#             */
/*   Updated: 2018/12/10 19:51:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	f_valid_cords(t_point m)
{
	t_point	p;
	int		i;
	int		colide;

	colide = 0;
	i = -1;
	while (++i < g_f.piece_count)
	{
		p = (t_point){g_f.piece[i].y + m.y, g_f.piece[i].x + m.x};
		if (p.y >= g_f.map_size.y || p.x >= g_f.map_size.x)
			return (2);
		if (g_f.map[p.y][p.x] == -1 && colide++)
			return (3);
		if (g_f.map[p.y][p.x] == 1)
			return (4);
	}
	if (!colide)
		return (1);
	return (0);
}

int			f_put_in_map(t_point m)
{
	t_point	p1;
	t_point	p2;
	t_point	i;
	int		dist;

	dist = EXIT;
	i.y = -1;
	while (++i.y < g_f.piece_count)
	{
		p1 = (t_point){g_f.piece[i.y].y + m.y, g_f.piece[i.y].x + m.x};
		i.x = -1;
		while (++i.x < g_f.enemy_count)
		{
			p2 = g_f.enemy_points[i.x];
			if (DIST(p1, p2) < dist)
				dist = DIST(p1, p2);
		}
	}
	return (dist);
}

void		f_work(void)
{
	t_point	m;
	int		dist;

	g_f.dist = EXIT;
	m.y = -1;
	g_f.result.y = 0;
	while (++m.y < g_f.map_size.y)
	{
		m.x = -1;
		while (++m.x < g_f.map_size.x)
		{
			if (!f_valid_cords(m))
			{
				if (g_w.enemy_kill || (dist = f_put_in_map(m)) < g_f.dist)
				{
					g_f.dist = dist;
					g_f.result.y = m.y - g_f.ps.y;
					g_f.result.x = m.x - g_f.ps.x;
					if (g_w.enemy_kill)
						return ;
				}
			}
		}
	}
}
