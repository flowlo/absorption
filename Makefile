absorption: absorption.c
	gcc -Wall -Werror -O3 -std=gnu99 absorption.c -o absorption

clean:
	rm absorption
