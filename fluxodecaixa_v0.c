#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int pizza_cont=0, options, tamanho, quant;

    float pizzas[6] = {12.00, 18.00, 33.00, 36.00, 43.50, 49.00}, pizza_soma=0;
    float massas[6] = {14.00, 14.00, 14.00, 14.00, 16.00, 15.00};

    printf("################# FLUXO DE CAIXA #################\n");
/*
    printf("Para assegurar o funcionamento correto, defina os preços previamente.\n\n");
    for (int i = 0; i < 1; i++)
    {
        printf("Pizza pequena: ");
        scanf("%f", &pizza[i]);
        printf("Pizza média: ");
        scanf("%f", &pizza[i+1]);
        printf("Pizza grande: ");
        scanf("%f", &pizza[i+2]);
    }

    printf("\nPizza pequena: %.2f", pizza[0]);
    printf("\nPizza media: %.2f", pizza[1]);
    printf("\nPizza grande: %.2f", pizza[2]);
*/

    printf("\n#################  ABRINDO CAIXA #################\n");

    do
    {
        printf("##################################################\n\n");
        printf("1- Pizzas     2- Sanduíches\n3- Massas     4- Fechar caixa\n");
        printf("\nQual opção? ");
        scanf("%i", &options);

        switch (options)
        {
            //Aqui temos o chunk para as pizzas
            case 1:
            printf("\n1- Pequena   2- Broto      3- Média\n4- Grande    5- Gigante    6- Big\n");
            printf("\nQual opção? ");
            scanf("%i", &tamanho);
            printf("\nQuantas? ");
            scanf("%i", &quant);
            pizza_soma = pizza_soma + (quant * pizzas[tamanho-1]); 
            pizza_cont++;
            printf("\nEntrada concluída! (%.2f reais)\n", pizza_soma);

            break;

            //Aqui temos o chunk dos hamburguers
            case 2:
            printf("\nAguarde a proxima atualização!\n");
            break; 
    
            default:
            break;
        }

    } while (options != 4);

    printf("\nMontante vendido em pizza: %.2f reais", pizza_soma);



    return 0;
}