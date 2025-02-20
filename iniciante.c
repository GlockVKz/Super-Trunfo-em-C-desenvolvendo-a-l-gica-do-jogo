#include <stdio.h>

#define ATRIBUTO_COMPARACAO 1 

int main() {
    char estado1[10], estado2[10];
    char nomecidade1[50], nomecidade2[50];
    char codigo1[10], codigo2[10];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int numerodepontos1, numerodepontos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    printf("Qual o nome do estado da primeira cidade?\n");
    scanf("%s", estado1);

    printf("Qual o código da primeira cidade?\n");
    scanf("%s", codigo1);

    printf("Qual o nome da primeira cidade?\n");
    scanf("%s", nomecidade1);

    printf("Quantas pessoas tem na primeira cidade?\n");
    scanf("%lu", &populacao1);

    printf("Qual a área da primeira cidade (em km²)?\n");
    scanf("%f", &area1);

    printf("Qual o PIB da primeira cidade (em bilhões de reais)?\n");
    scanf("%f", &pib1);

    printf("Qual o número de pontos turísticos da primeira cidade?\n");
    scanf("%d", &numerodepontos1);

    printf("\nQual o nome do estado da segunda cidade?\n");
    scanf("%s", estado2);

    printf("Qual o código da segunda cidade?\n");
    scanf("%s", codigo2);

    printf("Qual o nome da segunda cidade?\n");
    scanf("%s", nomecidade2);

    printf("Quantas pessoas tem na segunda cidade?\n");
    scanf("%lu", &populacao2);

    printf("Qual a área da segunda cidade (em km²)?\n");
    scanf("%f", &area2);

    printf("Qual o PIB da segunda cidade (em bilhões de reais)?\n");
    scanf("%f", &pib2);

    printf("Qual o número de pontos turísticos da segunda cidade?\n");
    scanf("%d", &numerodepontos2);

    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    float valor1, valor2;
    char atributo_nome[30];

    if (ATRIBUTO_COMPARACAO == 1) {
        valor1 = populacao1;
        valor2 = populacao2;
        sprintf(atributo_nome, "População");
    } else if (ATRIBUTO_COMPARACAO == 2) {
        valor1 = area1;
        valor2 = area2;
        sprintf(atributo_nome, "Área");
    } else if (ATRIBUTO_COMPARACAO == 3) {
        valor1 = pib1;
        valor2 = pib2;
        sprintf(atributo_nome, "PIB");
    } else if (ATRIBUTO_COMPARACAO == 4) {
        valor1 = densidade1;
        valor2 = densidade2;
        sprintf(atributo_nome, "Densidade Populacional");
    } else if (ATRIBUTO_COMPARACAO == 5) {
        valor1 = pibPerCapita1;
        valor2 = pibPerCapita2;
        sprintf(atributo_nome, "PIB per Capita");
    } else {
        printf("Atributo de comparação inválido.\n");
        return 1;
    }

    int cartaVencedora;
    if (ATRIBUTO_COMPARACAO == 4) { 
        cartaVencedora = (valor1 < valor2) ? 1 : 2;
    } else { 
        cartaVencedora = (valor1 > valor2) ? 1 : 2;
    }

    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", nomecidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", numerodepontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", nomecidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", numerodepontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    printf("\n--- Comparação de Cartas ---\n");
    printf("Atributo Comparado: %s\n", atributo_nome);
    printf("Carta 1 - %s (%s): %.2f\n", nomecidade1, estado1, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", nomecidade2, estado2, valor2);
    printf("Resultado: Carta %d (%s) venceu!\n", cartaVencedora, cartaVencedora == 1 ? nomecidade1 : nomecidade2);

    return 0;
}


