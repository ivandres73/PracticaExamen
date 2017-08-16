
#ifndef PRACTICAEXAMEN_REGISTRO2_H
#define PRACTICAEXAMEN_REGISTRO2_H

#include "DataFile.h"
#include <string.h>
#include <iostream>

using namespace std;

class Registro2 {
    //constructores
    Registro2();
    Registro2(char*, char*, int, char*);
    //atributos

    //funciones
    void mostrarRegistro();
    char* toChar();//Tamano Fijo para campos, Separacion por caracter Registro
    void fromChar(char*);
    void abrirArchivo(char*);
    void escribirArchivo();
    void leerArchivo();
    void cerrarArchivo();

    int tamanoDelRegistro();

private:
    DataFile* archivo;
    char nombre[20];
    char apellido[20];
    int edad;
    char direccion[20];
};


#endif //PRACTICAEXAMEN_REGISTRO2_H
