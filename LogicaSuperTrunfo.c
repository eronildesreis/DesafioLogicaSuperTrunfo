#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char nome[50];
    int poder;        // Atributo de poder
    int velocidade;   // Atributo de velocidade
    int habilidade;   // Atributo de habilidade
} Carta;

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\nMenu de Comparação de Cartas - Super Trunfo\n");
    printf("1. Comparar Poder\n");
    printf("2. Comparar Velocidade\n");
    printf("3. Comparar Habilidade\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

// Função para comparar duas cartas pelo atributo de poder
void compararPoder(Carta carta1, Carta carta2) {
    printf("\nComparando o atributo de Poder:\n");
    printf("%s (Poder: %d) vs %s (Poder: %d)\n", carta1.nome, carta1.poder, carta2.nome, carta2.poder);
    printf("%s venceu!\n", (carta1.poder > carta2.poder) ? carta1.nome : carta2.nome);
}

// Função para comparar duas cartas pelo atributo de velocidade
void compararVelocidade(Carta carta1, Carta carta2) {
    printf("\nComparando o atributo de Velocidade:\n");
    printf("%s (Velocidade: %d) vs %s (Velocidade: %d)\n", carta1.nome, carta1.velocidade, carta2.nome, carta2.velocidade);
    printf("%s venceu!\n", (carta1.velocidade > carta2.velocidade) ? carta1.nome : carta2.nome);
}

// Função para comparar duas cartas pelo atributo de habilidade
void compararHabilidade(Carta carta1, Carta carta2) {
    printf("\nComparando o atributo de Habilidade:\n");
    printf("%s (Habilidade: %d) vs %s (Habilidade: %d)\n", carta1.nome, carta1.habilidade, carta2.nome, carta2.habilidade);
    printf("%s venceu!\n", (carta1.habilidade > carta2.habilidade) ? carta1.nome : carta2.nome);
}

// Função principal que controla o fluxo do programa
int main() {
    Carta carta1, carta2;
    int opcao;

    // Entrada dos dados das cartas
    printf("Digite o nome da primeira carta: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = 0;  // Remove o caractere '\n'

    printf("Digite o poder da primeira carta: ");
    scanf("%d", &carta1.poder);

    printf("Digite a velocidade da primeira carta: ");
    scanf("%d", &carta1.velocidade);

    printf("Digite a habilidade da primeira carta: ");
    scanf("%d", &carta1.habilidade);

    getchar(); // Limpar o buffer do teclado após o scanf

    printf("\nDigite o nome da segunda carta: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = 0;  // Remove o caractere '\n'

    printf("Digite o poder da segunda carta: ");
    scanf("%d", &carta2.poder);

    printf("Digite a velocidade da segunda carta: ");
    scanf("%d", &carta2.velocidade);

    printf("Digite a habilidade da segunda carta: ");
    scanf("%d", &carta2.habilidade);

    // Menu interativo
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                compararPoder(carta1, carta2);
                break;
            case 2:
                compararVelocidade(carta1, carta2);
                break;
            case 3:
                compararHabilidade(carta1, carta2);
                break;
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
