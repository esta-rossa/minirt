/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_b.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 22:25:13 by arraji            #+#    #+#             */
/*   Updated: 2020/02/12 04:44:57 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# define PLANE			1
# define SPHERE			2
# define CYLINDER		3
# define SQUARE			4
# define TRIANGLE		5
# define DISK			6
# define LIGHT			7
# define CAM			8
# define OBJ			9
# define AMB			10
# define CUBE			11
# define PYRAMID		12
# define CAP			13
# define NUM_OF_ARGS	16
void		data_read(t_pars *pars, t_all *all);
void		line_pars(t_pars *pars, t_all *list, char **args);
void		add_obj(t_obj **alst, t_obj *new);
void		add_light(t_light **alst, t_light *new);
void		add_cam(t_camera **alst, t_camera *new);
void		check_tab(char **args, t_pars pars, int index, int type);
void		sp_pars(t_pars *pars, t_all *list, char **args);
void		plane_pars(t_pars *pars, t_all *list, char **args);
void		cyl_pars(t_pars *pars, t_all *list, char **args);
t_light		*new_light(void);
t_camera	*new_cam(void);
t_obj		*new_obj(void);
void		free_tab(char **tab, int i);
void		cam_pars(t_pars *pars, t_all *list, char **args);
void		ambiant_pars(t_pars *pars, t_all *list, char **args);
void		resul_pars(t_pars *pars, t_all *list, char **args);
void		light_pars(t_pars *pars, t_all *list, char **args);
void		pars_pos(t_pars *pars, t_cord *pos);
void		pars_color(t_pars *pars, t_color *color);
void		tr_pars(t_pars *pars, t_all *list, char **args);
void		square_pars(t_pars *pars, t_all *list, char **args);
void		rot_pars(t_pars *pars, t_all *list, char **args);
void		tran_pars(t_pars *pars, t_all *list, char **args);
void		rot(t_pars pars, t_cord *vec);
void		cube_pars(t_pars *pars, t_all *list, char **args);
void		pyramid_pars(t_pars *pars, t_all *list, char **args);
void		disk_pars(t_pars *pars, t_all *list, char **args);
#endif
