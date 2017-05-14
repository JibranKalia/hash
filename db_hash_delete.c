/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_hash_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:18:35 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/14 14:19:22 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

void		ht_lstdel(t_entry **entry)
{
	t_entry		*tmp;

	if (entry == NULL || *entry == NULL)
		return;
	while (*entry)
	{
		free((*entry)->key);
		free((*entry)->value);
		tmp = (*entry)->next;
		free(*entry);
		*entry = NULL;
		*entry = tmp;
	}
}

void		ht_delete(t_hashtable *hashtable)
{
	int			i;
	t_entry		*next;

	i = 0;
	while (i < hashtable->size)
	{
		next = hashtable->table[i];
		ht_lstdel(&next);
		++i;
	}
	free(hashtable->table);
	free(hashtable);
}
