/*
 * Solution to the Absorption-Assignment by Martin Gruber <lgrum@htl-ottakring.at>
 * Copyright (C) 2013  Lorenz Leutgeb <lorenz.leutgeb@gmail.com>
 *                     Moritz Wanzenböck <moritz9422@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
// gcc -g -Wall -Wextra -O3 -std=gnu99 ./absorption.c -o ./absorption

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define cmp(a, b) (a < b)
#define isl(node) (node == cnt)
#define par(node) (node / 2)
#define lch(node) (2 * node)
#define rch(node) (2 * node + 1)

#define ins(n)	\
{ \
	cnt++; \
	bubble = cnt; \
	parent = par(bubble); \
 \
	while (bubble > 0 && cmp(n, arr[parent])) { \
		arr[bubble] = arr[parent];	\
		bubble = parent; \
		parent = par(bubble); \
	} \
	arr[bubble] = n; \
}

#define del() \
{ \
	bubble = 1;	\
	child = lch(bubble);	\
 \
	if (child <= cnt) { \
		do { \
			child += (!isl(child) && \
				cmp(arr[child + 1], arr[child])) ? 1 : 0; \
			arr[bubble] = arr[child]; \
			bubble = child; \
			child = lch(bubble); \
		} \
		while (child <= cnt); \
	} \
	hole = arr[cnt]; \
	cnt--; \
 \
	parent = par(bubble); \
	while (bubble > 0 && cmp(arr[bubble], arr[parent])) { \
		arr[bubble] = arr[parent];	\
		bubble = parent; \
		parent = par(bubble); \
	} \
	arr[bubble] = hole;	\
}

static int     len = 10000000;
static int     cnt = 0;
static int  bubble = 0;
static int  parent = 0;
static int   child = 0;
static float  hole = 0;
static float	tmp = 0;
static float*	arr = NULL;

int main(int argc, char **argv)
{
	printf("\033[2J\033[1;1H");

	if (argc == 1)
		printf("\n\t[ No length specified; using %d. ]\n", len);
	else
		sscanf(argv[1], "%d", &len);

	arr = malloc((len + ((len % 2 == 0) ? 1 : 2)) * sizeof (float));
	
	if (arr == NULL)
		return 1;

	printf("\n");
	printf("\t[ sizeof(int)\t]\t=\t%lu bit\n",   sizeof(int) * 8);
	printf("\t[ sizeof(float)\t]\t=\t%lu bit\n", sizeof(float) * 8);
	printf("\t[ sizeof(arr)\t]\t=\t%lu bit\n",  sizeof(arr) * 8);

	printf("\n\t[ length\t]\t=\t%d\n\n", len);
	
	clock_t now = clock();
	
	for (int i = 0; i < len - 1; i++)
		ins(.0001f);

	ins(10000.0f);
	
	while (cnt > 1) {
		tmp = arr[1];
		del();
		tmp += arr[1];
		del();
		ins(tmp);
	}
	
	printf("\t[ time\t\t]\t=\t%f s\n", (clock() - now)/((double)CLOCKS_PER_SEC));
	printf("\t[ result\t]\t=\t%f\n\n", arr[1]);
	
	free(arr);
	return 0;
}
