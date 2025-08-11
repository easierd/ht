chain.o: chain.c
	gcc -c -Wall -Wextra -fsanitize=address chain.c

chain_utils.o: chain_utils.c
	gcc -c -Wall -Wextra -fsanitize=address chain_utils.c

hash_table.o: hash_table.c
	gcc -c -Wall -Wextra -fsanitize=address hash_table.c

hash_table_utils.o: hash_table_utils.c
	gcc -c -Wall -Wextra -fsanitize=address hash_table_utils.c

main: main.c chain_utils.o chain.o hash_table.o hash_table_utils.o
	gcc -o main -Wall -Wextra -fsanitize=address main.c chain_utils.o chain.o hash_table.o hash_table_utils.o

clear:
	rm main *.o
