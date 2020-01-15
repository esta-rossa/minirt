/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 02:33:15 by arraji            #+#    #+#             */
/*   Updated: 2020/01/15 00:47:12 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# define E_STD		1
# define E_ARGS		2
# define E_ND_FILE	3
# define E_NO_FILE	4
# define E_FILE_FRM	5
# define E_PARS		6
# define E_NO_CAM	7
# define E_NO_RES	8

void	ft_pars_exit(t_pars pars, int number);
void	init_error(t_pars pars);
void	ft_exit(int number);
#endif
