/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 02:24:07 by arraji            #+#    #+#             */
/*   Updated: 2020/01/19 05:50:54 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SAVE_H
# define FT_SAVE_H
# include "minirt.h"
typedef	struct	s_bitmap_file
{
		unsigned char			bitmap_type[2];     // 2 bytes
		int						file_size;          // 4 bytes
		short					reserved1;          // 2 bytes
		short					reserved2;          // 2 bytes
		unsigned int			offset_bits;        // 4 bytes
}				t_bitmap_file;

typedef	struct	s_bitmap_image
{
		unsigned int	size_header;        // 4 bytes
		unsigned int	width;              // 4 bytes
		unsigned int	height;             // 4 bytes
		short int		planes;             // 2 bytes
		short int		bit_count;          // 2 bytes
		unsigned int	compression;        // 4 bytes
		unsigned int	image_size;         // 4 bytes
		unsigned int	ppm_x;              // 4 bytes
		unsigned int	ppm_y;              // 4 bytes
		unsigned int	clr_used;           // 4 bytes
		unsigned int	clr_important;      // 4 bytes
}				t_bitmap_image;
void		save_bitmap(t_wind wind,  int *pp);
#endif
