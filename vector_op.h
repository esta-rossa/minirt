/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:48:17 by arraji            #+#    #+#             */
/*   Updated: 2019/12/16 04:51:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_OP_H
# define FT_VECTOR_OP_H
# include "minirt.h"
double	vector_size(t_cord vector);
t_cord	vector_add(t_cord vec_1, t_cord vec_2);
t_cord	vector_sub(t_cord vec_1, t_cord vec_2);
t_cord	vector_mltp(t_cord vec, double num);
t_cord	vector_div(t_cord vec, double num);
t_cord	 vector_norm(t_cord vec);

#endif
