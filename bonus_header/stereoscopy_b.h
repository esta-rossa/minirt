/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereoscopy_b.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:58:07 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:41:04 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STEREOSCOPY_B_H
# define FT_STEREOSCOPY_B_H
# include "minirt_b.h"

void		stereoscopy_render(t_all *all);
void		stereoscopy_filter(t_color *color, int type);
#endif
