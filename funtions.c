#include "lib.h"

// Definição das variáveis globais
int size = 10;
int l, c;
cell game[10][10];

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

//função que diz se um par de cordenadas é false || true (0 ou 1)
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
			game[l][c].neighbor = neighbor_bombs(l, c);
	}
}

//função para imprimir o jogo
void print_game()
{	
	printf("\n\n\t   ");
	for (l = 0; l < size; l++)
		printf(" %d  ", l);
	printf("\n\t   ----------------------------------------\n");
	for(l = 0; l < size; l++)
	{
		printf("\t%d |", l);
		for(c = 0; c < size; c++)
		{
			if(game[l][c].isOpen)
			{
				if (game[l][c].isBomb)
					printf(" * ");
				else
					printf(" %d ", game[l][c].neighbor);
			}
			else
				printf("   ");
			printf("|"); 
		}
		printf("\n\t   ----------------------------------------\n");
	}
}
//função para abrir a célula
void open_cell(int l, int c)
{
	if (is_valid(l, c) == 1 && game[l][c].isOpen == 0)
	{
		game[l][c].isOpen = 1;
		if (game[l][c].neighbor == 0)
		{
			open_cell(l - 1, c);
			open_cell(l + 1, c);
			open_cell(l, c - 1);
			open_cell(l, c + 1);
		}
	}
}

//Fução para verificar vitória 1 = ganhou 0 = ainda não ganhou

int win()
{
	int count = 0;

	for(l = 0; l < size; l++)
	{
		for(c = 0; c < size; c++)
		{
			if (game[l][c].isOpen == 0 && game[l][c].isBomb == 0)
				count++;
		}
	}
	return (count);
}

//Recebe as coordenadas do player
void player(){
	int	l, c;

	do
	{
        system("clear");
		print_game();
		do
		{
			printf("\nDigite as coordenadas de Linha e Coluna: ");
			scanf("%d%d", &l, &c);
			if (is_valid(l, c) == 0 || game[l][c].isOpen == 1)
				printf("Coordenada invalida ou já aberta!");
		} while (is_valid(l, c) == 0 || game[l][c].isOpen == 1);
		open_cell(l, c);
	} while (win() != 0 && game[l][c].isBomb == 0);
    system("clear");
	if (game[l][c].isBomb == 1)
		printf("\n\t\t  VOCÊ PERDEU OTARIO\n");
	else
		printf("\n\t\t  PARABENS VOCE GANHOU\n");
	print_game();
}