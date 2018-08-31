#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Estudiante.h"

class Empleado:Estudiante{
    private: 
            string empleadoID,salario;
    public:
            string getEmpleadoID();
            void setEmpleadoID();
            string getSalario();
            void setSalario();
};

#endif