#include "Persona.h"

Persona::Persona(string pnombre,string pnumeroID,string pedad, string psexo, string pnacionalidad){
    nombre=pnombre;
    pnumeroID=numeroID;
    edad=pedad;
    sexo=psexo;
    nacionalidad=pnacionalidad;

}

string Persona::getEdad(){
    return edad;
}

string Persona::getNacionalidad(){
    return nacionalidad;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getNumID(){
    return numeroID;
}

string Persona::getSexo(){
    return sexo;
}
