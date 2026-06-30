#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char texto [300];

int coleman (char texto[])
{
    int letras = 0;
    int palavras = 0;
    int frases = 0;
    bool palavra = false;

    for (int i = 0; i < strlen(texto); i++)
    {
        if ( isalpha(texto[i]))
        {
            letras++;
            if (!palavra)
            {
                palavras++;
                palavra = true;
            }
        }

        else if ((texto[i]) == '.' || (texto[i]) == '!' || (texto[i]) == '?')
        {
            frases++;
        }

        else
        {
            palavra = false;
        }
    }
    printf ("Quantidade de letras: %i\n", letras);
    printf ("Quantidade de palavras: %i\n", palavras);
    printf ("Quantidade de frases: %i\n", frases);

    float L = 100.0 * letras / palavras;
    float S = 100.0 * frases / palavras;

    return round(0.0588 * L - 0.296 * S - 15.8);
}

int main (void)
{
    printf ("Digite o texto escolhido:");
    fgets(texto, sizeof(texto), stdin);

    int soma = coleman(texto);
    
    if (soma >= 16)
    {
        printf ("Classe 16+");
    }
    else if (soma < 1)
    {
         printf ("Antes da classe 1");
    }
    else
    {
         printf ("Classe %i", soma);
    }
}