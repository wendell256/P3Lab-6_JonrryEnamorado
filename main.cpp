#include <iostream>
#include <string>
#include <vector>
#include "Estudiante.h"
#include "Persona.h"
using namespace std;

int main(){
    Estudiante* temp = new Estudiante("sistemas","UNITEC","123456","98","Wendy","0512-1999-01875","19","M","Hondureño");
    delete temp;
    return 0;
}