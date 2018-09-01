#include "Grande.h"

Grande::Grande(string pvice,string pproveedor,string pingresos,string egresos,string departamento,string RTN,string pdueno,string pnombre, string pfecha, string prubro, string pnumeroOP):Mediana(pingresos,egresos,departamento,RTN,pdueno,pnombre,pfecha,prubro,pnumeroOP){

}

string Grande::getVice(){
    return vice;
}

string Grande::getProveedores(){
    return proveedores;
}

void Grande::addProveedores(string nuevo){
    proveedores+=nuevo+"\n";
}