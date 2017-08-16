
#include "Registro3.h"

Registro3::Registro3() {
    archivo = new DataFile("C:\\Users\\ivand\\Desktop\\practica.ivan");
}

Registro3::Registro3(char * name, char * last, int age, char * address) {
    int longi;
    tamNombre = strlen(name);
    memcpy(&nombre, &name, tamNombre);
    tamApellido = strlen(last);
    memcpy(&apellido, &last, tamApellido);
    edad = age;
    tamDireccion = strlen(address);
    memcpy(&direccion, &address, tamDireccion);
}

void Registro3::mostrarRegistro() {
    cout << "nombre:" << nombre << endl;
    cout << "apellido:" << apellido << endl;
    cout << "edad: " << edad << endl;
    cout << "direccion: " << direccion << endl;
}

char* Registro3::toChar() {
    int longReg = tamanoDelRegistro();
    char finRegistro = '_';
    char* datos = new char[longReg];
    int pos = 0;
    memcpy(&datos[pos], &tamNombre, 4);
    pos += 4;
    memcpy(&datos[pos], nombre, tamNombre);
    pos += tamNombre;
    memcpy(&datos[pos], &tamApellido, 4);
    pos += 4;
    memcpy(&datos[pos], apellido, tamApellido);
    pos += tamApellido;
    memcpy(&datos[pos], &edad, 4);
    pos += 4;
    memcpy(&datos[pos], &tamDireccion, 4);
    pos += 4;
    memcpy(&datos[pos], direccion, tamDireccion);
    pos += tamDireccion;
    memcpy(&datos[pos], &finRegistro, 1);
    return datos;
}

void Registro3::fromChar(char * datos) {
    int pos = 0;
    memcpy(&tamNombre, &datos[pos], 4);
    pos += 4;
    memcpy(&nombre, &datos[pos], tamNombre);
    pos += tamNombre;
    memcpy(&tamApellido, &datos[pos], 4);
    pos += 4;
    memcpy(&apellido, &datos[pos], tamApellido);
    pos += tamApellido;
    memcpy(&edad, &datos[pos], 4);
    pos += 4;
    memcpy(&tamDireccion, &datos[pos], 4);
    pos += 4;
    memcpy(&apellido, &datos[pos], tamApellido);
}

int Registro3::tamanoDelRegistro() {
    int tam = 0;

    tam += tamNombre;
    tam += tamApellido;
    tam += 4;
    tam += tamDireccion;
    tam++;
    return tam;
}

void Registro3::abrirArchivo(char* para) {
    archivo->abrir(para);
}

void Registro3::cerrarArchivo() {
    archivo->cerrar();
}

void Registro3::escribirArchivo() {
    abrirArchivo("w+");
    char* data = this->toChar();
    archivo->escribir(data, 0, tamanoDelRegistro());
    cerrarArchivo();
}

void Registro3::leerArchivo() {
    abrirArchivo("r");
    char* data = archivo->leer(0,tamanoDelRegistro());
    fromChar(data);

}