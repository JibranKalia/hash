/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 13:57:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/14 15:23:03 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

/*
** Create a new hashtable
** Allocate table (line 16)
** Allocate pointers to head node (line 21)
*/

t_hashtable	*ht_create(int size)
{
	t_hashtable	*hashtable;
	int			i;

	i = 0;
	hashtable = NULL;
	CHK(size < 1, NULL);
	hashtable = ft_memalloc(sizeof(t_hashtable));
	CHK(hashtable == NULL, NULL);
	hashtable->table = ft_memalloc(sizeof(t_entry*) * size);
	CHK(hashtable->table == NULL, NULL);
	i = -1;
	while (++i < size)
		hashtable->table[i] = NULL;
	hashtable->size = size;
	return (hashtable);
}

/*
** Hash a string for specific hash table
*/

int			ht_hash(t_hashtable *hashtable, char *key)
{
	uint32_t	hashval;

	hashval = db_hash_algo(key);
	return (hashval % hashtable->size);
}

/*
** Create a key-value pair
*/

t_entry		*ht_newpair(char *key, char *value)
{
	t_entry *newpair;

	if ((newpair = malloc(sizeof(t_entry))) == NULL)
		return (NULL);
	if ((newpair->key = ft_strdup(key)) == NULL)
		return (NULL);
	if ((newpair->value = ft_strdup(value)) == NULL)
		return (NULL);
	newpair->next = NULL;
	return (newpair);
}

/*
** Insert a key-value pair.
** There is already a pair. Replace that string (line 86)
** If not create a pair. (line 92)
** Start of Linked list (line 96)
** End of Linked list (line 102)
** Middle of linked list (line 104)
*/

void		ht_set(t_hashtable *hashtable, char *key, char *value)
{
	int			bin;
	t_entry		*newpair;
	t_entry		*next;
	t_entry		*last;

	bin = ht_hash(hashtable, key);
	next = hashtable->table[bin];
	while (next != NULL && next->key != NULL && ft_strcmp(key, next->key) > 0)
	{
		last = next;
		next = next->next;
	}
	newpair = ht_newpair(key, value);
	if (next == hashtable->table[bin])
	{
		newpair->next = next;
		hashtable->table[bin] = newpair;
	}
	else if (next == NULL)
		last->next = newpair;
	else
	{
		newpair->next = next;
		last->next = newpair;
	}
}

/*
** Retrieve a key-value pair from hash table
** Step through the bin looking for value (line 125)
** Did we find anything? (line 129)
*/

char		*ht_get(t_hashtable *hashtable, char *key)
{
	int		bin;
	t_entry	*pair;

	bin = ht_hash(hashtable, key);
	pair = hashtable->table[bin];
	while (pair != NULL && pair->key != NULL && ft_strcmp(key, pair->key) > 0)
	{
		pair = pair->next;
	}
	if (pair == NULL || pair->key == NULL || ft_strcmp(key, pair->key) != 0)
		return (NULL);
	else
		return (pair->value);
}
