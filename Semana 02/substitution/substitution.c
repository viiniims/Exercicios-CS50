#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char plaintext[100];

int main (int argc, char *argv[])
{
    // Verifica se existe apenas um argumento
    if(argc != 2)
    {
        printf("Use: ./substituition key\n");
        return 1;
    }
    
    // Verifica se o Argumento tem apenas letras
    char *key = argv[1];

    for(int i = 0; i < strlen(key); i++)
        
        if(!isalpha(argv[1][i]))
        {
            printf("Use: ./substituition key\n");
            return 1;
        }

        // Verifica se a chave tem exatamente 26 letras
        if (strlen(key) != 26)
        {
            printf("A chave deve conter 26 caracteres.\n");
            return 1;
        }

        // Verifica se existem letras repetidas
        for(int i= 0; i < strlen(key); i++)
        {
            for(int j = i + 1; j < strlen(key); j++)
            {
                if(toupper(key[i]) == toupper(key[j]))
                {
                    printf("Use: ./substituition key\n");
                    return 1;
                }
            }
        }

    printf("Digite o texto a ser criptografado: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    //Codifica e imprime o texto
    for(int i= 0; i < strlen(plaintext); i++)
    {
        if(isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf ("%c", key[letter]);
        }

        else if(islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf ("%c", key[letter] + 32);
        }

        else
        {
            printf ("%c", plaintext[i]);
        }
    }
    
    printf("\n");
    return 0;
}