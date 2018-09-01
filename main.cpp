#include <iostream>
#include <string>
#include <vector>
#include "Estudiante.h"
#include "Persona.h"
#include "Empleado.h"
#include "Pasante.h"
#include "Empresa.h"
#include "Microempresa.h"
#include "Mediana.h"
#include "Grande.h"

using namespace std;

void CrearMicro();
void CrearRecluta();
void AggRecluta();
void AggProveedor();
void EliminarEmpleado();
void PrintMicro();
void PrintMed();
void PrintGrand();



vector<Estudiante*> reclutas;
vector<Microempresa*> micros;
vector<Mediana*> medianas;
vector<Grande*> grandes;
vector<string> carreras;
vector<string> eliminados; 
int main(){
    int opc;
    char resp='y';
    while(resp=='y' || resp=='Y'){
        cout<<"***ADMINISTRACION DE EMPRESAS***"<<endl;
        cout<<"1) Crear Micro"<<endl<<"2) Crear Recluta"<<endl<<"3) Agregar Recluta a Empresa"<<endl
            <<"4) Agregar Proveedor a Empresa Grande"<<"5) Eliminar Empleado o Pasante"<<endl
            <<"6) Mostrar Info Empresas"<<endl<<"7) Historial Estudiantes Eliminados"<<endl<<"8) salir"<<endl<<"Selecciona un opcion:"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                CrearMicro();
                break;
            case 2:
                CrearRecluta();
                break;
            case 3:
                if(reclutas.empty())
                    cout<<"TIENES QUE CREAR RECLUTAS PRIMERO"<<endl;
                else
                    if(grandes.empty()&&medianas.empty()&&micros.empty())
                        cout<<"TIENES QUE CREAR EMPRESA PRIMERO";
                    else
                        AggRecluta();
                break;
            case 4:
                if(grandes.empty())
                    cout<<"No hay empresas grandes a cuales agregar proveedores"<<endl;
                else
                    AggProveedor();
                break;
            case 5:
                EliminarEmpleado();
                break;
            case 6:
                if(!micros.empty())
                    PrintMicro();
                else
                    cout<<"No hay Micros"<<endl;
                if(!medianas.empty())
                    PrintMed();
                else
                    cout<<"No hay Medianas"<<endl;
                if(!grandes.empty())    
                    PrintGrand();
                else
                    cout<<"No hay grandes"<<endl;
                break;
            case 7:
                cout<<"LISTAR ELIMINADOS"<<endl;
                if(eliminados.empty())
                    cout<<"Eliminados esta vacio"<<endl;
                else
                    for(int i=0;i<eliminados.size();i++){
                        cout<<i+1<<")"<<eliminados[i]<<endl;
                    }
            case 8:
                break;
            default:
                cout<<"OPCION NO VALIDA"<<endl;
        }
        cout<<"Reiniciar?y/n"<<endl;
        
        cin>>resp;
    }
    for(int i=0;i<reclutas.size();i++)
        delete reclutas[i];
    for(int i=0;i<micros.size();i++)
        delete micros[i];
    for(int i=0;i<medianas.size();i++)
        delete medianas[i];
    for(int i=0;i<grandes.size();i++)
        delete grandes[i];
}

void CrearMicro(){
    string nombre,fecha,rubro,numeroOP,dueno;
    cout<<"***************"<<endl<<"NUEVA MICRO"<<endl<<"Nombre:"<<endl;
    cin>>nombre;
    cout<<endl<<"Fecha:"<<endl;
    cin>>fecha;
    cout<<endl<<"Rubro:"<<endl;
    cin>>rubro;
    cout<<endl<<"Numero de Oeracion:"<<endl;
    cin>>numeroOP;
    cout<<endl<<"Dueño:"<<endl;
    cin>>dueno;
    micros.push_back(new Microempresa(dueno,nombre,fecha,rubro,numeroOP));
    cout<<endl<<"MICRO CREADA"<<endl<<endl;
}

void CrearRecluta(){
    string nombre,numeroID,edad,sexo,nacionalidad,carrera,universidad,cuenta,indice;
    cout<<"***************"<<endl<<"NUEVO RECLUTA"<<endl<<"Nombre:"<<endl;
    cin>>nombre;
    cout<<endl<<"Numero de Identidad:"<<endl;
    cin>>numeroID;
    cout<<endl<<"Edad:"<<endl;
    cin>>edad;
    cout<<endl<<"Sexo:"<<endl;
    cin>>sexo;
    cout<<endl<<"Nacionalidad:"<<endl;
    cin>>nacionalidad;
    cout<<endl<<"Carrera:"<<endl;
    cin>>carrera;
    carreras.push_back(carrera);
    cout<<endl<<"Universidad"<<endl;
    cin>>universidad;
    cout<<endl<<"Cuenta:"<<endl;
    cin>>cuenta;
    cout<<endl<<"Indice:"<<endl;
    cin>>indice;
    reclutas.push_back(new Estudiante(carrera,universidad,cuenta,indice,nombre,numeroID,edad,sexo,nacionalidad));
    cout<<"RECLUTA CREADO EXITOSAMENTE"<<endl;
}

void AggRecluta(){
    int reclutasel,empresasel,opc,empopas;
    string salario,empleadoID,pasanteID,duracion;
    Empleado* nuevoempleado;
    Estudiante* nuevoestudiante;
    cout<<"***************"<<endl<<"A) SELECCIONAR RECLUTA"<<endl<<endl;
    for(int i=0;i<carreras.size();i++){
        int num=1;
        cout<<carreras[i]<<":"<<endl;
        for(int j=0;j<reclutas.size();j++){
            
                cout<<"   "<<num++<<") "<<reclutas[i]->getNombre()<<endl;
        }
        cout<<endl;
    }
    cout<<"Ingrese num de recluta:"<<endl;
    cin>>reclutasel;
    reclutasel--;
    while(reclutasel<0 || reclutasel>=reclutas.size()){
        cout<<"ERROR INGRESE NUMERO DE NUEVO:"<<endl;
        cin>>reclutasel;
    }
    cout<<endl<<"B) SELECCIONAR EMPRESA"<<endl<<endl<<"1) Micros"<<endl<<"2) Medianas"<<endl<<"3) Grandes"<<endl<<"Ingrese tipo de empresa:";
    cin>>opc;
    while(opc<=0 || opc>3){
        cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
        cin>>opc;
    }
    switch(opc){
        case 1:
            PrintMicro();
            cout<<"Ingrese empresa:"<<endl;
            cin>>empresasel;
            empresasel--;
            while(empresasel<0 || empresasel>=micros.size()){
            cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
            cin>>empresasel;
            }
            cout<<"Contratar como: \n1)empleado\n2)pasante?"<<endl;
            cin>>empopas;
            switch(empopas){
                case 1:
                    cout<<"Salario:"<<endl;
                    cin>>salario;
                    cout<<"ID de Empleado:"<<endl;
                    cin>>empleadoID;
                    nuevoempleado = new Empleado(empleadoID,salario,reclutas[reclutasel]->getCarrera(),reclutas[reclutasel]->getUniversidad(),reclutas[reclutasel]->getCuenta(),reclutas[reclutasel]->getIndice(),reclutas[reclutasel]->getNombre(),reclutas[reclutasel]->getNumID(),reclutas[reclutasel]->getEdad(),
                                                            reclutas[reclutasel]->getSexo(),reclutas[reclutasel]->getNacionalidad());
                    nuevoestudiante = dynamic_cast<Estudiante*>(nuevoempleado);
                    micros[empresasel]->addPasyEmp(nuevoestudiante);
                    delete nuevoempleado;
                    delete nuevoestudiante;
                    delete reclutas[reclutasel];
                    break;
                case 2:
                    cout<<"ID Pasante:"<<endl;
                    cin>>pasanteID;
                    cout<<"Duracion:"<<endl;
                    cin>>duracion;
                    nuevoempleado = new Empleado(pasanteID,duracion,reclutas[reclutasel]->getCarrera(),reclutas[reclutasel]->getUniversidad(),reclutas[reclutasel]->getCuenta(),reclutas[reclutasel]->getIndice(),reclutas[reclutasel]->getNombre(),reclutas[reclutasel]->getNumID(),reclutas[reclutasel]->getEdad(),
                                                            reclutas[reclutasel]->getSexo(),reclutas[reclutasel]->getNacionalidad());
                    nuevoestudiante = dynamic_cast<Estudiante*>(nuevoempleado);
                    micros[empresasel]->addPasyEmp(nuevoestudiante);
                    delete nuevoempleado;
                    delete nuevoestudiante;
                    delete reclutas[reclutasel];
                    break;
            }
            if(micros[empresasel]->getCant()>=5){
                string ingresos, egresos,departamento,rtn;
                cout<<"FELICIDADES SU MICRO EVOLUCIONADO A UNA MEDIANA"<<endl<<"Ingrese Ingresos Anuales:"<<endl;
                cin>>ingresos;
                cout<<"Egresos Anuales:"<<endl;
                cin>>egresos;
                cout<<"Numero de Departamentos:"<<endl;
                cin>>departamento;
                cout<<"RTN"<<endl;
                cin>>rtn;
                medianas.push_back(new Mediana(ingresos,egresos,departamento,rtn,micros[empresasel]->getDueno(),micros[empresasel]->getName(),micros[empresasel]->getFecha(),micros[empresasel]->getRubro(),micros[empresasel]->getNumeroOP()));
                delete micros[empresasel];
            }
            
            break;
        case 2:
            PrintMed();
            cout<<"Ingrese empresa:"<<endl;
            cin>>empresasel;
            empresasel--;
            while(empresasel<0 || empresasel>=medianas.size()){
            cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
            cin>>empresasel;
            }
            cout<<"Contratar como: \n1)empleado\n2)pasante?"<<endl;
            cin>>empopas;
            switch(empopas){
                case 1:
                    cout<<"Salario:"<<endl;
                    cin>>salario;
                    cout<<"ID de Empleado:"<<endl;
                    cin>>empleadoID;
                    nuevoempleado = new Empleado(empleadoID,salario,reclutas[reclutasel]->getCarrera(),reclutas[reclutasel]->getUniversidad(),reclutas[reclutasel]->getCuenta(),reclutas[reclutasel]->getIndice(),reclutas[reclutasel]->getNombre(),reclutas[reclutasel]->getNumID(),reclutas[reclutasel]->getEdad(),
                                                            reclutas[reclutasel]->getSexo(),reclutas[reclutasel]->getNacionalidad());
                    nuevoestudiante = dynamic_cast<Estudiante*>(nuevoempleado);
                    medianas[empresasel]->addPasyEmp(nuevoestudiante);
                    delete nuevoempleado;
                    delete nuevoestudiante;
                    delete reclutas[reclutasel];
                    break;
                case 2:
                    cout<<"ID Pasante:"<<endl;
                    cin>>pasanteID;
                    cout<<"Duracion:"<<endl;
                    cin>>duracion;
                    nuevoempleado = new Empleado(pasanteID,duracion,reclutas[reclutasel]->getCarrera(),reclutas[reclutasel]->getUniversidad(),reclutas[reclutasel]->getCuenta(),reclutas[reclutasel]->getIndice(),reclutas[reclutasel]->getNombre(),reclutas[reclutasel]->getNumID(),reclutas[reclutasel]->getEdad(),
                                                            reclutas[reclutasel]->getSexo(),reclutas[reclutasel]->getNacionalidad());
                    nuevoestudiante = dynamic_cast<Estudiante*>(nuevoempleado);
                    medianas[empresasel]->addPasyEmp(nuevoestudiante);
                    delete nuevoempleado;
                    delete nuevoestudiante;
                    delete reclutas[reclutasel];
                    break;
            }
            if(medianas[empresasel]->getCant()>15){
                string vice,proveedores;
                cout<<"FELICIDADES SU MEDIANA HA EVOLUCIONADO A UNA GRANDE"<<endl<<"Ingrese Vice Presidente:"<<endl;
                cin>>vice;
                cout<<"Proveedor:"<<endl;
                cin>>proveedores;
                grandes.push_back(new Grande(vice,proveedores,medianas[empresasel]->getIngresos(),medianas[empresasel]->getEgresos(),medianas[empresasel]->getDepartamento(),medianas[empresasel]->getRTN(),medianas[empresasel]->getDueno(),medianas[empresasel]->getName(),medianas[empresasel]->getFecha(),medianas[empresasel]->getRubro(),medianas[empresasel]->getNumeroOP()));
                delete medianas[empresasel];
            }
            break;
        case 3:
            PrintGrand();
            cout<<"Ingrese empresa:"<<endl;
            cin>>empresasel;
            empresasel--;
            while(empresasel<0 || empresasel>=grandes.size()){
            cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
            cin>>empresasel;
            }
            cout<<"Contratar como: \n1)empleado\n2)pasante?"<<endl;
            cin>>empopas;
            switch(empopas){
                case 1:
                    cout<<"Salario:"<<endl;
                    cin>>salario;
                    cout<<"ID de Empleado:"<<endl;
                    cin>>empleadoID;
                    nuevoempleado = new Empleado(empleadoID,salario,reclutas[reclutasel]->getCarrera(),reclutas[reclutasel]->getUniversidad(),reclutas[reclutasel]->getCuenta(),reclutas[reclutasel]->getIndice(),reclutas[reclutasel]->getNombre(),reclutas[reclutasel]->getNumID(),reclutas[reclutasel]->getEdad(),
                                                            reclutas[reclutasel]->getSexo(),reclutas[reclutasel]->getNacionalidad());
                    nuevoestudiante = dynamic_cast<Estudiante*>(nuevoempleado);
                    grandes[empresasel]->addPasyEmp(nuevoestudiante);
                    delete nuevoempleado;
                    delete nuevoestudiante;
                    delete reclutas[reclutasel];
                    break;
                case 2:
                    cout<<"ID Pasante:"<<endl;
                    cin>>pasanteID;
                    cout<<"Duracion:"<<endl;
                    cin>>duracion;
                    nuevoempleado = new Empleado(pasanteID,duracion,reclutas[reclutasel]->getCarrera(),reclutas[reclutasel]->getUniversidad(),reclutas[reclutasel]->getCuenta(),reclutas[reclutasel]->getIndice(),reclutas[reclutasel]->getNombre(),reclutas[reclutasel]->getNumID(),reclutas[reclutasel]->getEdad(),
                                                            reclutas[reclutasel]->getSexo(),reclutas[reclutasel]->getNacionalidad());
                    nuevoestudiante = dynamic_cast<Estudiante*>(nuevoempleado);
                    grandes[empresasel]->addPasyEmp(nuevoestudiante);
                    delete nuevoempleado;
                    delete nuevoestudiante;
                    delete reclutas[reclutasel];
                    break;
            }
            break;
    }
    cout<<"RECLUTA AGREGADO A EMPRESA"<<endl;

}

void AggProveedor(){
    int empresasel;
    PrintGrand();
    cout<<"***************"<<endl;
    cout<<"Ingrese empresa a agregar proveedores:"<<endl;
    cin>>empresasel;
    empresasel--;
    while(empresasel<0 || empresasel>=grandes.size()){
        cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
        cin>>empresasel;
    }
    char resp2= 'y';
    while(resp2 == 'y' || resp2=='Y'){
        string newprov;
        cout<<"Ingrese proveedor:"<<endl;
        cin>>newprov;
        
        grandes[empresasel]->addProveedores(newprov);
        cout<<"PROVEEDOR AGREGADO"<<endl<<"Desea agregar otro?y/n"<<endl;
        cin>>resp2;

    }
}

void EliminarEmpleado(){
    int opc,empresasel;
    string deleted;
    cout<<"***************"<<endl;
    cout<<endl<<"ELIMINAR EMPLEADO DE EMPRESA"<<endl<<endl<<"1) Micros"<<endl<<"2) Medianas"<<endl<<"3) Grandes"<<endl<<"Ingrese tipo de empresa:";
    cin>>opc;
    while(opc<=0 || opc>3){
        cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
        cin>>opc;
    }
    switch(opc){
        case 1:
            PrintMicro();
            cout<<"Ingrese empresa:"<<endl;
            cin>>empresasel;
            empresasel--;
            while(empresasel<0 || empresasel>=micros.size()){
            cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
            cin>>empresasel;
            }
            deleted = micros[empresasel]->deletefList(empresasel);
            eliminados.push_back(deleted);
            break;
        case 2:
            PrintMed();
            cout<<"Ingrese empresa:"<<endl;
            cin>>empresasel;
            empresasel--;
            while(empresasel<0 || empresasel>=medianas.size()){
            cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
            cin>>empresasel;

            }
            deleted = medianas[empresasel]->deletefList(empresasel);
            eliminados.push_back(deleted);
            break;
        case 3:
            PrintGrand();
            cout<<"Ingrese empresa:"<<endl;
            cin>>empresasel;
            empresasel--;
            while(empresasel<0 || empresasel>=grandes.size()){
            cout<<"ERROR NUM NO VALIDO INGRESE DE NUEVO:"<<endl;
            cin>>empresasel;
            }
            deleted = grandes[empresasel]->deletefList(empresasel);
            eliminados.push_back(deleted);
            break;
    }
}

void PrintGrand(){
    for(int i=0; i<grandes.size();i++){
        cout<<i+1<<") "<<grandes[i]->getName()<<", "<<grandes[i]->getFecha();
    }
}

void PrintMed(){
    for(int i=0; i<medianas.size();i++){
        cout<<i+1<<") "<<medianas[i]->getName()<<", "<<medianas[i]->getFecha();
    }
}

void PrintMicro(){
    for(int i=0; i<micros.size();i++){
        cout<<i+1<<") "<<micros[i]->getName()<<", "<<micros[i]->getFecha();
    }
}
