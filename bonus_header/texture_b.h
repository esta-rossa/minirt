/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_b.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 02:47:47 by arraji            #+#    #+#             */
/*   Updated: 2020/02/24 18:03:00 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEXTURE_B_H
# define FT_TEXTURE_B_H
# include "minirt_b.h"

void		apply_texture(t_all all);
void		load_texture(t_all all, t_texture *texture);
t_color		get_pixel_at(t_texture *texture, double x, double y);
#endif
