/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:51:12 by ybereshc          #+#    #+#             */
/*   Updated: 2018/12/10 19:51:13 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "lib/libft.h"

# define EXIT INT_MAX
# define ABS(n) ((n < 0 ? -(n) : n))
# define DIST(a,b) (ABS(a.y - b.y) + ABS(a.x - b.x))
# define BUFF_SIZE 4096

typedef struct	s_gnl
{
	ssize_t	i;
	ssize_t	size;
	char	buff[BUFF_SIZE];
}				t_gnl;

typedef struct	s_str
{
	char	*str;
	size_t	len;
}				t_str;

typedef	struct	s_point
{
	int	y;
	int	x;
}				t_point;

typedef struct	s_filler
{
	char	own;
	char	enemy;
	int		enemy_count;
	t_point	*enemy_points;
	int		**map;
	t_point	map_size;
	t_point	*piece;
	int		piece_count;
	t_point	ps;
	int		dist;
	t_point	result;
}				t_filler;

typedef struct	s_work
{
	int	enemy_last;
	int	enemy_kill;
}				t_work;

t_filler	g_f;
t_work		g_w;

char			*f_gnl(int skip);
void			f_get_map(void);
void			f_get_piece(void);
void			f_manhattan(void);
void			f_work(void);

void			print_map(void);
#endif
