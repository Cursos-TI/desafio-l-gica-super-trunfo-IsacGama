#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

// Função pra inicializar carta
void inicializarCarta(struct Carta *carta, char nome[], int populacao, float area, float pib, int pontosTuristicos) {
    strcpy(carta->nome, nome);
    carta->populacao = populacao;
    carta->area = area;
    carta->pib = pib;
    carta->pontosTuristicos = pontosTuristicos;
    carta->densidade = populacao / area;
}

// Função para exibir o menu
void exibirMenu(int escolhido) {
    printf("\nEscolha um atributo para comparar:\n");
    if (escolhido != 1) printf("1 - População\n");
    if (escolhido != 2) printf("2 - Área\n");
    if (escolhido != 3) printf("3 - PIB\n");
    if (escolhido != 4) printf("4 - Pontos Turísticos\n");
    if (escolhido != 5) printf("5 - Densidade Demográfica\n");
    printf("Sua escolha: ");
}

// Função para pegar valor do atributo
float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        default: return -1;
    }
}

// Nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função principal
int main() {
    struct Carta pais1, pais2;
    int atr1, atr2;
    float valor1_1, valor1_2, valor2_1, valor2_2, soma1, soma2;

    // Cartas fixas
    inicializarCarta(&pais1, "Brasil", 211000000, 8515767.00, 14450.00, 50);
    inicializarCarta(&pais2, "Argentina", 45000000, 2780400.00, 540.00, 30);

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        scanf("%d", &atr1);
        if (atr1 < 1 || atr1 > 5)
            printf("Opção inválida. Tente novamente.\n");
    } while (atr1 < 1 || atr1 > 5);

    // Escolha do segundo atributo (sem repetir)
    do {
        exibirMenu(atr1);
        scanf("%d", &atr2);
        if (atr2 < 1 || atr2 > 5 || atr2 == atr1)
            printf("Opção inválida ou repetida. Escolha diferente da anterior.\n");
    } while (atr2 < 1 || atr2 > 5 || atr2 == atr1);

    // Coleta dos valores
    valor1_1 = obterValor(pais1, atr1);
    valor2_1 = obterValor(pais2, atr1);
    valor1_2 = obterValor(pais1, atr2);
    valor2_2 = obterValor(pais2, atr2);

    // Exibição dos valores
    printf("\n== COMPARAÇÃO ENTRE CARTAS ==\n");
    printf("Carta 1: %s\n", pais1.nome);
    printf("Carta 2: %s\n", pais2.nome);
    printf("\nAtributo 1: %s\n", nomeAtributo(atr1));
    printf("%s: %.2f | %s: %.2f\n", pais1.nome, valor1_1, pais2.nome, valor2_1);
    printf("Resultado: %s venceu o atributo 1\n", 
           (atr1 == 5 ? (valor1_1 < valor2_1 ? pais1.nome : (valor2_1 < valor1_1 ? pais2.nome : "Empate")) :
                        (valor1_1 > valor2_1 ? pais1.nome : (valor2_1 > valor1_1 ? pais2.nome : "Empate"))));

    printf("\nAtributo 2: %s\n", nomeAtributo(atr2));
    printf("%s: %.2f | %s: %.2f\n", pais1.nome, valor1_2, pais2.nome, valor2_2);
    printf("Resultado: %s venceu o atributo 2\n", 
           (atr2 == 5 ? (valor1_2 < valor2_2 ? pais1.nome : (valor2_2 < valor1_2 ? pais2.nome : "Empate")) :
                        (valor1_2 > valor2_2 ? pais1.nome : (valor2_2 > valor1_2 ? pais2.nome : "Empate"))));

    // Soma dos atributos
    // Regra: densidade vence pelo menor, então invertemos o sinal pra somar "invertido"
    valor1_1 = (atr1 == 5) ? -valor1_1 : valor1_1;
    valor2_1 = (atr1 == 5) ? -valor2_1 : valor2_1;
    valor1_2 = (atr2 == 5) ? -valor1_2 : valor1_2;
    valor2_2 = (atr2 == 5) ? -valor2_2 : valor2_2;

    soma1 = valor1_1 + valor1_2;
    soma2 = valor2_1 + valor2_2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", pais1.nome, soma1);
    printf("%s: %.2f\n", pais2.nome, soma2);

    printf("\n== RESULTADO FINAL ==\n");
    if (soma1 > soma2)
        printf("Vencedor: %s\n", pais1.nome);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", pais2.nome);
    else
        printf("Empate!\n");

    return 0;
}