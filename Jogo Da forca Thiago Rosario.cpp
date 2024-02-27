#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <locale.h>

using namespace std;

string retornapalavraaleatoriafruta() {
    // Vetor com palavras disponíveis - Frutas
    string palavras[5] = {"AMORA", "LARANJA", "CUPUAÇU", "MORANGO", "CEREJA"};
    int indicealeatorio = rand() % 5;
    return palavras[indicealeatorio];
}

string retornapalavraaleatoriamedico() {
    // Vetor com palavras disponíveis - Médicos
    string medico[5] = {"NUTRICIONISTA", "CLINICO", "CARDIOLOGISTA", "ORTOPEDISTA", "VETERINARIO"};
    int inidicemedico = rand() % 5;
    return medico[inidicemedico];
}

string retornapalavraaleatoriaanimal() {
    // Vetor com palavras disponíveis - Animais Mamíferos
    string animal[5] = {"CACHORRO", "OVELHA", "JAGUATIRICA", "MORCEGO", "CAMELO"};
    int indiceanimal = rand() % 5;
    return animal[indiceanimal];
}

string retornaplavracommascara(string palavraSecreta, int tamanhoDaPalavra) {
    return string(tamanhoDaPalavra, '_');
}

void limpatela() {
    system("CLS");
}

void exibestatus(string palavraSecreta, string palavracommascara, int tamanhoDaPalavra, int tentativasrestantes, string letraserradas, string mensagem) {
    // Dica com base na categoria da palavra - alteração aqui
    if (palavraSecreta == retornapalavraaleatoriaanimal()) {
        cout << "\nDica: Animal Mamifero";
    } else if (palavraSecreta == retornapalavraaleatoriamedico()) {
        cout << "\nDica: Médico \n";
    } else if (palavraSecreta == retornapalavraaleatoriafruta()) {
        cout << "\nDica: Fruta \n";
    }

    cout << mensagem;
    cout << "\n A palavra: " << palavracommascara << " (tamanho: " << tamanhoDaPalavra << ")";
    cout << "\n Tentativas restantes: " << tentativasrestantes;
}

int jogarsozinho() {
    srand(static_cast<unsigned int>(time(0)));

    string respostas[3] = {retornapalavraaleatoriaanimal(), retornapalavraaleatoriamedico(), retornapalavraaleatoriafruta()};
    int indiceResposta = rand() % 3;
    string palavraSecreta = respostas[indiceResposta];
    int tamanhoDaPalavra = palavraSecreta.size();
    string palavracommascara = retornaplavracommascara(palavraSecreta, tamanhoDaPalavra);

    int tentativas = 0;
    int maximodetentativas = 15;
    char letra;
    int opcao;
    string letraserradas;
    string mensagem;
    string palavrainteira;

    while (palavraSecreta != palavracommascara && maximodetentativas - tentativas > 0) {
        exibestatus(palavraSecreta, palavracommascara, tamanhoDaPalavra, maximodetentativas - tentativas, letraserradas, mensagem);
        tentativas++;

        cout << "\n Digite 1 para acertar a palavra\n";
        cout << "\n Digite uma letra: ";
        cin >> letra;

        if (letra == '1') {
            cin >> palavrainteira;
            limpatela();

            if (palavrainteira == palavraSecreta) {
                cout << "Parabéns Você venceu !!!!";
                palavracommascara = palavraSecreta;
            } else {
                tentativas = maximodetentativas;
            }
        } else {
            // Verifica se a letra já foi digitada
            bool letraRepetida = false;
            for (char letraErrada : letraserradas) {
                if (letraErrada == letra) {
                    letraRepetida = true;
                    break;
                }
            }

            if (letraRepetida) {
                mensagem = "Letra Já Digitada";
            }
                // Verifica se a letra está na palavra
                bool acertou = false;
                for (int cont = 0; cont < tamanhoDaPalavra; cont++) {
                    if (palavraSecreta[cont] == letra) {
                        palavracommascara[cont] = letra;
                        acertou = true;
                    }
                }

                if (acertou) {
                    limpatela();
                    cout << "Você acertou uma letra!";
                } else {
                    limpatela();
                    letraserradas += letra;
                    cout << "\n Letra incorreta !!:";
                }

                cout << "\nLetras arriscadas:" << letra << letraserradas;
            }
        }


     // Verificar se o jogador venceu ou perdeu
        if (palavraSecreta == palavracommascara) {
            limpatela();
            cout << "Parabens, Você Venceu !!!\n";
            cout << "\n Para jogar novamente digite - 1\n";
            cout << "Para sair do jogo digite -2\n";
            cin >> opcao;
            return opcao;
        } else {
            limpatela();
            cout << "\n Você perdeu !, Game over";
            cout << "\n Para jogar novamente digite - 1\n";
            cout << "Para sair do jogo digite -2\n";
            cin >> opcao;
            return opcao;
        }
}




int jogardupla() {
    srand(static_cast<unsigned int>(time(0)));

    int jogadorAtual = 1;

    string respostas[3] = { retornapalavraaleatoriaanimal(), retornapalavraaleatoriamedico(), retornapalavraaleatoriafruta() };
    int indiceResposta = rand() % 3;
    string palavraSecreta = respostas[indiceResposta];
    int tamanhoDaPalavra = palavraSecreta.size();
    string palavracommascara = retornaplavracommascara(palavraSecreta, tamanhoDaPalavra);

    int tentativas = 0;
    int maximodetentativas = 15;
    char letra;
    int opcao;
    string letraserradas;
    string mensagem;
    string palavrainteira;

    while (palavraSecreta != palavracommascara && maximodetentativas - tentativas > 0) {
        exibestatus(palavraSecreta, palavracommascara, tamanhoDaPalavra, maximodetentativas - tentativas, letraserradas, mensagem);
        tentativas++;

        cout << "\nJogador " << jogadorAtual << ", digite 1 para acertar a palavra\n";
        cout << "Jogador " << jogadorAtual << ", digite uma letra: ";
        cin >> letra;

        if (letra == '1') {
            cin >> palavrainteira;

            if (palavrainteira == palavraSecreta) {
                cout << "Parabéns Jogador " << jogadorAtual << " venceu!!!";
                palavracommascara = palavraSecreta;
            } else {
                tentativas = maximodetentativas;
            }
        } else {
            // Verifica se a letra já foi digitada
            bool letraRepetida = false;
            for (char letraErrada : letraserradas) {
                if (letraErrada == letra) {
                    letraRepetida = true;
                    break;
                }
            }

            if (letraRepetida) {
                mensagem = "Letra Já Digitada";
            } else {
                // Verifica se a letra está na palavra
                bool acertou = false;
                for (int cont = 0; cont < tamanhoDaPalavra; cont++) {
                    if (palavraSecreta[cont] == letra) {
                        palavracommascara[cont] = letra;
                        acertou = true;
                    }
                }

                if (acertou) {
                    limpatela();
                    cout << "Você acertou uma letra!";
                } else {
                    limpatela();
                    letraserradas += letra;
                    cout << "\nLetra incorreta!!";
                }

                cout << "\nLetras arriscadas: " << letraserradas;
            }
        }

        // Verificar se o jogador venceu ou perdeu
        // Após o loop while em jogardupla()

if (palavraSecreta == palavracommascara) {
    limpatela();
    cout << "Parabens, Jogador " << jogadorAtual << " Venceu !!!\n";
    cout << "Para jogar novamente digite - 1\n";
    cout << "Para sair do jogo digite - 2\n";
    cin >> opcao;
    return opcao;
} else if (maximodetentativas - tentativas <= 0) {
    limpatela();
    cout << "\nOs dois jogadores perderam, Game over";
    cout << "\nPara jogar novamente digite - 1\n";
    cout << "Para sair do jogo digite - 2\n";
    cin >> opcao;
    return opcao;
}

// Troca o jogador para a próxima rodada
jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
limpatela();
        }

        // Troca o jogador para a próxima rodada
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
        limpatela();
    }




void sobrejogo (){

cout << "Este jogo foi feito por thiago rosario souza no ano de 2023 em C++, Criado como forma de divertir os usuarios e que se divirtam jogando.";


}


void menuinicial(){
 int opcao = 0;

    while(opcao , 1 || opcao >4){



    cout << "bem vindo ao jogo da forca \n";
    cout << "\n 1- Jogar ";
    cout << "\n 2- Jogar Em Dupla";
    cout << "\n 3- Sobre ";
    cout << "\n 4- Retorna ao menu do game pad";
    cout << "\n";
    cin >> opcao;

    switch (opcao) {
        case 1:

            limpatela ();

        cout << " \n jogo iniciado";

        if (jogarsozinho() == 1){
            menuinicial();
        }

        break;

        case 2:
         cout << "\n Jogo em dupla iniciado";

         limpatela ();

         if (jogardupla() == 1){
            menuinicial();


        break ;

        case 3:
         cout << "Informações do jogo :";
         sobrejogo();

        break ;

        case 4:
               cout << "Retornando ao menu do gamepad";
        break;

    }



    }

 // pausando o algoritmo
 system ("pause");


}
}

//função prinicpal do programa

int main (){
    setlocale (LC_ALL,"");

    srand ( (unsigned)time (NULL));

    menuinicial();


 srand(static_cast<unsigned int>(time(0)));




    return 0;
}
