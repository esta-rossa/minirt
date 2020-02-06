/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_pars_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:38:11 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 11:53:49 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

static	void	init_vecs(t_cord *up, t_cord *right, t_obj *o)
{
	*right = vector_norm(cross_prod(new_cord(0, 1, NEAR), o->norm));
	*up = vector_norm(cross_prod(o->norm, *right));
	*right = vector_mltp(*right, o->diam / 2);
	*up = vector_mltp(*up, o->diam / 2);
}

static	void	add_triangles(t_obj *sq, t_cord up, t_cord right)
{
	t_obj	*obj;

	add_obj(&sq, new_obj());
	obj = sq->next;
	obj->type = TRIANGLE;
	obj->vertex_0 = vector_add(sq->pos, vector_add(right, up));
	obj->vertex_1 = vector_add(sq->pos, vector_add(up, vector_mltp(right, -1)));
	obj->vertex_2 = vector_add(sq->pos, vector_mltp(sq->norm, sq->height));
	obj->color = sq->color;
	add_obj(&sq, new_obj());
	*obj->next = *obj;
	obj = obj->next;
	obj->next = NULL;
	obj->vertex_0 = vector_add(sq->pos,
	vector_add(vector_mltp(right, -1), vector_mltp(up, -1)));
	add_obj(&obj, new_obj());
	*obj->next = *obj;
	obj = obj->next;
	obj->next = NULL;
	obj->vertex_1 = vector_add(sq->pos, vector_add(vector_mltp(up, -1), right));
	add_obj(&obj, new_obj());
	*obj->next = *obj;
	obj = obj->next;
	obj->next = NULL;
	obj->vertex_0 = vector_add(sq->pos, vector_add(right, up));
}

static	void	create_obj(t_obj pyramid, t_all *list)
{
	t_obj	*obj;
	t_cord	up;
	t_cord	right;

	add_obj(&(list->a_obj), new_obj());
	obj = list->a_obj;
	while (obj->next)
		obj = obj->next;
	*obj = pyramid;
	obj->type = SQUARE;
	list->last->save = obj;
	list->last->type = PYRAMID;
	init_vecs(&up, &right, obj);
	add_triangles(obj, up, right);
}

void	pyramid_pars(t_pars *pars, t_all *list, char **args)
{
	t_obj	pyramid;

	if (ft_tablen(args) != 6 || !valid_f(args[3]) || !valid_f(args[4]))
		ft_pars_exit(*pars, E_PARS);
	check_tab(args, *pars, 1, 2);
	check_tab(args, *pars, 2, 2);
	check_tab(args, *pars, 5, 1);
	pars->tab = ft_split(args[1], ',');
	pars_pos(pars, &pyramid.pos);
	pars->tab = ft_split(args[2], ',');
	pars_pos(pars, &pyramid.norm);
	pyramid.diam = ft_atof(args[3]);
	pyramid.height = ft_atof(args[4]);
	pars->tab = ft_split(args[5], ',');
	pars_color(pars, &pyramid.color);
	pyramid.next = NULL;
	create_obj(pyramid, list);
}
