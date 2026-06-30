#include <stdio.h>
#include <math.h>

// Protótipos
int num_cartao (long long card);
int primeiros (int digitos,long long card);
int multiplicacao (long long card);
int somar (long long card);

int main (void)

{
   long long card;

    do
    {
        printf (" Digite o numero do seu cartao: ");
        scanf ("%lld", &card);
    }
    while (card <= 0);

    int digitos = num_cartao (card);
    int dois_dig = primeiros (digitos, card);
    int multi = multiplicacao (card);
    int soma = somar (card);

    int luhn = multi + soma;

    printf ("Quantidade de digitos : %i\n", digitos);
    printf ("Dois Primeiros Digitos : %i\n", dois_dig);
    printf ("Algoritimo de Luhn : %i\n", luhn);

    if (luhn % 10 == 0)
{
    if ((dois_dig == 34 || dois_dig == 37) && digitos == 15)
{
    printf("VALIDO! - AMEX\n");
}
else if ((dois_dig >= 51 && dois_dig <= 55) && digitos == 16)
{
    printf("VALIDO! - MASTERCARD\n");
}
else if ((dois_dig / 10 == 4) && (digitos == 13 || digitos == 16))
{
    printf("VALIDO! - VISA\n");
}
else
{
    printf("VALIDO MAS BANDEIRA DESCONHECIDA\n");
}
}
else
{
    printf("INVALIDO\n");
}

}

// Funções

int num_cartao (long long card)
{
    int digitos = 0;

    // Obter quantidade de digitos
    while ( card > 0)
    {
        card /= 10;
        digitos++;
    }
    return digitos;
    
}

int primeiros(int digitos, long long card)

{
    while (card >= 100)
    {
        card /= 10;
    }

    return card;
    
}

int multiplicacao (long long card)

{
    int multi = 0;
    
    // começa no penúltimo dígito
    card /= 10;
    
    while (card > 0)
    {
        int opera = (card % 10) * 2;

        // soma os digitos se o resultado for => 10
        if (opera > 9)
        {
            opera = (opera % 10) + (opera / 10);
        }

        multi += opera;

         // pula dois dígitos
        card /= 100;
    }

    return multi;
}

int somar (long long card)

{
    int soma = 0;

    while ( card > 0)
    {
        soma += card % 10;

         // pula dois dígitos
        card /= 100;
    }
    return soma;
}
