/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:16:25 by ybereshc          #+#    #+#             */
/*   Updated: 2018/12/19 12:16:26 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "../lib/libft.h"

#define BUFF_SIZE 4096
#define TAG_OPEN "<script>var map = \""
#define TAG_CLOSE "\";</script>"
#define SRC_FILE "./bonus/index.html"
#define TMP_FILE "./bonus/.index.html"

static ssize_t	b_write_np(int fd, const void *buff, unsigned long size)
{
	char	*str;
	char	*tmp;

	str = (char*)buff;
	tmp = str;
	while (size--)
	{
		if (*tmp == '\n')
		{
			write(fd, str, tmp - str);
			write(fd, "\\n", 2);
			str = tmp + 1;
		}
		tmp++;
	}
	write(fd, str, tmp - str);
	return (0);
}

int				b_read_write(void)
{
	int		i[3];
	char	buff[BUFF_SIZE + 1];
	ssize_t	(*wfunc)();

	wfunc = &write;
	i[0] = open(SRC_FILE, O_RDONLY);
	remove(TMP_FILE);
	i[1] = open(TMP_FILE, O_CREAT | O_WRONLY, S_IWRITE | S_IREAD);
	if (i[0] == -1 || i[1] == -1)
		return (1);
	while ((i[2] = read(i[0], buff, BUFF_SIZE)) || i[0])
	{
		if (!i[2])
		{
			write(i[1], TAG_OPEN, ft_strlen(TAG_OPEN));
			close(i[0]);
			i[0] = 0;
			wfunc = &b_write_np;
		}
		wfunc(i[1], buff, i[2]);
	}
	write(i[1], TAG_CLOSE, ft_strlen(TAG_CLOSE));
	return (0);
}

int				main(int ac, char **av)
{
	char	*cmd;

	cmd = ft_strfjoin("open ", TMP_FILE, 0);
	cmd = ft_strfjoin(cmd, " -a ", 1);
	if (b_read_write())
	{
		write(2, "bonus error\n", 12);
		return (0);
	}
	if (ac != 2)
		cmd = ft_strfjoin(cmd, "Safari", 1);
	else
		cmd = ft_strfjoin(cmd, av[1], 1);
	system(cmd);
	free(cmd);
	return (0);
}
