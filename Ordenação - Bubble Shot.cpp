#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10
 using namespace std;

 void imprime_vetor(int vetor[TAM]){

    //Auxiliar contador
    int cont;

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }

}

//função prinicpal do programa

int main (){
    setlocale (LC_ALL,"");

    int vetor [TAM] = {10,9,8,7,6,5,4,3,2,1};
    int x,y,aux;
    for (x=0;x < TAM; x++){
        for (y = x + 1; y < TAM; y++){

          // verificando se precisa fazer a troca

          imprime_vetor(vetor);

           if (vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor [y] = aux;
            }
        }
    }

    imprime_vetor(vetor);




 return 0;
}
