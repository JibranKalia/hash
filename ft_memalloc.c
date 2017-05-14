/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:19:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/13 16:51:31 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

void	*ft_memalloc(size_t size)
{
	void			*ret;

	CHK(size == 0, 0);
	CHK((ret = malloc(size)) == 0, 0);
	ft_bzero(ret, size);
	return (ret);
}
