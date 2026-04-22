#include "Usuario.h"

Usuario::Usuario() {
    nombreUsuario = "";
    idUsuario = 0;
}

Usuario::Usuario(string n, int id) {
    nombreUsuario = n;
    idUsuario = id;
}

void Usuario::mostrarInformacion() {
    cout << "Nombre: " << nombreUsuario << endl;
    cout << "ID: " << idUsuario << endl;
}

int Usuario::getId() {
    return idUsuario;
}

string Usuario::getNombre() {   // ? ARREGLADO
    return nombreUsuario;
}
