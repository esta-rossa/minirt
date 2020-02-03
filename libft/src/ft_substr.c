/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:38:50 by arraji            #+#    #+#             */
/*   Updated: 2019/11/06 01:03:52 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	int	ft_slen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		index;

	tab = 0;
	index = 0;
	tab = (char *)malloc(len + 1);
	if (!tab || !s)
		return (NULL);
	while (s[start] != '\0' && len-- > 0 && start < ft_slen(s))
		tab[index++] = s[start++];
	tab[index] = 0;
	return (tab);
}
