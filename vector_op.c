/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 03:35:45 by arraji            #+#    #+#             */
/*   Updated: 2019/12/16 03:44:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vector_size(t_cord vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

t_cord	vector_add(t_cord vec_1, t_cord vec_2)
{
	t_cord	v_new;

	v_new.x = vec_1.x + vec_2.x;
	v_new.y = vec_1.y + vec_2.y;
	v_new.z = vec_1.z + vec_2.z;
	return (v_new);
}

t_cord	vector_sub(t_cord vec_1, t_cord vec_2)
{
	t_cord	v_new;

	v_new.x = vec_1.x - vec_2.x;
	v_new.y = vec_1.y - vec_2.y;
	v_new.z = vec_1.z - vec_2.z;
	return (v_new);
}

t_cord	vector_mltp(t_cord vec, double num)
{
	t_cord	v_new;

	v_new.x = num * vec.x;
	v_new.y = num * vec.y;
	v_new.z = num * vec.z;
	return (v_new);
}

t_cord	vector_div(t_cord vec, double num)
{
	t_cord	v_new;

	v_new.x = num / vec.x;
	v_new.y = num / vec.y;
	v_new.z = num / vec.z;
}

t_cord	 vector_norm(t_cord vec)
{
	double	len;
	t_cord	v_new;

	len = vector_size(vec);
	v_new = vector_div(vec, len);
	return (v_new);
}

