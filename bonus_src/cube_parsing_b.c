/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_parsing_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 06:04:06 by arraji            #+#    #+#             */
/*   Updated: 2020/02/10 10:04:44 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	up_down_squares(t_all *list, t_obj *cube)
{
	t_obj	*obj;

	add_obj(&(list->a_obj), new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	list->last->save = obj;
	list->last->type = CUBE;
	obj->sp_type = CUBE;
	obj->head = obj;
	cube->head = obj;
	obj->type = SQUARE;
	obj->pos = vector_add(cube->pos,
	vector_mltp((t_cord){0, 1, 0}, cube->diam / 2));
	obj->norm = (t_cord){0, 1, 0};
	obj->diam = cube->diam;
	obj->color = cube->color;
	add_obj(&(list->a_obj), new_obj());
	obj = obj->next;
	obj->type = SQUARE;
	obj->pos = vector_add(cube->pos,
	vector_mltp((t_cord){0, -1, 0}, cube->diam / 2));
	obj->norm = (t_cord){0, -1, 0};
	obj->diam = cube->diam;
	obj->color = cube->color;
}

static	void	right_left_squares(t_all *list, t_obj *cube)
{
	t_obj	*obj;

	add_obj(&(list->a_obj), new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = SQUARE;
	obj->pos = vector_add(cube->pos,
	vector_mltp((t_cord){1, 0, 0}, cube->diam / 2));
	obj->norm = (t_cord){1, 0, 0};
	obj->diam = cube->diam;
	obj->color = cube->color;
	add_obj(&(list->a_obj), new_obj());
	obj = obj->next;
	obj->type = SQUARE;
	obj->pos = vector_add(cube->pos,
	vector_mltp((t_cord){-1, 0, 0}, cube->diam / 2));
	obj->norm = (t_cord){-1, 0, 0};
	obj->diam = cube->diam;
	obj->color = cube->color;
	obj->head = cube->head;
	obj->sp_type = CUBE;
}

static	void	front_back_squares(t_all *list, t_obj *cube)
{
	t_obj	*obj;

	add_obj(&(list->a_obj), new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	obj->type = SQUARE;
	obj->pos = vector_add(cube->pos,
	vector_mltp((t_cord){0, 0, 1}, cube->diam / 2));
	obj->norm = (t_cord){0, 0, 1};
	obj->diam = cube->diam;
	obj->color = cube->color;
	add_obj(&(list->a_obj), new_obj());
	obj = obj->next;
	obj->type = SQUARE;
	obj->pos = vector_add(cube->pos,
	vector_mltp((t_cord){0, 0, -1}, cube->diam / 2));
	obj->norm = (t_cord){0, 0, -1};
	obj->diam = cube->diam;
	obj->color = cube->color;
	obj->head = cube->head;
	obj->sp_type = CUBE;
}

void			cube_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	cube;

	if (ft_tablen(args) != 4 || !valid_f(args[2]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 3, 1);
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &cube.pos);
	cube.diam = ft_atof(args[2]);
	pars->tab = ft_split(args[3], ',');
	pars_color(pars, &cube.color);
	up_down_squares(list, &cube);
	right_left_squares(list, &cube);
	front_back_squares(list, &cube);
}
