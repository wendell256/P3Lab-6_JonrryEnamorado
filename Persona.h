#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;
class Persona{
    protected:
            string nombre, numeroID,edad,sexo,nacionalidad;
    public:
            Persona();
            Persona(string,string,string,string,string);
            string getNombre();
            string getNumID();
            string getEdad();
            string getSexo();
            string getNacionalidad();

};

#endif