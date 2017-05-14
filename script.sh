rm hash
gcc -Wall -Werror -Wextra -I includes/ db_hash.c db_hash_delete.c db_hash_test.c db_murmurhash.c ft_bzero.c ft_memalloc.c ft_strcmp.c ft_strdup.c ft_strlen.c ft_strnew.c -o hash
./hash
