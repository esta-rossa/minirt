/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 06:50:31 by arraji            #+#    #+#             */
/*   Updated: 2020/02/04 05:22:43 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	init_image_header(t_bitmap_image *bih, t_wind wind,
int file_size)
{
	int ppm;

	ppm = 96 * 39.375;
	bih->size_header = sizeof(t_bitmap_image);
	bih->width = wind.wind_x;
	bih->height = -wind.wind_y;
	bih->planes = 1;
	bih->bit_count = 32;
	bih->compression = 0;
	bih->image_size = file_size;
	bih->ppm_x = ppm;
	bih->ppm_y = ppm;
	bih->clr_used = 0;
	bih->clr_important = 0;
}

static	void	init_file_header(t_bitmap_file *bfh, int file_size)
{
	ft_memcpy(&bfh->bitmap_type, "BM", 2);
	bfh->file_size = file_size;
	bfh->reserved1 = 0;
	bfh->reserved2 = 0;
	bfh->offset_bits = 0;
}

void			save_bitmap(t_wind wind, int *pp)
{
	int				fd;
	t_bitmap_file	bfh;
	t_bitmap_image	bih;
	int				image_size;
	int				file_size;

	image_size = wind.wind_x * wind.wind_y;
	pp -= image_size;
	file_size = HEADER_SIZE + (4 * image_size);
	init_file_header(&bfh, file_size);
	init_image_header(&bih, wind, file_size);
	if ((fd = open("save.bmp",
	O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
		ft_exit(E_NO_SAVE);
	write(fd, &bfh, sizeof(bfh) - 2);
	write(fd, &bih, sizeof(bih));
	write(fd, pp, image_size * 4);
	close(fd);
}
