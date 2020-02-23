/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_b.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 02:24:07 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:37:18 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SAVE_B_H
# define FT_SAVE_B_H
# include "minirt_b.h"
# define HEADER_SIZE 54

typedef	struct	s_bitmap_file
{
	unsigned char			bitmap_type[2];
	int						file_size;
	short					reserved1;
	short					reserved2;
	unsigned int			offset_bits;
}				t_bitmap_file;

typedef	struct	s_bitmap_image
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_bitmap_image;
void			save_bitmap(t_wind wind, int *pp);
#endif
