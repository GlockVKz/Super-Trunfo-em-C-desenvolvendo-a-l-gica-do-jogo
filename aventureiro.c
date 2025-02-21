#include <string.h>

int main() {
    char estado1[20], estado2[20];
    char nomecidade1[50], nomecidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int numerodepontos1, numerodepontos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    int opcao;
    
    printf("Digite o nome do estado da primeira cidade:\n");
    scanf("%s", estado1);
    printf("Digite o nome da primeira cidade:\n");
    scanf("%s", nomecidade1);
    printf("Digite a população da primeira cidade:\n");
    scanf("%lu", &populacao1);
    printf("Digite a área da primeira cidade (em km²):\n");
    scanf("%f", &area1);
    printf("Digite o PIB da primeira cidade (em bilhões de reais):\n");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos da primeira cidade:\n");
    scanf("%d", &numerodepontos1);
    
    printf("\nDigite o nome do estado da segunda cidade:\n");
    scanf("%s", estado2);
    printf("Digite o nome da segunda cidade:\n");
    scanf("%s", nomecidade2);
    printf("Digite a população da segunda cidade:\n");
    scanf("%lu", &populacao2);
    printf("Digite a área da segunda cidade (em km²):\n");
    scanf("%f", &area2);
    printf("Digite o PIB da segunda cidade (em bilhões de reais):\n");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos da segunda cidade:\n");
    scanf("%d", &numerodepontos2);
    
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    
    while (1) {
        printf("\nEscolha o atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Densidade Populacional\n");
        printf("5 - PIB per Capita\n");
        printf("6 - Número de pontos turísticos\n");
        printf("0 - Sair (Digite 'comparação concluída')\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) {
            printf("Comparação concluída.\n");
            break;
        }
        
        float valor1, valor2;
        char atributo_nome[30];
        int cartaVencedora;
        
        switch (opcao) {
            case 1:
                valor1 = populacao1;
                valor2 = populacao2;
                strcpy(atributo_nome, "População");
                break;
            case 2:
                valor1 = area1;
                valor2 = area2;
                strcpy(atributo_nome, "Área");
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
            case 6:
                valor1 = numerodepontos1;
                valor2 = numerodepontos2;
                strcpy(atributo_nome, "Número de Pontos Turísticos");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }
        
        if (opcao == 4) {
            cartaVencedora = (valor1 < valor2) ? 1 : 2;
        } else {
            cartaVencedora = (valor1 > valor2) ? 1 : 2;
        }
        
        // Exibir resultado
        printf("\n--- Comparação ---\n");
        printf("Atributo Comparado: %s\n", atributo_nome);
        printf("%s (%s): %.2f\n", nomecidade1, estado1, valor1);
        printf("%s (%s): %.2f\n", nomecidade2, estado2, valor2);
        
        if (valor1 == valor2) {
            printf("Resultado: Empate!\n");
        } else {
            printf("Resultado: Carta %d (%s) venceu!\n", cartaVencedora, cartaVencedora == 1 ? nomecidade1 : nomecidade2);
        }
    }
    return 0;
}