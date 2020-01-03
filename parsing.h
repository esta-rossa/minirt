/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 22:25:13 by arraji            #+#    #+#             */
/*   Updated: 2020/01/03 11:56:11 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include "minirt.h"
# define PLANE		1
# define SPHERE		2
# define CYLINDER	3
# define SQUARE		4
# define TRIANGLE	5



void	data_read(t_pars *pars, t_all *all);
void	line_pars(t_pars *pars, t_obj *obj, char **args);
#endif
