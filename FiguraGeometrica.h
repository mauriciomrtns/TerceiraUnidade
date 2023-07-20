#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Sculptor.h"

class FiguraGeometrica // superclasse, todas as outras ir o herdar ela
{
    protected:
        float r, g, b, a; // ir  armazenar as cores que est o sendo trabalhadas atualmente
    public:
        FiguraGeometrica(){}
        virtual ~FiguraGeometrica(){}
        virtual void draw(Sculptor &s)=0; // metodo virtual puro, aponta para o metodo draw das outras classes
};

#endif // FIGURAGEOMETRICA_H
