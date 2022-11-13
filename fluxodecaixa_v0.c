#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char lista_pizzas[50][50] = {"Presunto", "Muçarela", "Bacon", "Calabresa", "Frango", "Bolonhesa", "Salaminho", "Lombinho", "À moda", "Amoricada", "Portuguese", "Atum"};
    char lista_sanduiches[50][50] = {"Misto", "Misto Especial", "Piteco", "Cascão", "Cebolinha", "Mônica", "Rosinha", "Chico Bento", "Magali", "Calabresa", "X-Vegetal", "X-Cedaf", "X-Amoricana"};
    char lista_massas[50][50] = {"Espaguete Bolonhesa", "Espaguete de Frango", "Espaguete Molho Vermelho", "Alho e óleo", "Espaguete na Chapa", "Omelete", "Lasanha"};
    
    float pizzas[12][6] = 
    {12.00, 18.00, 33.00, 36.00, 43.50, 49.00, // presunto
    12.00, 18.00, 33.00, 36.00, 43.50, 49.00, // muçarela
    12.00, 18.00, 33.00, 36.00, 44.50, 50.00, // bacon
    12.00, 18.00, 33.00, 36.00, 43.50, 50.00, // calabresa
    12.00, 18.00, 33.00, 36.00, 44.50, 49.00, // frango
    12.00, 18.00, 34.00, 37.00, 44.50, 49.00, // bolonhesa
    12.00, 18.00, 34.00, 36.00, 45.00, 50.50, // salaminho
    12.00, 18.00, 33.00, 36.00, 45.50, 50.00, // lombinho
    12.00, 18.00, 33.00, 36.00, 44.50, 50.00, // a moda
    12.00, 18.00, 34.00, 39.00, 45.00, 50.00, // amoricana
    12.00, 18.00, 34.00, 37.50, 44.50, 50.00, // portuguesa
    17.00, 21.00, 34.00, 37.50, 45.00, 51.50}; // atum
    float pizza_soma = 0.0;

    float sanduiche[13] = {8.50, 10.50, 13.50, 14.00, 14.50, 16.00, 17.00, 16.00, 19.00, 15.50, 13.50, 17.00, 26.00}, sanduiche_soma=0;
    float massas[7] = {14.0, 14.0, 14.0, 14.0, 16.0, 15.0};

    int pizza_cont=0, sanduiche_cont=0, options, tamanho, quantidade;
    int auxiliar=0;

    float pedidos[10][4];

    

    int linha=0, coluna=0;
    int escolha_1, escolha_2, escolha_3;

    //printf("################# FLUXO DE CAIXA #################\n");

    printf("\n##########  ABRINDO CAIXA ##########\n");

    for (int i = 0; i < 999; i++)
    {
        printf("\n1- Novo pedido     2- Fechar caixa\n");
        printf("\nQual opção? ");
        scanf("%i", &escolha_1);
        pizza_soma = 0.0;

        if (escolha_1 == 2) break;
        
        do
        {
            printf("\n####### PEDIDO Nº%i #######\n\n", i);
            printf("1- Pizzas     2- Sanduíches\n3- Massas     4- Finalizar pedido\n");
            printf("\nQual opção? ");
            scanf("%i", &options);
                    
            switch (options)
            {
                //Aqui temos o chunk para as pizzas
                case 1:
                for (int i = 0; i < 12; i++)
                {
                    printf("%i- %s\n", i, lista_pizzas[i]);
                }
                printf("\nQual opção? ");
                scanf("%i", &escolha_2);

                printf("\n0- Pequena   1- Broto      2- Média\n3- Grande    4- Gigante    5- Big\n");
                printf("\nQual opção? ");
                scanf("%i", &escolha_3);

                printf("\nQuantidade? ");
                scanf("%i", &quantidade);

                pizza_soma = pizza_soma + quantidade * (pizzas[escolha_2][escolha_3]);
                pedidos[i][0] = pizza_soma;

                printf("\nEntrada concluída!\nTotal do pedido: (%.2f reais)\n", pizza_soma);

                break;

                //Aqui temos o chunk dos sanduiches
                case 2:
                for (int i = 0; i < 13; i++)
                {
                    printf("%i- %s\n", i, lista_sanduiches[i]);
                }
                printf("\nQual opção? ");
                scanf("%i", &escolha_2);

                printf("\nQuantidade? ");
                scanf("%i", &quantidade);

                sanduiche_soma = sanduiche_soma + quantidade * (sanduiche[escolha_2]);
                pedidos[i][1] = sanduiche_soma;

                printf("\nEntrada concluída!\nTotal do pedido: (%.2f reais)\n", sanduiche_soma);

                break;

                default:
                break;

            }

        } while (options != 4);

    }




    printf("\nTeste:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%.2f | ", pedidos[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}