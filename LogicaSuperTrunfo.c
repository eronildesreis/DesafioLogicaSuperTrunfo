#include <stdio.h>
#include <string.h>

// Definição da estrutura para uma carta
typedef struct {
    char nome[50];
    int poder;        // Atributo 1
    int velocidade;   // Atributo 2
    int habilidade;   // Atributo 3
} Carta;

// Função para exibir o menu de escolha de atributos
void exibirMenu() {
    printf("\nMenu de Comparação de Cartas - Super Trunfo\n");
    printf("1. Comparar Poder\n");
    printf("2. Comparar Velocidade\n");
    printf("3. Comparar Habilidade\n");
    printf("4. Comparar Múltiplos Atributos (Poder e Velocidade)\n");
    printf("5. Comparar Múltiplos Atributos (Velocidade e Habilidade)\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

// Função para comparar uma carta com a outra usando um único atributo
void compararAtributo(Carta carta1, Carta carta2, int atributo) {
    if (atributo == 1) {
        // Comparação de Poder
        printf("\nComparando o atributo Poder:\n");
        printf("%s (Poder: %d) vs %s (Poder: %d)\n", carta1.nome, carta1.poder, carta2.nome, carta2.poder);
        if (carta1.poder > carta2.poder) {
            printf("%s venceu!\n", carta1.nome);
        } else if (carta1.poder < carta2.poder) {
            printf("%s venceu!\n", carta2.nome);
        } else {
            printf("Empate!\n");
        }
    }
    else if (atributo == 2) {
        // Comparação de Velocidade
        printf("\nComparando o atributo Velocidade:\n");
        printf("%s (Velocidade: %d) vs %s (Velocidade: %d)\n", carta1.nome, carta1.velocidade, carta2.nome, carta2.velocidade);
        if (carta1.velocidade > carta2.velocidade) {
            printf("%s venceu!\n", carta1.nome);
        } else if (carta1.velocidade < carta2.velocidade) {
            printf("%s venceu!\n", carta2.nome);
        } else {
            printf("Empate!\n");
        }
    }
    else if (atributo == 3) {
        // Comparação de Habilidade
        printf("\nComparando o atributo Habilidade:\n");
        printf("%s (Habilidade: %d) vs %s (Habilidade: %d)\n", carta1.nome, carta1.habilidade, carta2.nome, carta2.habilidade);
        if (carta1.habilidade > carta2.habilidade) {
            printf("%s venceu!\n", carta1.nome);
        } else if (carta1.habilidade < carta2.habilidade) {
            printf("%s venceu!\n", carta2.nome);
        } else {
            printf("Empate!\n");
        }
    }
}

// Função para comparar múltiplos atributos (Poder e Velocidade)
void compararMultiploPoderVelocidade(Carta carta1, Carta carta2) {
    printf("\nComparando Poder e Velocidade:\n");
    
    if (carta1.poder > carta2.poder) {
        printf("%s venceu no Poder (Poder: %d vs %d)\n", carta1.nome, carta1.poder, carta2.poder);
    } else if (carta1.poder < carta2.poder) {
        printf("%s venceu no Poder (Poder: %d vs %d)\n", carta2.nome, carta2.poder, carta1.poder);
    } else {
        printf("Empate no Poder\n");
    }
    
    if (carta1.velocidade > carta2.velocidade) {
        printf("%s venceu na Velocidade (Velocidade: %d vs %d)\n", carta1.nome, carta1.velocidade, carta2.velocidade);
    } else if (carta1.velocidade < carta2.velocidade) {
        printf("%s venceu na Velocidade (Velocidade: %d vs %d)\n", carta2.nome, carta2.velocidade, carta1.velocidade);
    } else {
        printf("Empate na Velocidade\n");
    }
}

// Função para comparar múltiplos atributos (Velocidade e Habilidade)
void compararMultiploVelocidadeHabilidade(Carta carta1, Carta carta2) {
    printf("\nComparando Velocidade e Habilidade:\n");

    // Usando o operador ternário para comparar
    printf("%s venceu no atributo Velocidade: %s\n", (carta1.velocidade > carta2.velocidade) ? carta1.nome : carta2.nome,
           (carta1.velocidade > carta2.velocidade) ? "Venceu" : "Perdeu");

    printf("%s venceu no atributo Habilidade: %s\n", (carta1.habilidade > carta2.habilidade) ? carta1.nome : carta2.nome,
           (carta1.habilidade > carta2.habilidade) ? "Venceu" : "Perdeu");
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
                compararAtributo(carta1, carta2, 1); // Comparar Poder
                break;
            case 2:
                compararAtributo(carta1, carta2, 2); // Comparar Velocidade
                break;
            case 3:
                compararAtributo(carta1, carta2, 3); // Comparar Habilidade
                break;
            case 4:
                compararMultiploPoderVelocidade(carta1, carta2); // Comparar Poder e Velocidade
                break;
            case 5:
                compararMultiploVelocidadeHabilidade(carta1, carta2); // Comparar Velocidade e Habilidade
                break;
            case 6:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
