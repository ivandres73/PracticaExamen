
#ifndef PRACTICAEXAMEN_CAMPOS_H
#define PRACTICAEXAMEN_CAMPOS_H

#include "DataFile.h"
#include <string.h>
#include <iostream>

using namespace std;

class Registro {
public:
    //constructores
    Registro();
    Registro(char*, char*, int, char*);
    //atributos

    //funciones
    void mostrarRegistro();
    char* toChar();//Separacion por caracter tanto en campos como por registros
    void fromChar(char*);//Separacion por caracter tanto en campos como por registros
    void abrirArchivo(char*);
    void escribirArchivo();
    void leerArchivo();
    void cerrarArchivo();

    int tamanoDelRegistro();

private:
    DataFile* archivo;
    char* nombre;
    char* apellido;
    int edad;
    char* direccion;
};


#endif //PRACTICAEXAMEN_CAMPOS_H
