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

    float sanduiche[13] = {8.50, 10.50, 13.50, 14.00, 14.50, 16.00, 17.00, 16.00, 19.00, 15.50, 13.50, 17.00, 26.00};
    float massas[7] = {14.0, 14.0, 14.0, 14.0, 16.0, 15.0};
    
    float pedidos[999][4] = {0};

    int escolha_1, escolha_2, escolha_3, escolha_4;
    int options, quantidade, cont_linhas=0, frete=0;
    int cont_pizza=0, cont_sanduiche=0, cont_massa=0;
    
    float soma_pizza=0, soma_sanduiche=0, soma_massa=0, soma=0, soma_linhas[999], soma_colunas[999];

    //printf("################# FLUXO DE CAIXA #################\n");

    printf("\n########## ABRINDO CAIXA ##########\n");

    for (int i = 0; i < 999; i++)
    {
        printf("\n1- Novo pedido     2- Fechar caixa\n");
        printf("\nQual opção? ");
        scanf("%i", &escolha_1);
        soma_pizza=0; 
        soma_sanduiche=0; 
        soma_massa=0;
        cont_linhas++;

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
                
                soma_pizza = soma_pizza + quantidade * (pizzas[escolha_2][escolha_3]);
                pedidos[i][0] = soma_pizza;
                cont_pizza = cont_pizza + quantidade;

                printf("\nEntrada concluída!\nTotal do pedido: (%.2f reais)\n", soma_pizza);

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

                soma_sanduiche = soma_sanduiche + quantidade * (sanduiche[escolha_2]);
                pedidos[i][1] = soma_sanduiche;
                cont_sanduiche = cont_sanduiche + quantidade;

                printf("\nEntrada concluída!\nTotal do pedido: (%.2f reais)\n", soma_sanduiche);

                break;

                //Aqui temos o chunk das massas
                case 3:
                for (int i = 0; i < 7; i++)
                {
                    printf("%i- %s\n", i, lista_massas[i]);
                }
                printf("\nQual opção? ");
                scanf("%i", &escolha_2);

                printf("\nQuantidade? ");
                scanf("%i", &quantidade);

                soma_massa = soma_massa + quantidade * (massas[escolha_2]);
                pedidos[i][2] = soma_massa;
                cont_massa = cont_massa + quantidade;

                printf("\nEntrada concluída!\nTotal do pedido: (%.2f reais)\n", soma_massa);

                break;

                // Calculando o frete
                case 4:
                printf("\n1- Retirada   2- Entrega\n\nQual opção? ");
                scanf("%i", &escolha_4);
                if (escolha_4 == 2)
                {
                    pedidos[i][3] = 3;
                    frete++;
                }
                
                default:
                break;

            }

        } while (options != 4);

    }

    //Somando as linhas
    for (int i = 0; i < cont_linhas-1; i++)
    {
        soma=0;
        for (int j = 0; j < 4; j++)
        {
            soma = soma + pedidos[i][j];
        }
        soma_linhas[i] = soma;
    }

    //Somando as colunas
    for (int j = 0; j < 4; j++)
    {
        soma=0;
        for (int i = 0; i < cont_linhas-1; i++)
        {
            soma = soma + pedidos[i][j];
        }
        soma_colunas[j] = soma;
    }

    //###### APENAS TESTE ######
    printf("\nTeste:\n");
    for (int i = 0; i < cont_linhas-1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%.2f | ", pedidos[i][j]);
        }
        printf("\n");
    }
    /*
    printf("\nSoma linhas: ");
    for (int i = 0; i < cont-1; i++)
    {
        printf("%.2f | ", soma_linhas[i]);
    }

    printf("\nSoma colunas: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%.2f | ", soma_colunas[i]);
    }
    //###### APENAS TESTE ######
    */

    printf("\n\nTotal vendido em pizza: %i pizzas (%.2f reais)", cont_pizza, soma_colunas[0]);
    printf("\nTotal vendido em sanduíche: %i sanduíches (%.2f reais)", cont_sanduiche, soma_colunas[1]);
    printf("\nTotal vendido em massa: %i massas (%.2f reais)", cont_massa, soma_colunas[2]);
    printf("\nFaturamenteo total: %.2f reais", soma_colunas[0] + soma_colunas[1] + soma_colunas[2] + soma_colunas[3]);

    printf("\nEntregas feitas na noite: %i", frete);
    printf("\nTotal do frete: %.2f reais", soma_colunas[3]);
    
    return 0;
}