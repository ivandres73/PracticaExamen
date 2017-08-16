
#include "Registro2.h"

Registro2::Registro2() {
    archivo = new DataFile("C:\\Users\\ivand\\Desktop\\practica.ivan");
}

Registro2::Registro2(char * name, char * last, int age, char * address) {
    memcpy(&nombre, &name, 20);
    memcpy(&apellido, &last, 20);
    edad = age;
    memcpy(&direccion, &address, 20);
}

void Registro2::mostrarRegistro() {
    cout << "nombre:" << nombre << endl;
    cout << "apellido:" << apellido << endl;
    cout << "edad: " << edad << endl;
    cout << "direccion: " << direccion << endl;
}

char* Registro2::toChar() {
    char* datos = new char[65];
    int pos = 0;
    memcpy(&datos[pos], nombre, 20);
    pos += 20;
    memcpy(&datos[pos], apellido, 20);
    pos += 20;
    memcpy(&datos[pos], &edad, 4);
    pos += 4;
    memcpy(&datos[pos], direccion, 20);
    pos += 20;
    char fin = '\n';
    memcpy(&datos[pos], &fin, 1);
    return datos;
}

void Registro2::fromChar(char * datos) {
    int pos = 0;
    memcpy(nombre, &datos[pos], 20);
    pos += 20;
    memcpy(apellido, &datos[pos], 20);
    pos += 20;
    memcpy(&edad, &datos[pos], 4);
    pos += 4;
    memcpy(direccion, &datos[pos], 20);
}

void Registro2::escribirArchivo() {
    abrirArchivo("w+");
    char* data = this->toChar();
    archivo->escribir(data, 0, tamanoDelRegistro());
    cerrarArchivo();
}

void Registro2::cerrarArchivo() {
    archivo->cerrar();
}

void Registro2::leerArchivo() {
    abrirArchivo("r");
    char* data = archivo->leer(0,tamanoDelRegistro());
    fromChar(data);

}

void Registro2::abrirArchivo(char* para) {
    archivo->abrir(para);
}