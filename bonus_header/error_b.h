/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 02:33:15 by arraji            #+#    #+#             */
/*   Updated: 2020/02/24 04:49:21 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_B_H
# define FT_ERROR_B_H
# include "minirt_b.h"
# define E_STD			1
# define E_ARGS			2
# define E_ND_FILE		3
# define E_NO_FILE		4
# define E_FILE_FRM		5
# define E_PARS			6
# define E_NO_CAM		7
# define E_NO_RES		8
# define E_NO_SAVE		9
# define E_NO_AMB		10
# define E_TEXTURE		11
# define E_TEXTURE_F	12

void	ft_pars_exit(t_pars pars, int number);
void	init_error(t_pars pars);
void	ft_exit(int number);
#endif
