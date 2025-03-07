#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definir uma estrutura para uma carta
typedef struct {
    char nome[50];      // Nome da carta (exemplo: "Fusca", "Avião", "Cavalo")
    int poder;          // Atributo para comparação (exemplo: poder do carro)
    int velocidade;     // Outro atributo para comparação (exemplo: velocidade)
    int tamanho;        // Outro atributo para comparação (exemplo: tamanho do carro)
} Carta;

// Função para criar uma carta
Carta criarCarta(char nome[], int poder, int velocidade, int tamanho) {
    Carta carta;
    strcpy(carta.nome, nome);
    carta.poder = poder;
    carta.velocidade = velocidade;
    carta.tamanho = tamanho;
    return carta;
}

// Função para exibir uma carta
void exibirCarta(Carta carta) {
    printf("\nCarta: %s\n", carta.nome);
    printf("Poder: %d\n", carta.poder);
    printf("Velocidade: %d\n", carta.velocidade);
    printf("Tamanho: %d\n", carta.tamanho);
}

// Função para comparar duas cartas com base no atributo escolhido
int compararCartas(Carta carta1, Carta carta2, int atributo) {
    // Atributo 1: Poder, Atributo 2: Velocidade, Atributo 3: Tamanho
    int valor1 = 0, valor2 = 0;
    
    switch (atributo) {
        case 1:
            valor1 = carta1.poder;
            valor2 = carta2.poder;
            break;
        case 2:
            valor1 = carta1.velocidade;
            valor2 = carta2.velocidade;
            break;
        case 3:
            valor1 = carta1.tamanho;
            valor2 = carta2.tamanho;
            break;
        default:
            printf("Atributo inválido!\n");
            return 0;
    }
    
    if (valor1 > valor2) {
        return 1; // carta1 vence
    } else if (valor1 < valor2) {
        return 2; // carta2 vence
    } else {
        return 0; // empate
    }
}

// Função para escolher o atributo para a comparação
int escolherAtributo() {
    int atributo;
    printf("\nEscolha o atributo para a comparação:\n");
    printf("1. Poder\n");
    printf("2. Velocidade\n");
    printf("3. Tamanho\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);
    return atributo;
}

int main() {
    // Inicialização das cartas (Exemplo de cartas, pode ser expandido)
    Carta carta1 = criarCarta("Fusca", 50, 120, 3);
    Carta carta2 = criarCarta("Avião", 200, 900, 40);
    Carta carta3 = criarCarta("Cavalo", 30, 60, 2);
    
    Carta deck[3] = {carta1, carta2, carta3};
    
    // Embaralhamento das cartas (apenas simulado com o índice)
    srand(time(0));
    int indiceJogador1 = rand() % 3;
    int indiceJogador2;
    do {
        indiceJogador2 = rand() % 3;
    } while (indiceJogador1 == indiceJogador2);
    
    // Exibindo as cartas dos jogadores
    printf("\nCartas dos jogadores:\n");
    printf("Jogador 1: ");
    exibirCarta(deck[indiceJogador1]);
    printf("Jogador 2: ");
    exibirCarta(deck[indiceJogador2]);
    
    // Escolhendo o atributo para a comparação
    int atributo = escolherAtributo();
    
    // Comparando as cartas
    int resultado = compararCartas(deck[indiceJogador1], deck[indiceJogador2], atributo);
    
    // Exibindo o resultado da comparação
    if (resultado == 1) {
        printf("\nJogador 1 venceu a rodada!\n");
    } else if (resultado == 2) {
        printf("\nJogador 2 venceu a rodada!\n");
    } else {
        printf("\nEmpate na rodada!\n");
    }
    
    return 0;
}