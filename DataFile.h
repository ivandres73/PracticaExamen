
#ifndef PRACTICAEXAMEN_DATAFILE_H
#define PRACTICAEXAMEN_DATAFILE_H

#include <stdio.h>

class DataFile {
public:
    //constructores
    DataFile();
    DataFile(char*);
    //atributos
    FILE* archivo;
    //funciones
    void abrir(char*);
    void cerrar();
    void escribir(char*,int, int);
    char* leer(int, int);

private:
    char* path;
};


#endif //PRACTICAEXAMEN_DATAFILE_H
