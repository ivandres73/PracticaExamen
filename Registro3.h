
#ifndef PRACTICAEXAMEN_REGISTRO3_H
#define PRACTICAEXAMEN_REGISTRO3_H

#include "DataFile.h"
#include <iostream>
#include <string.h>

using namespace std;

class Registro3 {
    //constructores
    Registro3();
    Registro3(char*, char*, int, char*);
    //atributos

    //funciones
    void mostrarRegistro();//Delimitadores de longi por Campos, Separacion por caracter por Registros
    char* toChar();
    void fromChar(char*);
    void abrirArchivo(char*);
    void escribirArchivo();
    void leerArchivo();
    void cerrarArchivo();

    int tamanoDelRegistro();

private:
    DataFile* archivo;
    int tamNombre;
    char* nombre;
    int tamApellido;
    char* apellido;
    int edad;
    int tamDireccion;
    char* direccion;
};


#endif //PRACTICAEXAMEN_REGISTRO3_H
