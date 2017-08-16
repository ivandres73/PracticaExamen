
#include "Registro.h"

Registro::Registro() {
    archivo = new DataFile("C:\\Users\\ivand\\Desktop\\practica.ivan");
}

Registro::Registro(char * name, char * last, int age, char * address) {
    int longi;
    longi = strlen(name);
    cout << "longi: " << longi << endl;
    memcpy(&nombre, &name, longi);
    longi = strlen(last);
    cout << "longi: " << longi << endl;
    memcpy(&apellido, &last, longi);
    edad = age;
    longi = strlen(address);
    cout << "longi: " << longi << endl;
    memcpy(&direccion, &address, longi);

    edad = age;
}

void Registro::mostrarRegistro() {
    cout << "nombre:" << nombre << endl;
    cout << "apellido:" << apellido << endl;
    cout << "edad: " << edad << endl;
    cout << "direccion: " << direccion << endl;
}

char* Registro::toChar() {
    int longReg = tamanoDelRegistro();
    cout << "la longi es de: " << longReg << endl;
    char caraDeli = '\0';
    char finRegistro = ';';
    char* datos = new char[longReg];
    int pos = 0;
    int longi;
    longi = strlen(nombre);
    memcpy(&datos[pos], nombre, longi);
    pos += longi;
    memcpy(&datos[pos], &caraDeli, 1);
    pos++;
    longi = strlen(apellido);
    memcpy(&datos[pos], apellido, longi);
    pos += longi;
    memcpy(&datos[pos], &caraDeli, 1);
    pos++;
    memcpy(&datos[pos], &edad, 4);
    pos += 4;
    memcpy(&datos[pos], &caraDeli, 1);
    pos++;
    longi = strlen(direccion);
    memcpy(&datos[pos], direccion, longi);
    pos += longi;
    memcpy(&datos[pos], &finRegistro, 1);
    return datos;
}

int Registro::tamanoDelRegistro() {
    int tam = 0;

    tam += strlen(nombre);
    tam += strlen(apellido);
    tam += 4;
    tam += strlen(direccion);
    tam += 5;
    return tam;
}

void Registro::fromChar(char * datos) {
    int pos = 0;
    int longi = strlen(&datos[pos]);
    memcpy(nombre, &datos[pos], longi);
    pos += longi;
    longi = strlen(&datos[pos]);
    memcpy(apellido, &datos[pos], longi);
    pos += longi;
    longi = 4;
    memcpy(&edad, &datos[pos], longi);
    pos += 4;
    longi = strlen(&datos[pos]);
    memcpy(direccion, &datos[pos], longi);
}

void Registro::abrirArchivo(char* para) {
    archivo->abrir(para);
}

void Registro::escribirArchivo() {
    abrirArchivo("w+");
    char* data = this->toChar();
    archivo->escribir(data, 0, tamanoDelRegistro());
    cerrarArchivo();
}

void Registro::leerArchivo() {
    abrirArchivo("r");
    char* data = archivo->leer(0,tamanoDelRegistro());
    fromChar(data);

}

void Registro::cerrarArchivo() {
    archivo->cerrar();
}