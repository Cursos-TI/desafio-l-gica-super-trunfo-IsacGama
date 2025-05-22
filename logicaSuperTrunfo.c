#include <stdio.h>
#include <string.h>

// Estrutura pra armazenar os dados da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função pra cadastrar uma carta
void cadastrarCarta(struct Carta *carta, char estado[], char codigo[], char cidade[], int populacao, float area, float pib, int pontosTuristicos) {
    strcpy(carta->estado, estado);
    strcpy(carta->codigo, codigo);
    strcpy(carta->cidade, cidade);
    carta->populacao = populacao;
    carta->area = area;
    carta->pib = pib;
    carta->pontosTuristicos = pontosTuristicos;

    // Calcula a densidade populacional e PIB per capita
    carta->densidadePopulacional = populacao / area;
    carta->pibPerCapita = pib / populacao;
}

// Função para comparar um atributo e mostrar o vencedor
void compararCartas(struct Carta carta1, struct Carta carta2) {
    // Vamos comparar pela População
    printf("Comparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.cidade, carta2.estado, carta2.populacao);

    // Comparação usando if-else
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate! As duas cartas têm a mesma população.\n");
    }
}

int main() {
    struct Carta carta1, carta2;

    // Cadastrando duas cartas fixas
    cadastrarCarta(&carta1, "SP", "C001", "São Paulo", 12300000, 1521.11, 2300000000.00, 25);
    cadastrarCarta(&carta2, "RJ", "C002", "Rio de Janeiro", 6000000, 1182.30, 1600000000.00, 18);

    // Comparar e exibir o resultado
    compararCartas(carta1, carta2);

    return 0;
}