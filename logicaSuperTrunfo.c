#include <stdio.h>

int main() {
    // Variáveis da carta 01
    char estado01[3], codigo01[10], nomedacidade01[50];
    int populacao01, pontosturisticos01;
    float area01, pib01, densidade01, pibpercapita01;

    // Variáveis da carta 02
    char estado02[3], codigo02[10], nomedacidade02[50];
    int populacao02, pontosturisticos02;
    float area02, pib02, densidade02, pibpercapita02;

    // --- Cadastro das cartas ---
    printf("Cadastro da carta 01\n");
    printf("Estado (ex: SP): ");
    scanf("%s", estado01);
    printf("Código (ex: A01): ");
    scanf("%s", codigo01);
    printf("Nome do país/cidade: ");
    scanf(" %[^\n]", nomedacidade01);
    printf("População: ");
    scanf("%d", &populacao01);
    printf("Área (km²): ");
    scanf("%f", &area01);
    printf("PIB (bilhões R$): ");
    scanf("%f", &pib01);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosturisticos01);
    densidade01 = (area01 != 0) ? (populacao01 / area01) : 0;
    pibpercapita01 = (pib01 * 1e9) / populacao01;

    printf("\nCadastro da carta 02\n");
    printf("Estado (ex: RJ): ");
    scanf("%s", estado02);
    printf("Código (ex: A02): ");
    scanf("%s", codigo02);
    printf("Nome do país/cidade: ");
    scanf(" %[^\n]", nomedacidade02);
    printf("População: ");
    scanf("%d", &populacao02);
    printf("Área (km²): ");
    scanf("%f", &area02);
    printf("PIB (bilhões R$): ");
    scanf("%f", &pib02);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosturisticos02);
    densidade02 = (area02 != 0) ? (populacao02 / area02) : 0;
    pibpercapita02 = (pib02 * 1e9) / populacao02;

    // --- Menu interativo: Escolha de atributos ---
    int atributo1, atributo2;
    float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2;
    float soma1, soma2;

    // Mostrar menu de atributos
    printf("\n--- MENU DE ATRIBUTOS ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica (MENOR vence)\n");
    printf("6. PIB per capita\n");

    // Escolher primeiro atributo
    printf("\nEscolha o 1º atributo para comparar (1-6): ");
    scanf("%d", &atributo1);

    // Validação do primeiro atributo
    if (atributo1 < 1 || atributo1 > 6) {
        printf("Atributo inválido! Encerrando programa.\n");
        return 1;
    }

    // Escolher segundo atributo, com menu dinâmico
    printf("\n--- MENU DE ATRIBUTOS (2ª ESCOLHA) ---\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1. População\n"); break;
                case 2: printf("2. Área\n"); break;
                case 3: printf("3. PIB\n"); break;
                case 4: printf("4. Pontos Turísticos\n"); break;
                case 5: printf("5. Densidade Demográfica\n"); break;
                case 6: printf("6. PIB per capita\n"); break;
            }
        }
    }

    printf("\nEscolha o 2º atributo para comparar (diferente do primeiro): ");
    scanf("%d", &atributo2);

    // Validação do segundo atributo
    if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
        printf("Atributo inválido ou repetido! Encerrando programa.\n");
        return 1;
    }

    // --- Função de seleção dos valores com switch + ternário ---
    float getValor(int atributo, int carta) {
        switch (atributo) {
            case 1: return carta == 1 ? populacao01 : populacao02;
            case 2: return carta == 1 ? area01 : area02;
            case 3: return carta == 1 ? pib01 : pib02;
            case 4: return carta == 1 ? pontosturisticos01 : pontosturisticos02;
            case 5: return carta == 1 ? densidade01 : densidade02;
            case 6: return carta == 1 ? pibpercapita01 : pibpercapita02;
            default: return 0;
        }
    }

    // Obter os valores dos dois atributos
    valor1_carta1 = getValor(atributo1, 1);
    valor1_carta2 = getValor(atributo1, 2);
    valor2_carta1 = getValor(atributo2, 1);
    valor2_carta2 = getValor(atributo2, 2);

    // Mostrar resultados parciais
    printf("\nComparação dos atributos:\n");
    printf("%s:\n", nomedacidade01);
    printf("Atributo 1: %.2f\n", valor1_carta1);
    printf("Atributo 2: %.2f\n", valor2_carta1);

    printf("\n%s:\n", nomedacidade02);
    printf("Atributo 1: %.2f\n", valor1_carta2);
    printf("Atributo 2: %.2f\n", valor2_carta2);

    // Comparar cada atributo individualmente com regras
    float resultado1 = (atributo1 == 5) ? ((valor1_carta1 < valor1_carta2) ? 1 : (valor1_carta1 > valor1_carta2) ? -1 : 0)
                                        : ((valor1_carta1 > valor1_carta2) ? 1 : (valor1_carta1 < valor1_carta2) ? -1 : 0);

    float resultado2 = (atributo2 == 5) ? ((valor2_carta1 < valor2_carta2) ? 1 : (valor2_carta1 > valor2_carta2) ? -1 : 0)
                                        : ((valor2_carta1 > valor2_carta2) ? 1 : (valor2_carta1 < valor2_carta2) ? -1 : 0);

    // Soma total dos atributos
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nomedacidade01, soma1);
    printf("%s: %.2f\n", nomedacidade02, soma2);

    // Resultado final
    printf("\nResultado final:\n");
    if (soma1 > soma2) {
        printf("%s venceu a rodada!\n", nomedacidade01);
    } else if (soma2 > soma1) {
        printf("%s venceu a rodada!\n", nomedacidade02);
    } else {
        printf("Empate!\n");
    }

    return 0;
}