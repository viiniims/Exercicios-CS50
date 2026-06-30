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
        printf("Use: ./caesar key\n");
        return 1;
    }

    // Salva a Chave
    char *key = argv[1];

    // Verifica se o Argumento tem apenas números
    int len = strlen(argv[1]);

    for(int i= 0; i < len; i++)
        
        if(!isdigit(argv[1][i]))
        {
            printf("Use: ./caesar key\n");
            return 1;
        }

    printf("Digite o texto a ser criptografado: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    //Transfoma a chave em numero
    int k = atoi(key);
    
    //Codifica e imprime o texto
    int tamanho = strlen(plaintext);

    for(int i= 0; i < tamanho; i++)
    { 
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 'A') + k) %26) + 'A');
        }

        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 'a') + k) %26) + 'a');
        }
        
        else
        {
            printf("%c", (plaintext[i]) );
        }
        
    }
    
    printf("\n");
}