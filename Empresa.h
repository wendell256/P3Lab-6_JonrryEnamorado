#ifndef EMPRESA_H
#define EMPRESA_H

#include "Empleado.h"
#include "Pasante.h"
#include <vector>

using namespace std;

class Empresa{
    protected:
            string nombre,fecha,rubro,numeroOP;
            int cant;
            vector<Estudiante*> pasantesyempleados;
            
    public:
            Empresa(string,string,string,string);
            void addPasyEmp(Estudiante*);
            void printList();
            string deletefList(int pos);
            string getName();
            string getFecha();
            string getRubro();
            string getNumeroOP();
            int getCant();

            
};

#endif