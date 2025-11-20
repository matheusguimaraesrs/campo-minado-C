#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*CELULA
isBomb: 0 || 1
open: 0 || 1
neighbor: 0 a 4
 */

typedef struct
{
	int isBomb;
	int	open;
	int	neighbor;
}	cell;
//variáveis globais
cell game[10][10];
int	l, c, size = 10;


//função para iniciar a matriz do jogo. Limpa toda matriz.
void play_game()
{
	for(l = 0; l < tam; l++)
	{
		for(c = 0; c < tam; c++)
		{
			game[l][c].isBomb = 0;
			game[l][c].open = 0;
			game[l][c].neigjbor = 0;
		}
	}
}
//função para sortear bombas aleatoriamente
void new_bombs(int n)
{
	srand(time(NULL));
	for(int i = 0; i <= n; i++)
	{
		l = rand() % tam;
		c = rand() % tam;
		if (game[l][c].isBomb == 0)
			game[l][c].isBomb = 1;
		else
			i--;
	}
}


int main(void)
{
	play_game();
	new_bombs(10);

	return (0);
}
