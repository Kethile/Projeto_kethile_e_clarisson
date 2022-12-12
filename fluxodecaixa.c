#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

FILE *arquivo;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int lerOpcao();
    void lista_nomes();
    int lerQuantidade ();
    int tabela_pizza();
    
    float sanduiche[13] = {8.50, 10.50, 13.50, 14.00, 14.50, 16.00, 17.00, 16.00, 19.00, 15.50, 13.50, 17.00, 26.00};
    float massas[7] = {14.00, 14.00, 14.00, 14.00, 16.00, 15.00};
    float acrescimos[7] = {0.00, 6.00, 6.00, 8.00, 6.00, 5.00, 5.00};
    float pedidos[999][4] = {0};

    int escolha, option_1, option_2, lanche, tamanho, quantidade, acres;
    int cont_pizza=0, cont_sanduiche=0, cont_massa=0, cont_linhas=0, frete=0;
    float soma_pedido=0, soma=0, soma_linhas[999], soma_colunas[999], pizza;

    //printf("################# FLUXO DE CAIXA #################\n");

    printf("\n########## ABRINDO CAIXA ##########\n");

    for (int i = 0; i < 999; i++)
    {
        soma_pedido=0;
        cont_linhas++;

        printf("\n1- Novo pedido     2- Fechar caixa\n");
        option_1 = lerOpcao(1, 2);

        if (option_1 == 2) break;
        
        do
        {
            printf("\n####### PEDIDO Nº%i #######\n\n", i);
            printf("1- Pizzas     2- Sanduíches\n3- Massas     4- Finalizar pedido\n");
            option_2 = lerOpcao(1, 4);
                    
            switch (option_2)
            {
                //Aqui temos o chunk para as pizzas
                case 1:
                lista_nomes(1); // apenas printa a lista de pizzas
                lanche = lerOpcao(0, 12); // os paramêtros definem o intervalo a ser aceito
                printf("\n0- Pequena   1- Broto      2- Média\n3- Grande    4- Gigante    5- Big\n");
                tamanho = lerOpcao(0, 5);

                printf("\n### Acréscimos disponíveis ###\n");
                lista_nomes(4); // acrescimos
                acres = lerOpcao(0, 6);

                quantidade = lerQuantidade();
                pizza = tabela_pizza(lanche, tamanho);

                soma_pedido = soma_pedido + (quantidade * pizza) + acrescimos[acres];
                pedidos[i][0] = soma_pedido;
                cont_pizza = cont_pizza + quantidade;

                printf("\nEntrada concluída! (%.2f reais)", soma_pedido);

                break;

                //Aqui temos o chunk dos sanduiches
                case 2:
                lista_nomes(2);
                lanche = lerOpcao(0, 13);
                quantidade = lerQuantidade();

                soma_pedido = soma_pedido + quantidade * (sanduiche[lanche]);
                pedidos[i][1] = soma_pedido;
                cont_sanduiche = cont_sanduiche + quantidade;

                printf("\nEntrada concluída! (%.2f reais)", soma_pedido);

                break;

                //Aqui temos o chunk das massas
                case 3:
                lista_nomes(3);
                lanche = lerOpcao(0, 7);
                quantidade = lerQuantidade();

                soma_pedido = soma_pedido + quantidade * (massas[lanche]);
                pedidos[i][2] = soma_pedido;
                cont_massa = cont_massa + quantidade;

                printf("\nEntrada concluída! (%.2f reais)", soma_pedido);

                break;

                // Calculando o frete
                case 4:
                printf("\n1- Retirada   2- Entrega\n");
                escolha = lerOpcao(1, 2);

                if (escolha == 2)
                {
                    pedidos[i][3] = 3;
                    frete++;
                }

                default:
                break;

            }

        } while (option_2 != 4);

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

    /*###### MOSTRAR A MATRIZ ######
    printf("\nTeste:\n");
    for (int i = 0; i < cont_linhas-1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%.2f | ", pedidos[i][j]);
        }
        printf("\n");
    }*/

    

    printf("\nTotal vendido em pizza: %i pizzas (%.2f reais)", cont_pizza, soma_colunas[0]);
    printf("\nTotal vendido em sanduíche: %i sanduíches (%.2f reais)", cont_sanduiche, soma_colunas[1]);
    printf("\nTotal vendido em massa: %i massas (%.2f reais)", cont_massa, soma_colunas[2]);
    printf("\nTotal do frete: %.2f reais", soma_colunas[3]);
    printf("\nEntregas feitas na noite: %i", frete);
    printf("\nFaturamenteo total: %.2f reais", soma_colunas[0] + soma_colunas[1] + soma_colunas[2] + soma_colunas[3]);

    arquivo = fopen("log_noites.txt", "a+");
    fprintf(arquivo, "\n\nTotal vendido em pizza: %i pizzas (%.2f reais)", cont_pizza, soma_colunas[0]);
    fprintf(arquivo, "\nTotal vendido em sanduíche: %i sanduíches (%.2f reais)", cont_sanduiche, soma_colunas[1]);
    fprintf(arquivo, "\nTotal vendido em massa: %i massas (%.2f reais)", cont_massa, soma_colunas[2]);
    fprintf(arquivo, "\nTotal do frete: %.2f reais", soma_colunas[3]);
    fprintf(arquivo, "\nEntregas feitas na noite: %i", frete);
    fprintf(arquivo, "\nFaturamenteo total: %.2f reais", soma_colunas[0] + soma_colunas[1] + soma_colunas[2] + soma_colunas[3]);
    
    return 0;
}

int tabela_pizza(int escolha, int tamanho)
{
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

    float resultado;
    resultado = pizzas[escolha][tamanho];
    return resultado;
}

int lerOpcao (int inicio, int fim)
{
    int auxiliar;
    do
    {
        printf("\nQual opção? ");
        scanf("%i", &auxiliar);
    } while (auxiliar < inicio || auxiliar > fim);

    return auxiliar;
}

int lerQuantidade ()
{
    int auxiliar;
    do
    {
        printf("\nQuantidade? ");
        scanf("%i", &auxiliar);
    } while (auxiliar < 0);

    return auxiliar;
}

void lista_nomes(int escolha)
{
    char lista_pizzas[50][50] = {"Presunto", "Muçarela", "Bacon", "Calabresa", "Frango", "Bolonhesa", "Salaminho", "Lombinho", "À moda", "Amoricana", "Portuguesa", "Atum"};
    char lista_sanduiches[50][50] = {"Misto", "Misto Especial", "Piteco", "Cascão", "Cebolinha", "Mônica", "Rosinha", "Chico Bento", "Magali", "Calabresa", "X-Vegetal", "X-Cedaf", "X-Amoricana"};
    char lista_massas[50][50] = {"Espaguete Bolonhesa", "Espaguete de Frango", "Espaguete Molho Vermelho", "Alho e óleo", "Espaguete na Chapa", "Omelete", "Lasanha"};
    char lista_acrescimo[50][50] = {"Nenhum", "Cheddar", "Catupiry", "Cream chesee", "Caramelo", "Bacon", "Palmito"};

    printf("\n");
    switch (escolha)
    {
    case 1:
        for (int i = 0; i < 12; i++)
        {
            printf("%i- %s\n", i, lista_pizzas[i]);
        }
        break;

    case 2:
        for (int i = 0; i < 13; i++)
        {
            printf("%i- %s\n", i, lista_sanduiches[i]);
        }
        break;

    case 3:
        for (int i = 0; i < 7; i++)
        {
            printf("%i- %s\n", i, lista_massas[i]);
        }
    break;

    case 4:
        for (int i = 0; i < 7; i++)
        {
            printf("%i- %s\n", i, lista_acrescimo[i]);
        }
    break;

    default:
    break;
    }
}
