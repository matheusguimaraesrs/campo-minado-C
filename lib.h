#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

/*CELULA
isBomb: 0 || 1
open: 0 || 1
neighbor: 0 a 4
 */

typedef struct
{
	int isBomb;
	int	isOpen;
	int	neighbor;
}	cell;

// Variáveis globais
extern int size;
extern int l, c;
extern cell game[10][10];

void play_game();
void new_bombs(int n);
int	 is_valid(int l, int c);
int  neighbor_bombs(int l, int c);
void count_bombs();
void print_game();
void open_cell(int l, int c);
int	 win();
void player();

#endif