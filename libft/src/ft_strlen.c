/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:01:30 by arraji            #+#    #+#             */
/*   Updated: 2019/12/04 17:02:13 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(char const *str, int type)
{
	size_t len;

	len = 0;
	if (str == NULL)
		return (0);
	if (type == 1)
		while (str[len])
			len -= -1;
	if (type == 0)
		while (str[len] != '\n' && str[len] != '\0')
			len -= -1;
	return (len);
}
