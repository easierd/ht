chain.o: ht/chain.c
	gcc -c -Wall -Wextra -fsanitize=address ht/chain.c

chain_utils.o: utils/chain_utils.c
	gcc -c -Wall -Wextra -fsanitize=address utils/chain_utils.c

hash_table.o: ht/hash_table.c
	gcc -c -Wall -Wextra -fsanitize=address ht/hash_table.c

hash_table_utils.o: utils/hash_table_utils.c
	gcc -c -Wall -Wextra -fsanitize=address utils/hash_table_utils.c

main: main.c chain_utils.o chain.o hash_table.o hash_table_utils.o
	gcc -o main -Wall -Wextra -fsanitize=address main.c chain_utils.o chain.o hash_table.o hash_table_utils.o

clear:
	rm main *.o
