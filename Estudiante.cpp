#include "Estudiante.h"

Estudiante::Estudiante(string pcarrera,string puniversidad,string pcuenta,string pindice,string pnombre,string pnumeroID,string pedad,string psexo,string pnacionalidad):Persona(pnombre,pnumeroID,pedad,psexo,pnacionalidad){
    carrera=pcarrera;
    universidad=puniversidad;
    cuenta=pcuenta;
    indice=pindice;
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