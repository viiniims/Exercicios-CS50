#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tabela[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculo (char palavra[]);
char player1 [25], player2[25];

int main (void)

{ 
    printf ("Player 01: \n");
	scanf (" %s", player1);

    printf ("Player 02: \n");
	scanf (" %s", player2);

    int pontos1 = calculo(player1);
    int pontos2 = calculo(player2);
 
    printf ("Player 01 total points: %i\n", pontos1);
    printf ("Player 02 total points: %i\n", pontos2);

    if (pontos1 > pontos2)
    {
         printf (" Player 01 Venceu!!!");
    }
    else if (pontos1 <  pontos2)
    {
        printf (" Player 02 Venceu!!!");
    }
    else
    {
        printf (" Empate!!!");
    }

}

int calculo (char palavra[])

{
    int soma = 0;

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (isalpha(palavra[i]))
        {
            char letra = toupper(palavra[i]);
            soma += tabela[letra - 'A'];
        }
    }
    return soma;
}