/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:34:07 by arraji            #+#    #+#             */
/*   Updated: 2020/01/02 17:53:28 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define NONE	0
# define POINT	2
# define AST	4
# define ZE_FL	8
# define LE_ALI	16
# define WIDTH	32
# define PRE	64
# define CRI	128
# define C_T	1
# define S_T	2
# define P_T	3
# define D_T	4
# define U_T	5
# define X_T	6
# define XX_T	7
# define PERC	8

typedef	struct	s_printed
{
	unsigned char		type;
	unsigned char		flag;
	char				*printed;
	char				fill_char;
	char				printed_c;
	int					size_rt;
	int					width;
	int					precision;
	int					pr_size;
	unsigned int		index;
}				t_data;
int				ft_printf(const char *arg1, ...);
int				shit_printing(const char *arg1, va_list ar, t_data *data);
unsigned char	check_type(char c);
void			end(char **s1, char **s2);
void			c_type(va_list ar, t_data *data);
int				s_type(va_list ar, t_data *data);
int				p_type(va_list ar, t_data *data);
int				d_type(va_list ar, t_data *data);
int				d_type_utils(t_data *data, int neg);
int				u_type(va_list ar, t_data *data);
int				u_type_utils(t_data *data, int len);
int				x_type(va_list ar, t_data *data);
int				x_type_utils(t_data *data, int len);
t_data			*declare(void);
int				strc_end(t_data **ptr, int rt);
int				is_flag(char c);
void			print_char(va_list ar, t_data *data);
int				print_string(va_list ar, t_data *data);
void			print_string_utils(t_data *data, int type);
int				print_corder(va_list ar, t_data *data);
void			print_corder_utils(t_data *data, int type);
int				print_decimal(va_list ar, t_data *data);
int				print_unsigned(va_list ar, t_data *data);
int				print_hexa(va_list ar, t_data *data);
void			print_perc(t_data *data);
void			precision_set(const char *arg1, va_list ar, t_data *data);
void			asterisk_set(va_list ar, t_data *data);
void			set_width(const char *arg1, t_data *data);
void			check_flag(const char *arg1, va_list ar, t_data *data);
char			*ft_to_hex(unsigned long hl, int type);
void			ft_reset(t_data *data);

#endif
