#include <stdio.h>
#include <string.h>

int main() {
    char estado1[10], estado2[10];
    char nomecidade1[50], nomecidade2[50];
    char codigo1[10], codigo2[10];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int numerodepontos1, numerodepontos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    char sair[30];

    printf("Qual o nome do estado da primeira cidade?\n");
    scanf("%s", estado1);
    printf("Qual o c\u00f3digo da primeira cidade?\n");
    scanf("%s", codigo1);
    printf("Qual o nome da primeira cidade?\n");
    scanf("%s", nomecidade1);
    printf("Quantas pessoas tem na primeira cidade?\n");
    scanf("%lu", &populacao1);
    printf("Qual a \u00e1rea da primeira cidade (em km\u00b2)?\n");
    scanf("%f", &area1);
    printf("Qual o PIB da primeira cidade (em bilh\u00f5es de reais)?\n");
    scanf("%f", &pib1);
    printf("Qual o n\u00famero de pontos tur\u00edsticos da primeira cidade?\n");
    scanf("%d", &numerodepontos1);

    printf("\nQual o nome do estado da segunda cidade?\n");
    scanf("%s", estado2);
    printf("Qual o c\u00f3digo da segunda cidade?\n");
    scanf("%s", codigo2);
    printf("Qual o nome da segunda cidade?\n");
    scanf("%s", nomecidade2);
    printf("Quantas pessoas tem na segunda cidade?\n");
    scanf("%lu", &populacao2);
    printf("Qual a \u00e1rea da segunda cidade (em km\u00b2)?\n");
    scanf("%f", &area2);
    printf("Qual o PIB da segunda cidade (em bilh\u00f5es de reais)?\n");
    scanf("%f", &pib2);
    printf("Qual o n\u00famero de pontos tur\u00edsticos da segunda cidade?\n");
    scanf("%d", &numerodepontos2);

    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    do {
        int escolha;
        float valor1, valor2;
        char atributo_nome[30];

        printf("\nEscolha o atributo para compara\u00e7\u00e3o:\n");
        printf("1 - Popula\u00e7\u00e3o\n2 - \u00c1rea\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n");
        printf("Digite o n\u00famero do atributo: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                valor1 = populacao1;
                valor2 = populacao2;
                strcpy(atributo_nome, "Popula\u00e7\u00e3o");
                break;
            case 2:
                valor1 = area1;
                valor2 = area2;
                strcpy(atributo_nome, "\u00c1rea");
                break;
            case 3:
                valor1 = pib1;
                valor2 = pib2;
                strcpy(atributo_nome, "PIB");
                break;
            case 4:
                valor1 = densidade1;
                valor2 = densidade2;
                strcpy(atributo_nome, "Densidade Populacional");
                break;
            case 5:
                valor1 = pibPerCapita1;
                valor2 = pibPerCapita2;
                strcpy(atributo_nome, "PIB per Capita");
                break;
            default:
                printf("Op\u00e7\u00e3o inv\u00e1lida!\n");
                continue;
        }

        int cartaVencedora;
        if (escolha == 4) {
            cartaVencedora = (valor1 < valor2) ? 1 : (valor1 > valor2 ? 2 : 0);
        } else {
            cartaVencedora = (valor1 > valor2) ? 1 : (valor1 < valor2 ? 2 : 0);
        }

        printf("\n--- Comparac\u00e3o de Cartas ---\n");
        printf("Atributo Comparado: %s\n", atributo_nome);
        printf("Carta 1 - %s (%s): %.2f\n", nomecidade1, estado1, valor1);
        printf("Carta 2 - %s (%s): %.2f\n", nomecidade2, estado2, valor2);
        if (cartaVencedora == 0) {
            printf("Resultado: Empate!\n");
        } else {
            printf("Resultado: Carta %d (%s) venceu!\n", cartaVencedora, cartaVencedora == 1 ? nomecidade1 : nomecidade2);
        }

        printf("\nDigite 'Comparacao Concluida' para sair ou pressione Enter para jogar novamente: ");
        getchar(); 
        fgets(sair, sizeof(sair), stdin);
        sair[strcspn(sair, "\n")] = 0;
    } while (strcmp(sair, "Comparacao Concluida") != 0);

    printf("\nJogo encerrado. Obrigado por jogar!\n");
    return 0;
}


