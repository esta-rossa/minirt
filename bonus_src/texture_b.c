/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:56:48 by arraji            #+#    #+#             */
/*   Updated: 2020/02/24 18:02:58 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_b.h"

/*
**[0]->bpp
**[1]->size_line
**[2]->endian
*/

void		apply_texture(t_all all)
{
	t_obj	*obj;

	obj = all.a_obj;
	while (obj)
	{
		if (obj->type == UV_SPHERE)
			load_texture(all, obj->texture);
		obj = obj->next;
	}
}

void		load_texture(t_all all, t_texture *texture)
{
	int		vars[3];
	int		*image;
	void	*image_p;
	t_pars	pars;

	if (!(image_p =
	mlx_png_file_to_image(all.wind->init,
	texture->file,
	&(texture->width), &(texture->hight))))
	{
		pars.line = texture->file;
		ft_pars_exit(pars, E_TEXTURE_F);
	}
	image = (int *)mlx_get_data_addr(image_p, &vars[0],
	&vars[1], &vars[2]);
	texture->image = (int *)malloc(4 * texture->hight * texture->width);
	ft_memcpy(texture->image, image, 4 * texture->hight * texture->width);
	mlx_destroy_image(all.wind->init, image_p);
}

t_color		get_pixel_at(t_texture *texture, double x, double y)
{
	t_color		color;

	y = 1 - y;
	x = x * (texture->width - 1);
	y = y * (texture->hight - 1);
	x = round(x);
	y = round(y);
	color = get_color(texture->image[((int)y * texture->width) + (int)x]);
	return (color);
}
