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
	int	isOpen;
	int	neighbor;
}	cell;
//variáveis globais
cell game[10][10];
int	l, c, size = 10;


//função para iniciar a matriz do jogo. Limpa toda matriz.
void play_game()
{
	for(l = 0; l < size; l++)
	{
		for(c = 0; c < size; c++)
		{
			game[l][c].isBomb = 0;
			game[l][c].isOpen = 0;
			game[l][c].neighbor = 0;
		}
	}
}
//função para sortear bombas aleatoriamente
void new_bombs(int n)
{
	srand(time(NULL));
	for(int i = 0; i <= n; i++)
	{
		l = rand() % size;
		c = rand() % size;
		if (game[l][c].isBomb == 0)
			game[l][c].isBomb = 1;
		else
			i--;
	}
}

//função que diz se um par de cordenadas é false ou true (0 ou 1)
int	is_valid(int l, int c)
{
	if((l >= 0 && l < size) && (c >= 0 && c < size))
		return (1);
	else
		return (0);
}

//função que retorna quantidade de bombas
int	neighbor_bombs(int l, int c)
{
	int count = 0;
	if(is_valid(l-1, c) && game[l-1][c].isBomb)
		count++;
	if(is_valid(l+1, c) && game[l+1][c].isBomb)
		count++;
	if(is_valid(l, c-1) && game[l][c+1].isBomb)
		count++;
	if(is_valid(l, c+1) && game[l][c-1].isBomb)
		count++;
	return (count);
}

//função para contar as bombas vizinhas
void count_bombs()
{
	for(l = 0; l < size; l++)
	{
		for(c = 0; c < size; c++)
		{
			game[l][c].neighbor = neighbor_bombs(l, c);
		}
	}
}

int main(void)
{
	play_game();
	new_bombs(10);
	count_bombs();
	return (0);
}
