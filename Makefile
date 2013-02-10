heap: heap.c
	gcc -Wall -Werror -O3 -std=gnu99 heap.c -o heap

trivial: trivial.c
	gcc -Wall -Werror -O3 -std=gnu99 trivial.c -o trivial

clean:
	rm heap trivial
