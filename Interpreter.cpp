#include "Interpreter.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "CutBox.h"
#include "CutBox.cpp"
#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"
#include "Sculptor.h"


using namespace std;

Interpreter::Interpreter()
{
    //ctor
}

vector<FiguraGeometrica *> Interpreter::analise(string filename){
    ifstream orange; // o arquivo a ser aberto
    stringstream ss; // cria uma stream
    string s, token; // cria duas strings
    vector<FiguraGeometrica *> figs; // cria um vetor de figuras geometricas chamado figs

    orange.open(filename.c_str()); // abrir o arquivo

    if (!orange.is_open()){ // verifica se houve errro na abertura do arquivo, se n o estiver aberto ele notifica e encerra o processo
        cout << "Erro ao abrir o arquivo\n";
        exit(0);
    }

    cout << "Arquivo aberto!\n";

    while(orange.good()){ // o la o se mantem enquanto o arquvo nao apresenta erro
        getline(orange, s);// pegar a linha do arquivo e associar a s
        if(orange.good()){ // caso o arquivo nao apresente erro
            ss.clear(); // limpar a stream ss
            ss.str(s); // associar  o valor de s em ss
            ss >> token; //  associa token a ss

            if(ss.good()){ // se tiver tudo bem com a stream, ele entra no if
                // onde inicia a verificao dos tokens, que sao as chamadas de construcao do desenho
                if(token.compare("dim") == 0){
                    ss >> dx >> dy >> dz;
                }


                else if(token.compare("putvoxel") == 0){
                    cout << "putvoxel\n";
                    int x_, y_, z_;
                    ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x_, y_, z_, r, g, b, a));
                }

                else if(token.compare("cutvoxel") == 0){
                    cout << "cutvoxel\n";
                    int x_, y_, z_;
                    ss >> x_ >> y_ >> z_;
                    figs.push_back(new CutVoxel(x_, y_, z_));
                }

                else if(token.compare("putbox") == 0){
                    cout << "putbox\n";
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }

                else if(token.compare("cutbox") == 0){
                    cout << "cutbox\n";
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }

                else if(token.compare("putellipsoid") == 0){
                    cout << "putellipsoid\n";
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
                }

                else if(token.compare("cutellipsoid") == 0){
                    cout << "cutellipsoid\n";
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xc, yc, zc, rx, ry, rz));
                }

                else if(token.compare("putsphere") == 0){
                    cout << "putsphere\n";
                    int xc, yc, zc, raio;
                    ss >> xc >> yc >> zc >> raio >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(xc, yc, zc, raio, r, g, b, a));
                }

                else if(token.compare("cutsphere") == 0){
                    cout << "cutsphere\n";
                    int xc, yc, zc, raio;
                    ss >> xc >> yc >> zc >> raio;
                    figs.push_back(new CutSphere(xc, yc, zc, raio));
                }

                else{
                    orange.close();
                    cout << "\n token " << token << " nao deDKido\n";
                    exit(1);
                }
            }
        }
    }

    orange.close(); // fecha o arquivo
    return figs;
}

int Interpreter::getDX(){
    return dx;
}

int Interpreter::getDY(){
    return dy;
}

int Interpreter::getDZ(){
    return dz;
}
