/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_manhattan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:51:03 by ybereshc          #+#    #+#             */
/*   Updated: 2018/12/10 19:51:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_point	f_go_top(void)
{
	t_point	m;
	int		i;

	i = 0;
	m.y = -1;
	while (!i && ++m.y < g_f.map_size.y)
	{
		m.x = -1;
		while (!i && ++m.x < g_f.map_size.x)
			if (g_f.map[m.y][m.x] == 1)
			{
				g_f.enemy_points[0] = m;
				i = 1;
			}
	}
	m.y = -1;
	while (i && ++m.y < g_f.map_size.y)
	{
		m.x = -1;
		while (i && ++m.x < g_f.map_size.x)
			if (g_f.map[m.y][m.x] == -1)
				i = 0;
	}
	return (m);
}

void			f_manhattan(void)
{
	t_point	m;
	int		i;

	g_f.enemy_points = malloc(sizeof(t_point) * g_f.enemy_count);
	if (g_w.enemy_kill)
		return ;
	m = f_go_top();
	if (g_f.enemy_points[0].y && g_f.enemy_points[0].y + 2 < m.y)
	{
		g_f.enemy_count = 1;
		g_f.enemy_points[0] = (t_point){0, m.x + 1};
		g_f.map[g_f.enemy_points[0].y][g_f.enemy_points[0].x] = 2;
		return ;
	}
	i = 0;
	m.y = -1;
	while (++m.y < g_f.map_size.y)
	{
		m.x = -1;
		while (++m.x < g_f.map_size.x)
			if (g_f.map[m.y][m.x] == 1)
				g_f.enemy_points[i++] = m;
	}
}
