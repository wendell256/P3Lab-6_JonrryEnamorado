#include "Pasante.h"

Pasante::Pasante(string pIDPas,string duracion,string pcarrera,string puniversidad,string pcuenta,string pindice,string pnombre,string pnumeroID,string pedad,string psexo,string pnacionalidad):Estudiante(pcarrera,puniversidad,pcuenta,pindice,pnombre,pnumeroID,pedad,psexo,pnacionalidad){
    IDpas=pIDPas;
    this->duracion=duracion;
}