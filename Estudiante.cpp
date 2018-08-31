#include "Estudiante.h"

Estudiante::Estudiante(string pcarrera,string puniversidad,string pcuenta,string pindice,string pnombre,string pnumeroID,string pedad,string psexo,string pnacionalidad){
    carrera=pcarrera;
    universidad=puniversidad;
    cuenta=pcuenta;
    indice=pindice;

    this->nombre=pnombre;
    this->numeroID=pnumeroID;
    this->edad=pedad;
    this->sexo=psexo;
    this->nacionalidad=pnacionalidad;
}

string Estudiante::getCarrera(){
    return carrera;
}

string Estudiante::getUniversidad(){
    return universidad;
}

string Estudiante::getCuenta(){
    return cuenta;
}

string Estudiante::getIndice(){
    return indice;
}