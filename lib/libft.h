/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:16:24 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 19:16:26 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <unistd.h>

# include "ft_list.h"

# define BIG_PIECE __int128_t

size_t		ft_strlen(char *str);

char		*ft_strsub(char *str, size_t pass, size_t n);
char		*ft_strdup(char *str);
char		*ft_strndup(char *str, size_t n);

char		*ft_strcat(char *str1, char *str2);
char		*ft_strncat(char *str1, char *str2, size_t n);
char		*ft_strfcat(char *str1, char *str2);
char		*ft_strjoin(char *str1, char *str2);
char		*ft_strfjoin(char *str1, char *str2, uint8_t f);

char		*ft_strchr(char *str, char chr);
char		*ft_strrchr(char *str, char chr);
intptr_t	ft_strchri(char *str, char chr);
intptr_t	ft_strrchri(char *str, char chr);

char		*ft_strupper(char *str);
char		*ft_strlower(char *str);

intmax_t	ft_atoi(char *str);
intmax_t	ft_str_to_int(char *str);
uintmax_t	ft_str_to_uint(char *str, uint8_t base);

char		*ft_dint_to_str(intmax_t num);
char		*ft_uint_to_str(uintmax_t num, uint8_t base);

size_t		ft_int_len(intmax_t num);
size_t		ft_uint_len(uintmax_t num, uint8_t base);

void		ft_print_memory(void *ptr, size_t size);
char		*ft_unichr(int chr);

/*
** Memory
*/
void		*ft_bzero(void *ptr, size_t n);
void		*ft_memset(void *ptr, uint8_t byte, size_t n);
void		*ft_memcpy(void *dst, void *src, size_t n);

/*
** Malloc
*/
void		*ft_bzmalloc(size_t n);

/*
** Math
*/
intmax_t	ft_pow(intmax_t nb, uintmax_t pow);
uintmax_t	ft_upow(uintmax_t nb, uintmax_t pow);
uintmax_t	ft_abs(intmax_t n);
uint8_t		ft_odd(intmax_t n);
uint8_t		ft_even(intmax_t n);
uint8_t		ft_negative(intmax_t n);
uint8_t		ft_positive(intmax_t n);

/*
** List
*/
t_list		*list_new(void);
t_list_el	*list_push(t_list *list, void *data, size_t size);
t_list_el	*list_remove(t_list *list, void *ptr);
t_list_el	*list_get(t_list *list, intmax_t n);

#endif
