/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:50:05 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/14 15:52:19 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	end;

	i = 0;
	end = start + len;
	if (!s || (!(str = (char *)malloc(len + 1)) && end != 0))
		return (NULL);
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
