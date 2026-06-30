#include <stdio.h>
#include <math.h>

int main (void)

{
    long lhamas, ini_lhamas, fim_lhamas;
    int anos;

    do
    {
        printf ( " Digite a quantidade inicial de Lhamas: ");
        scanf ( "%ld", &ini_lhamas);
    }
    while ( ini_lhamas < 9);

    do
    {
        printf ( " Digite a quantidade final de Lhamas: ");
        scanf ( "%ld", &fim_lhamas);
    } 
    while (fim_lhamas < ini_lhamas);
    
    lhamas = ini_lhamas;
    anos = 0;

    while ( lhamas < fim_lhamas)
    {
        lhamas = lhamas + (lhamas / 3) - (lhamas / 4);
        anos++;
    }

    printf (" Quantidade de anos nescessarios: %i\n", anos);

}