/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_hash_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:28:46 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/14 14:44:23 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <hotrace.h>

#include <string.h>
#define KEYSIZE  100
#define VALUESIZE 100
#define TESTSIZE 20000

const char		g_charset[89] = "%:!#&'()*+-./0123456789;<=>?@ABCDFGHIJKL\
MNOPQRSTUVWXYZ[]^_`abcdefghijklmnoprstuvwxyz{|}~";

typedef struct	s_test
{
	char		key[KEYSIZE];
	char		value[VALUESIZE];
}				t_test;

static void		rand_string(char *str, size_t size)
{
	size_t		n;
	int			key;

	n = 0;
	--size;
	while (n < size)
	{
		key = rand() % (int)(sizeof(g_charset) - 1);
		str[n] = g_charset[key];
		++n;
	}
	str[size] = '\0';
}

int		main(void)
{
	int				i;
	char			*out;
	t_hashtable		*hh;
	t_test			test[TESTSIZE];
	
	i = 0;
	while (i < TESTSIZE)
	{
		rand_string(test[i].key, KEYSIZE);
		rand_string(test[i].value, VALUESIZE);
		++i;
	}

	hh = ht_create(10000);
	CHK1(hh == NULL, printf("MALLOC FAILED\n"), -1);

	i = 0;
	while (i < TESTSIZE)
	{
		ht_set(hh, test[i].key, test[i].value);
		++i;
	}

	i = 0;
	while (i < TESTSIZE)
	{
		out = ht_get(hh, test[i].key);
		if (strcmp(out, test[i].value) != 0)
			printf("Wrong String\n");
		++i;
	}
	printf("%d Test Passed\n", i);
	ht_delete(hh);
	return (0);
}
