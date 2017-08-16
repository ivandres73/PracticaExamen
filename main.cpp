#include <iostream>

#include "DataFile.h"
#include "Registro.h"
#include <string.h>

void desglosarDatos(char* datos, int longi) {
    for (int i=0; i < longi; i++) {
        cout << "[" << i << "]: " << datos[i] << endl;
    }
}

int main() {
    Registro* reg1 = new Registro("Ivan", "Andres", 19, "col. el limonar");
    reg1->mostrarRegistro();
    int log = reg1->tamanoDelRegistro();
    char* datos = reg1->toChar();
    //char* datos = new char[log];
    //datos = reg1->toChar();
    //desglosarDatos(datos, reg1->tamanoDelRegistro());
/*    Registro* reg2 = new Registro();
    reg2->fromChar(datos);
    reg2->mostrarRegistro();*/
    return 0;
}