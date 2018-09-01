#include "Empleado.h"

Empleado::Empleado(string empleadoID,string salario,string pcarrera,string puniversidad,string pcuenta,string pindice,string pnombre,string pnumeroID,string pedad,string psexo,string pnacionalidad):Estudiante(pcarrera,puniversidad,pcuenta,pindice,pnombre,pnumeroID,pedad,psexo,pnacionalidad){
    this->empleadoID=empleadoID;
    this->salario=salario;
}

string Empleado::getEmpleadoID(){
    return empleadoID;
}

void Empleado::setEmpleadoID(string pempleadoID){
    empleadoID=pempleadoID;
}

string Empleado::getSalario(){
    return salario;
}

void Empleado::setSalario(string psalario){
    salario=psalario;
}