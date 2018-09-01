#include "Microempresa.h"

Microempresa::Microempresa(string pdueno,string pnombre,string pfecha,string prubro,string pnumeroOP):Empresa(pnombre,pfecha,prubro,pnumeroOP){
    dueno=pdueno;
}

string Microempresa::getDueno(){
    return dueno;
}

void Microempresa::setDueno(string pdueno){
    dueno=pdueno;
}
