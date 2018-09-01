#ifndef MEDIANA_H
#define MEDIANA_H

#include "Microempresa.h"

class Mediana:public Microempresa{
    protected:
        string ingresos,egresos,departamento,RTN;
    public:
        Mediana(string,string,string,string,string,string,string,string,string);
        void setIngresos(string);
        void setEgresos(string);
        void setDepartamento(string);
        void setRTN(string);
        string getIngresos();
        string getEgresos();
        string getDepartamento();
        string getRTN();
};
#endif