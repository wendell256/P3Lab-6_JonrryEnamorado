#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

class Estudiante:public Persona{
    protected:
            string carrera,universidad,cuenta,indice;
    public:
            Estudiante();
            Estudiante(string,string,string,string,string,string,string,string,string);
            string getCarrera();
            string getUniversidad();
            string getCuenta();
            string getIndice();
};

#endif