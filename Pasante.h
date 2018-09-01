#ifndef PASANTE_H
#define PASANTE_H

#include "Estudiante.h"

class Pasante:public Estudiante{
    private:
            string IDpas,duracion;
    public:
            Pasante(string,string,string,string,string,string,string,string,string,string,string);
};

#endif