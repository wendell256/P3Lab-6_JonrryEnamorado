#include "Mediana.h"

Mediana::Mediana(string pingresos,string egresos,string departamento,string RTN,string pdueno,string pnombre, string pfecha, string prubro, string pnumeroOP):Microempresa(pdueno,pnombre,pfecha,prubro,pnumeroOP){

}

string Mediana::getIngresos(){
    return ingresos;
}

string Mediana::getEgresos(){
    return egresos;
}

string Mediana::getDepartamento(){
    return departamento;
}

string Mediana::getRTN(){
    return RTN;
}
