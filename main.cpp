#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Interpreter.h"
#include "FiguraGeometrica.h"
#include "Sculptor.h"

using namespace std;

int main(void){

    Sculptor *figura; // cria um ponteiro para sculptor
    Interpreter it; // define o objeto
    vector<FiguraGeometrica*> figs; // define o vetor de ponteiros para a classe figura geometrica

    figs = it.analise("orange.txt"); /* it.analise retorna um vetor para a classe figura geometrica,
    então basicamente duplica o vetor*/

    figura = new Sculptor(it.getDX(), it.getDY(), it.getDZ()); // aloca-se um espaço na memoria do tamanho das dimensões necessárias

    for(int i = 0; i< (int) figs.size(); i++){ // percorrer todos os espaços de figs
        figs[i]->draw(*figura); // entao comeca a desenhar tudo o que foi alocado em figs, utilizando o metodo draw
    }

figura->writeOFF("orange.off"); // faz a escrita do arquivo off

    for(int i = 0; i < (int) figs.size(); i++){ //aqui libera a memoria que foi alocada em figs
        delete figs[i];
    }

    delete figura; // liberacao da memoria alocada para figura

    return 0;
}
