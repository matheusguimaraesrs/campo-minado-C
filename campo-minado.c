#include "lib.h"

int main(void)
{
	int option;

	do
	{
		play_game();
		new_bombs(10);
		count_bombs();
		printf("\n\t\t\tCAMPO MINADO");
		player();
		printf("\njogar novamente (1) | Desistir (0):  ");
		scanf("%d", &option);
	} while (option);
	return (0);
}
