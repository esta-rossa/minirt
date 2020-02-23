/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_b.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:38:39 by arraji            #+#    #+#             */
/*   Updated: 2020/02/23 16:39:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILTER_B_H
# define FT_FILTER_B_H
# define FILTER_X 9
# define FILTER_Y 9

extern const double g_filter[FILTER_X][FILTER_Y];
void		filter(int *img);
#endif
