#ifndef GRANDE_H
#define GRANDE_H

#include "Mediana.h"

class Grande:public Mediana{
    private: 
        string vice,proveedores="";
    public:
        Grande(string,string,string,string,string,string,string,string,string,string,string);
        string getVice();
        string getProveedores();
        void addProveedores(string);
};
#endif