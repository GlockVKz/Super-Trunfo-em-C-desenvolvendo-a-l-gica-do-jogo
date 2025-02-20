#include <stdio.h>

int main() {
    char estado1[10], estado2[10];
    char nomecidade1[50], nomecidade2[50];
    char codigo1[10], codigo2[10];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int numerodepontos1, numerodepontos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

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

    superPoder1 = populacao1 + area1 + (pib1 * 1000000000) + numerodepontos1 + pibPerCapita1 + (1.0 / densidade1);
    superPoder2 = populacao2 + area2 + (pib2 * 1000000000) + numerodepontos2 + pibPerCapita2 + (1.0 / densidade2);

    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomecidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", numerodepontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomecidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", numerodepontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu\n", populacao1 > populacao2 ? 1 : 2, populacao1 > populacao2);
    printf("Área: Carta %d venceu\n", area1 > area2 ? 1 : 2, area1 > area2);
    printf("PIB: Carta %d venceu\n", pib1 > pib2 ? 1 : 2, pib1 > pib2);
    printf("Pontos Turísticos: Carta %d venceu\n", numerodepontos1 > numerodepontos2 ? 1 : 2, numerodepontos1 > numerodepontos2);
    printf("Densidade Populacional: Carta %d venceu\n", densidade1 < densidade2 ? 1 : 2, densidade1 < densidade2);
    printf("PIB per Capita: Carta %d venceu\n", pibPerCapita1 > pibPerCapita2 ? 1 : 2, pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: Carta %d venceu\n", superPoder1 > superPoder2 ? 1 : 2, superPoder1 > superPoder2);

    return 0;
}

