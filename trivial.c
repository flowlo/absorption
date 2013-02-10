#include <stdio.h>

int main(int argc, char **argv) {
	float x = 0;

	for (int i = 0; i < 10000000; i++)
		x += .0001;

	x += 10000;

	printf("%f\n", x);
}
