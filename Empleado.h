#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Estudiante.h"

class Empleado:public Estudiante{
    private: 
            string empleadoID,salario;
    public:
            Empleado(string,string,string,string,string,string,string,string,string,string,string);
            string getEmpleadoID();
            void setEmpleadoID(string);
            string getSalario();
            void setSalario(string);
};

#endif