#include <stdio.h>
#include <string.h>

int main() {
    char estado1[20], estado2[20];
    char nomecidade1[50], nomecidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int numerodepontos1, numerodepontos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    int opcao1, opcao2;

    // Entrada de dados para a primeira cidade
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

    // Entrada de dados para a segunda cidade
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

    // Cálculo dos atributos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    while (1) {
        // Escolha do primeiro atributo
        printf("\nEscolha o primeiro atributo para comparação:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n6 - Número de Pontos Turísticos\n0 - Sair\nOpção: ");
        scanf("%d", &opcao1);

        if (opcao1 == 0) {
            printf("Comparação concluída.\n");
            break;
        }

        // Escolha do segundo atributo (não pode ser igual ao primeiro)
        do {
            printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
            printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n6 - Número de Pontos Turísticos\nOpção: ");
            scanf("%d", &opcao2);

            if (opcao2 == opcao1) {
                printf("Erro: O segundo atributo deve ser diferente do primeiro.\n");
            }
        } while (opcao2 == opcao1);

        // Variáveis para armazenar os valores dos atributos escolhidos
        float valor1_attr1, valor2_attr1, valor1_attr2, valor2_attr2;
        char atributo_nome1[30], atributo_nome2[30];

        // Função para selecionar valores e nomes dos atributos
        void selecionar_atributo(int opcao, float *valor1, float *valor2, char *nome) {
            switch (opcao) {
                case 1: *valor1 = populacao1; *valor2 = populacao2; strcpy(nome, "População"); break;
                case 2: *valor1 = area1; *valor2 = area2; strcpy(nome, "Área"); break;
                case 3: *valor1 = pib1; *valor2 = pib2; strcpy(nome, "PIB"); break;
                case 4: *valor1 = densidade1; *valor2 = densidade2; strcpy(nome, "Densidade Populacional"); break;
                case 5: *valor1 = pibPerCapita1; *valor2 = pibPerCapita2; strcpy(nome, "PIB per Capita"); break;
                case 6: *valor1 = numerodepontos1; *valor2 = numerodepontos2; strcpy(nome, "Número de Pontos Turísticos"); break;
                default: printf("Erro na seleção do atributo.\n"); break;
            }
        }

        // Selecionar os dois atributos
        selecionar_atributo(opcao1, &valor1_attr1, &valor2_attr1, atributo_nome1);
        selecionar_atributo(opcao2, &valor1_attr2, &valor2_attr2, atributo_nome2);

        // Soma dos valores dos atributos
        float soma1 = valor1_attr1 + valor1_attr2;
        float soma2 = valor2_attr1 + valor2_attr2;

        // Exibição dos resultados organizados
        printf("\n==================== RESULTADO ====================\n");
        printf("Cidade 1: %s (%s)\nCidade 2: %s (%s)\n", nomecidade1, estado1, nomecidade2, estado2);
        printf("---------------------------------------------------\n");
        printf("Atributo 1: %s\n- %s: %.2f\n- %s: %.2f\n", atributo_nome1, nomecidade1, valor1_attr1, nomecidade2, valor2_attr1);
        printf("Atributo 2: %s\n- %s: %.2f\n- %s: %.2f\n", atributo_nome2, nomecidade1, valor1_attr2, nomecidade2, valor2_attr2);
        printf("---------------------------------------------------\n");
        printf("Soma dos atributos:\n- %s: %.2f\n- %s: %.2f\n", nomecidade1, soma1, nomecidade2, soma2);
        printf("---------------------------------------------------\n");

        // Verificação de empate final
        if (soma1 == soma2) {
            printf("🚨 EMPATE! 🚨\n");
        } else {
            int cidadeVencedora = (soma1 > soma2) ? 1 : 2;
            char *nomeVencedora = (cidadeVencedora == 1) ? nomecidade1 : nomecidade2;
            printf("🎉 Resultado: A cidade vencedora é %s! 🎉\n", nomeVencedora);
        }
        printf("===================================================\n");
    }

    return 0;
}
