#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <locale.h>

using namespace std;

void limpaTela() {
    system("CLS");
}

void sobreJogo() {
    cout << "Este jogo foi feito por Thiago Rosario Souza no ano de 2023 em C++, criado como forma de divertir os usuários. Divirta-se jogando!\n";
}

void instrucoes() {
    cout << "O jogo é formado por 10 barcos dentre eles 5 barcos pequenos 3 barcos medios e 1 barco grande.\n";
    cout << "O objetivo do jogo consiste em derrubar a frota que está escondida no mapa utilizando o sistemas de linhas e colunas\n";
    cout << "No se foi escolhido pelo o usuario a opcao 'jogar em dupla' vence o jogador com a maior pontuação durante as rodadas";
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]) {
    int linha, coluna;

    // Inicia tabuleiro com água
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10]) {

        cout << "   ";
    for (int i = 0; i < 10; i++) {
        cout << i << " ";
    }
    cout << "\n";

    for (int linha = 0; linha < 10; linha++) {
        // Número da linha
        cout << linha << "  ";
        for (int coluna = 0; coluna < 10; coluna++) {
            cout << mascara[linha][coluna] << " ";
        }
        cout << "\n";

    }
}

void posicionaBarcos(char tabuleiro[10][10]) {
    int barcosP = 5;
    int barcosM = 3;
    int barcosG = 2;

    // Posiciona barcos pequenos
    for (int i = 0; i < barcosP; ++i) {
        int linhabarco, colunabarco;

        do {
            linhabarco = rand() % 10;
            colunabarco = rand() % 10;
        } while (tabuleiro[linhabarco][colunabarco] != 'A');

        tabuleiro[linhabarco][colunabarco] = 'p';
    }

    // Posiciona barcos médios
    for (int i = 0; i < barcosM; ++i) {
        int linhabarco, colunabarco;

        do {
            linhabarco = rand() % 10;
            colunabarco = rand() % 10;
        } while (tabuleiro[linhabarco][colunabarco] != 'A');

        tabuleiro[linhabarco][colunabarco] = 'm';

        // Adiciona mais uma parte do barco médio
        if (colunabarco < 9 && tabuleiro[linhabarco][colunabarco + 1] == 'A') {
            tabuleiro[linhabarco][colunabarco + 1] = 'm';
        }
    }

    // Posiciona barco grande
    for (int i = 0; i < barcosG; ++i) {
        int linhabarco, colunabarco;

        do {
            linhabarco = rand() % 10;
            colunabarco = rand() % 10;
        } while (tabuleiro[linhabarco][colunabarco] != 'A');

        tabuleiro[linhabarco][colunabarco] = 'g';

        // Adiciona mais uma parte do barco grande
        if (linhabarco < 9 && tabuleiro[linhabarco + 1][colunabarco] == 'A') {
            tabuleiro[linhabarco + 1][colunabarco] = 'g';
            }if(linhabarco < 9 && tabuleiro[linhabarco + 1][colunabarco] == 'A') {
            tabuleiro[linhabarco + 1][colunabarco] = 'g';
            }
    }
}

void verificatiro(char tabuleiro[10][10], int linhajogada, int colunajogada, int *pontuacao, string &mensagem) {
    switch (tabuleiro[linhajogada][colunajogada]) {
        case 'p':
            *pontuacao += 10;
            mensagem = "Você acertou um barco pequeno";
            break;
        case 'A':
            mensagem = "Você acertou água";
            break;
        case 'm':
            *pontuacao += 10;
            mensagem = "Você acertou um barco médio";
            break;
        case 'g':
            *pontuacao += 10;
            mensagem = "Você acertou um barco grande";
            break;
    }
}

bool jogoEmAndamento(char mascara[10][10]) {
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            if (mascara[linha][coluna] == '*') {
                return true;  // ainda há partes não descobertas do tabuleiro
            }
        }
    }
    return false;  // todas as partes do tabuleiro foram descobertas
}

void jogaremdupla(){

   char tabuleiro1[10][10], mascara1[10][10];  // tabuleiro e mascara do jogador 1
    char tabuleiro2[10][10], mascara2[10][10];  // tabuleiro e mascara do jogador 2

    // Inicia tabuleiros com água
    iniciaTabuleiro(tabuleiro1, mascara1);
    iniciaTabuleiro(tabuleiro2, mascara2);

    // Posiciona os barcos para ambos os jogadores
    posicionaBarcos(tabuleiro1);
    posicionaBarcos(tabuleiro2);

    int pontuacao1 = 0, pontuacao2 = 0;
    string mensagem;

    while (jogoEmAndamento(mascara1) && jogoEmAndamento(mascara2)) {
        // Lógica do jogo aqui

        // Jogador 1
        limpaTela();
        cout << "Jogador 1:\n";
        exibeTabuleiro(tabuleiro1, mascara1);
        cout << "\n Pontuação Atual: " << pontuacao1;
        cout << "\n" << mensagem;
        cout << "\n";
        cout << "Digite uma linha:\n";
        int linhajogada1, colunajogada1;
        cin >> linhajogada1;
        cout << "Digite uma coluna:\n";
        cin >> colunajogada1;
        verificatiro(tabuleiro1, linhajogada1, colunajogada1, &pontuacao1, mensagem);
        mascara1[linhajogada1][colunajogada1] = tabuleiro1[linhajogada1][colunajogada1];

        if (!jogoEmAndamento(mascara1)) {
            cout << "Jogador 1 ganhou!\n";
            break;
        }

        // Jogador 2
        limpaTela();
        cout << "Jogador 2:\n";
        exibeTabuleiro(tabuleiro2, mascara2);
        cout << "\n Pontuação Atual: " << pontuacao2;
        cout << "\n" << mensagem;
        cout << "\n";
        cout << "Digite uma linha:\n";
        int linhajogada2, colunajogada2;
        cin >> linhajogada2;
        cout << "Digite uma coluna:\n";
        cin >> colunajogada2;
        verificatiro(tabuleiro2, linhajogada2, colunajogada2, &pontuacao2, mensagem);
        mascara2[linhajogada2][colunajogada2] = tabuleiro2[linhajogada2][colunajogada2];

        if (!jogoEmAndamento(mascara2)) {
            cout << "Jogador 2 ganhou!\n";
            break;
        }
    }
}


void jogo() {
    char tabuleiro[10][10], mascara[10][10]; // tabuleiro e mascara do jogo
    int linhajogada, colunajogada;
    int jogoEmAndamento = 1;
    int pontuacao = 0;
    string mensagem;

    // Inicia tabuleiro com água
    iniciaTabuleiro(tabuleiro, mascara);

    // Posiciona os barcos
    posicionaBarcos(tabuleiro);

    while (jogoEmAndamento == 1) {
        // Lógica do jogo aqui
        limpaTela();

        // Exibe o tabuleiro
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\n Pontuação Atual: " << pontuacao;
        cout << "\n" << mensagem;
        cout << "\n";
        cout << "Digite uma linha:\n";
        cin >> linhajogada;
        cout << "Digite uma coluna:\n";
        cin >> colunajogada;

        verificatiro(tabuleiro, linhajogada, colunajogada, &pontuacao, mensagem);
        mascara [linhajogada][colunajogada] = tabuleiro[linhajogada][colunajogada];

        // Lógica para verificar o fim do jogo (por exemplo, quando todos os barcos forem afundados)
        // Implemente isso conforme necessário

    }

}


void menuInicial() {
    // Opção escolhida pelo usuário
    int opcao = 0;

    // Nome do usuário
    string nomeDoJogador;

    // Enquanto o jogador não digita uma opção válida, mostra o menu novamente
    while (opcao < 1 || opcao > 5) {
        limpaTela();
        cout << "Bem-vindo ao batalha naval 2023 by thiago rosario \n";
        cout << "\n 1- Jogar ";
        cout << "\n 2- Jogar Em Dupla";
        cout << "\n 3- Instruções.";
        cout << "\n 4- Sobre ";
        cout << "\n 5- Retorna ao menu do game pad";
        cout << "\n";
        cin >> opcao;

        // Faz algo de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                // Inicia o jogo
                cout << "Digite o nome do usuário: ";
                cin >> nomeDoJogador;
                jogo();
                break;
            case 2:
                // Jogo em dupla
                cout << "Iniciando jogo em dupla";
                jogaremdupla();
                break;
            case 3:
                instrucoes();
                break;
            case 4:
                // Jogo em dupla
                sobreJogo();
                break;
            case 5:
                cout << "Retornando ao menu do gamepad";
                break;
            default:
                cout << "Opção inválida. Tente novamente.";
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");

    srand((unsigned)time(NULL));

    menuInicial();
    return 0;
}
