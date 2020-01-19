/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:50:24 by arraji            #+#    #+#             */
/*   Updated: 2020/01/19 06:58:32 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_wind(t_all all)
{

	if (!(all.wind->init = mlx_init()))
		ft_exit(E_STD);
	all.wind->wind_p = mlx_new_window(all.wind->init, all.wind->wind_x,
	all.wind->wind_y, "oups");
}

void		init_image(t_all all)
{
	int		bpp;
	int		size_line;
	int		endian;
	if (!(all.wind->img_p = mlx_new_image(all.wind->init, all.wind->wind_x,
	all.wind->wind_y)))
		ft_exit(E_STD);
	all.wind->img_data = (int *)mlx_get_data_addr(all.wind->img_p, &bpp,
	&size_line, &endian);

}

void		render(t_all all, t_camera camera, t_color *color)
{
	int			pos;
	double		t;
	t_obj		*obj;

	*color = (t_color){ 0, 0, 0};
	t = FAR;
	if ((pos = inters(all.a_obj, camera, &t)) >= 0)
	{
		obj = all.a_obj;
		while (pos--)
			obj = obj->next;
		ft_phong(all, obj, color, t);
		// *color = obj->color;
	}
}

void		here_we_go(t_all *all)
{
	int			y;
	int			x;
	t_color		color;

	y = -1;
	init_image(*all);
	all->wind->img_data_save = all->wind->img_data;
	init_camera(all->a_camera, *all);
	while (++y < all->wind->wind_y)
	{
		x = -1;
		while (++x < all->wind->wind_x)
		{
			all->a_camera->v_ray = vector_norm(get_ray(*(all)->a_camera,
			all->a_camera->bot, x, y));
			render(*all, *(all)->a_camera, &color);
			*(all->wind)->img_data = get_color(color);
			(all->wind)->img_data++;
		}
	}
/* 	mlx_put_image_to_window(all->wind->init, all->wind->wind_p,
	all->wind->img_p, 0, 0); */
	save_bitmap(*all->wind, all->wind->img_data_save);
}

void	init_image_header(t_bitmap_image *bih, t_wind wind, int file_size)
{
	int ppm;

	ppm = 96 * 39.375;
	bih->size_header     = sizeof(t_bitmap_image);
	bih->width           = wind.wind_x;
	bih->height          = -wind.wind_y;
	bih->planes          = 1;
	bih->bit_count       = 32;
	bih->compression     = 0;
	bih->image_size      = file_size;
	bih->ppm_x           = ppm;
	bih->ppm_y           = ppm;
	bih->clr_used        = 0;
	bih->clr_important   = 0;

}

void	init_file_header(t_bitmap_file *bfh, int file_size)
{
	ft_memcpy(&bfh->bitmap_type, "BM", 2);
	bfh->file_size       = file_size;
	bfh->reserved1       = 0;
	bfh->reserved2       = 0;
	bfh->offset_bits     = 0;
}

void	save_bitmap(t_wind wind, int *pp)
{
	int				fd;
	t_bitmap_file	bfh;
	t_bitmap_image	bih;
	int image_size;
	char *file_name = "";
	int file_size;

	image_size = wind.wind_x * wind.wind_y;
	file_size = 54 + 4 * image_size;
	init_file_header(&bfh, file_size);
	init_image_header(&bih, wind, file_size);
	if ((fd = open("save.bmp", O_RDWR, O_CREAT)) == -1)
		exit (1);
	write(fd, &bfh, sizeof(bfh));
	write(fd, &bih, sizeof(bih));
	unsigned char *color = (unsigned char *)pp;
	write(fd, &color, image_size * 4);
	close(fd);
}
