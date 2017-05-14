/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:45:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/13 16:52:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

char	*ft_strdup(const char *src)
{
	int			len;
	int			i;
	char		*dst;

	i = 0;
	len = ft_strlen(src);
	CHK((dst = ft_strnew(len + 1)) == 0, 0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
