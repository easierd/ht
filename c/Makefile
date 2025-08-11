chain.o: chain.c
	gcc -c -Wall -Wextra -fsanitize=address chain.c

chain_utils.o: chain_utils.c
	gcc -c -Wall -Wextra -fsanitize=address chain_utils.c

main: main.c chain_utils.o chain.o
	gcc -o main -Wall -Wextra -fsanitize=address main.c chain_utils.o chain.o

clear:
	rm main *.o
