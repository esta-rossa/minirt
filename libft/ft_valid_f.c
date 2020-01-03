/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:13:09 by arraji            #+#    #+#             */
/*   Updated: 2020/01/03 02:20:45 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		valid_f(char *str)
{
	int		index;

	index = 0;
	if (str[index] == '-')
		index++;
	if (ft_isdigit(str[index]) == 0)
		return (0);
	while (str[index] != '.' && str[index] != '\0')
	{
		if (ft_isdigit(str[index]) == 0)
			return (0);
		index++;
	}
	if (str[index] == '.')
	{
		index++;
		if (ft_isdigit(str[index]) == 0)
			return (0);
	}
	while (str[index])
	{
		if (ft_isdigit(str[index++]) == 0)
			return (0);
	}
	return (1);
}
