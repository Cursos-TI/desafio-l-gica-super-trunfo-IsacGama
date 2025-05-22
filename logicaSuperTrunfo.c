#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para inicializar a carta
void inicializarCarta(struct Carta *carta, char nome[], int populacao, float area, float pib, int pontosTuristicos) {
    strcpy(carta->nome, nome);
    carta->populacao = populacao;
    carta->area = area;
    carta->pib = pib;
    carta->pontosTuristicos = pontosTuristicos;
    carta->densidadeDemografica = populacao / area;
}

// Função para exibir os dados das cartas
void exibirDados(struct Carta c1, struct Carta c2) {
    printf("\n== CARTAS CARGADAS ==\n");
    printf("Carta 1 - %s\n", c1.nome);
    printf("Carta 2 - %s\n\n", c2.nome);
}

// Função para comparar e mostrar o vencedor
void compararCartas(struct Carta c1, struct Carta c2, int opcao) {
    printf("\n== RESULTADO DA COMPARAÇÃO ==\n");

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", c1.nome, c1.populacao);
            printf("%s: %d habitantes\n", c2.nome, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", c1.nome, c1.area);
            printf("%s: %.2f km²\n", c2.nome, c2.area);
            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", c1.nome, c1.pib);
            printf("%s: %.2f bilhões\n", c2.nome, c2.pib);
            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d locais\n", c1.nome, c1.pontosTuristicos);
            printf("%s: %d locais\n", c2.nome, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.nome, c1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", c2.nome, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Vencedor: %s (menor densidade vence)\n", c1.nome);
            else if (c2.densidadeDemografica < c1.densidadeDemografica)
                printf("Vencedor: %s (menor densidade vence)\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
    }
}

int main() {
    struct Carta pais1, pais2;
    int escolha;

    // Cadastrando duas cartas fixas
    inicializarCarta(&pais1, "Brasil", 211000000, 8515767.00, 14450.00, 50);
    inicializarCarta(&pais2, "Argentina", 45000000, 2780400.00, 540.00, 30);

    exibirDados(pais1, pais2);

    // Menu interativo
    printf("=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &escolha);

    compararCartas(pais1, pais2, escolha);

    return 0;
}