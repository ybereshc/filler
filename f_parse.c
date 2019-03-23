/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:50:44 by ybereshc          #+#    #+#             */
/*   Updated: 2018/12/10 19:50:47 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	f_get_map_first(void)
{
	char	*line;
	int		i;

	line = f_gnl(0);
	g_f.own = (line[10] == '1' ? 'O' : 'X');
	g_f.enemy = (g_f.own == 'O' ? 'X' : 'O');
	free(line);
	line = f_gnl(0);
	g_f.map_size.y = (int)ft_atoi(&line[8]);
	g_f.map_size.x = (int)ft_atoi(&line[8 + ft_int_len(g_f.map_size.y)]);
	free(line);
	free(f_gnl(0));
	g_f.map = malloc(sizeof(int*) * g_f.map_size.y);
	i = -1;
	while (++i < g_f.map_size.y)
		g_f.map[i] = malloc(sizeof(int) * g_f.map_size.x);
}

void		f_get_map(void)
{
	char	*line;
	t_point	p;

	if (!g_f.own)
		f_get_map_first();
	else
		free(f_gnl(1));
	p.y = -1;
	while (++p.y < g_f.map_size.y)
	{
		line = f_gnl(0);
		p.x = -1;
		while (++p.x < g_f.map_size.x)
		{
			g_f.map[p.y][p.x] = 0;
			if ((line + 4)[p.x] == g_f.own)
				g_f.map[p.y][p.x] = -1;
			else if ((line + 4)[p.x] == g_f.enemy)
			{
				g_f.enemy_count++;
				g_f.map[p.y][p.x] = 1;
			}
		}
		free(line);
	}
}

static void	f_piece_pos(char *piece_line, int x)
{
	int	i;
	int	n;

	i = -1;
	n = -1;
	while (piece_line[++i])
		if (piece_line[i] == '*')
			g_f.piece[++n] = (t_point){i / x, i % x};
	free(piece_line);
	g_f.ps.y = INT_MAX;
	g_f.ps.x = INT_MAX;
	i = -1;
	while (++i < g_f.piece_count)
	{
		if (g_f.piece[i].y < g_f.ps.y)
			g_f.ps.y = g_f.piece[i].y;
		if (g_f.piece[i].x < g_f.ps.x)
			g_f.ps.x = g_f.piece[i].x;
	}
	i = -1;
	while (++i < g_f.piece_count)
	{
		g_f.piece[i].y -= g_f.ps.y;
		g_f.piece[i].x -= g_f.ps.x;
	}
}

void		f_get_piece(void)
{
	char	*line;
	char	*piece_line;
	t_point	p;
	t_point	i;

	piece_line = 0;
	g_f.piece_count = 0;
	line = f_gnl(0);
	i.y = (int)ft_atoi(&line[6]);
	i.x = (int)ft_atoi(&line[6 + ft_int_len(i.y)]);
	free(line);
	p.y = -1;
	while (++p.y < i.y)
	{
		line = f_gnl(0);
		p.x = -1;
		while (++p.x < i.x)
			if (line[p.x] == '*')
				g_f.piece_count++;
		piece_line = ft_strfjoin(piece_line, line, 3);
	}
	g_f.piece = malloc(sizeof(t_point) * g_f.piece_count);
	f_piece_pos(piece_line, i.x);
}
