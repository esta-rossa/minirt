/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:23:09 by arraji            #+#    #+#             */
/*   Updated: 2019/10/23 00:38:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int value)
{
	int index;
	int len;

	index = 0;
	len = 0;
	while (str[len])
		len++;
	while (index < len + 1)
	{
		if (str[index] == (unsigned char)value)
			return ((char*)&str[index]);
		index++;
	}
	return (0);
}
