
#include "DataFile.h"

DataFile::DataFile() {
    archivo = NULL;
}

DataFile::DataFile(char* direccion) {
    path = direccion;
}

void DataFile::abrir(char* purpose) {
    archivo = fopen(path, purpose);
}

void DataFile::cerrar() {
    fclose(archivo);
}

void DataFile::escribir(char * datos,int pos, int longitud) {
    fseek(archivo, longitud, SEEK_SET);
    fwrite(datos, 1, longitud, archivo);
}

char *DataFile::leer(int pos, int longi) {
    char* datos = new char[longi];
    fseek(archivo, pos, SEEK_SET);
    fread(datos, 1, longi, archivo);
}
