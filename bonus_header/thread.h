/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:43:19 by arraji            #+#    #+#             */
/*   Updated: 2020/02/07 07:06:32 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREAD_H
# define FT_THREAD_H
# include "minirt_b.h"
void		hold_threads(pthread_t *threads, int size);
void		threads_parent(void);
#endif
