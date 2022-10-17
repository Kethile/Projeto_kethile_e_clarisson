#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int pizza_cont=0, sanduiche_cont=0, options, tamanho, quant;

    float pizzas[6] = {12.00, 18.00, 33.00, 36.00, 43.50, 49.00}, pizza_soma=0;
    float sanduiche[13] = {8.50, 10.50, 13.50, 14.00, 14.50, 16.00, 17.00, 16.00, 19.00, 15.50, 13.50, 17.00, 26.00}, sanduiche_soma=0;

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

            //Aqui temos o chunk dos sanduíches
            case 2:
            printf("\n1- Misto \n2- Misto Especial \n3- Piteco \n4- Cascão \n5- Cebolinha \n6- Mônica \n7- Rosinha \n8- Chico Bento \n9- Magali \n10- Calabresa\n");
            printf("\nQual opção? ");
            scanf("%i", &tamanho);
            printf("\nQuantos? ");
            scanf("%i", &quant);
            sanduiche_soma = sanduiche_soma + (quant * sanduiche[tamanho-1]); 
            sanduiche_cont++;
            printf("\nEntrada concluída! (%.2f reais)\n", sanduiche_soma);

            break; 
    
            default:
            break;
        }

    } while (options != 4);

    printf("\nVendas realizadas: %i", (pizza_cont + sanduiche_cont));
    printf("\nMontante vendido em pizza: %.2f reais", pizza_soma);
    printf("\nMontante vendido em sanduíche: %.2f reais", sanduiche_soma);



    return 0;
}