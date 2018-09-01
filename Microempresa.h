#ifndef MICROEMPRESA_H
#define MICROEMPRESA_H

#include "Empresa.h"

class Microempresa:public Empresa{
    protected:
        string dueno;
    public:
        Microempresa(string,string,string,string,string);
        string getDueno();
        void setDueno(string);

};
#endif