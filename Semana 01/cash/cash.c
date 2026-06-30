#include <stdio.h>
#include <math.h>

int main (void)

{
    float troco;
    int centavos;
    int moedas;
    int moeda25 = 0;
    int moeda10 = 0;
    int moeda5 = 0;
    int moeda1 = 0;

    do
{
    printf ("Quanto de troco falta?: R$");
    scanf ("%f", &troco);
}
    while ( troco <= 0);

    centavos = round (troco * 100);
{
    while (centavos >= 25)
    {
        centavos -= 25;
         moeda25++;
    }
   
    printf (" Moedas de 25 centavos: %i\n", moeda25);
}

{
     while (centavos >= 10)
    {
        centavos -= 10;
         moeda10++;
    }

    printf (" Moedas de 10 centavos:  %i\n", moeda10);
}

{
    while (centavos >= 5)
    {
        centavos -= 5;
         moeda5++;
    }

    printf (" Moedas de 5 centavos:  %i\n", moeda5);
}

{
    while (centavos >= 1)
    {
        centavos -= 1;
         moeda1++;
    }

    printf (" Moedas de 1 centavo:  %i\n", moeda1);
}
    moedas = ( moeda25 + moeda10 + moeda5 + moeda1);

    printf ("Total de moedas:  %i\n", moedas);
}   