#include "Empresa.h"
#include <iostream>
using namespace std;
Empresa::Empresa(string nombre,string fecha, string rubro,string numeroOP){
    this->nombre=nombre;
    this->fecha=fecha;
    this->rubro=rubro;
    this->numeroOP=numeroOP;
    cant = 0;
}

void Empresa::addPasyEmp(Estudiante* nuevo){
    pasantesyempleados.push_back(nuevo);
    cant++;
}

void Empresa::printList(){
    for(int i=0;i<pasantesyempleados.size();i++){
        cout<<i+1<<")"<<pasantesyempleados[i]->getNombre()<<","<<pasantesyempleados[i]->getNumID()<<endl;
    }
}

string Empresa::deletefList(int pos){
    string cosas = pasantesyempleados[pos]->getNombre() + ", " + pasantesyempleados[pos]->getNumID() + ", " + pasantesyempleados[pos]->getEdad()+"\n";
    delete pasantesyempleados[pos];
    return cosas;
}

string Empresa::getName(){
    return nombre;
}

string Empresa::getFecha(){
    return fecha;
}

int Empresa::getCant(){
    return cant;
}

string Empresa::getRubro(){
    return rubro;
}

string Empresa::getNumeroOP(){
    return numeroOP;
}