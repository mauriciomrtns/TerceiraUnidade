//Classe que imprime uma elipse
#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "Sculptor.h"
#include "FiguraGeometrica.h"


class PutEllipsoid : public FiguraGeometrica
{
    private:
        int xcenter,ycenter,zcenter,rx,ry,rz;
 		float r,g,b,a;

    public:
		PutEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz,float r,float g,float b,float a);
		void draw(Sculptor &s);

};

#endif // PUTELLIPSOID_H
