#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
using namespace std;

class Usuario {
private:
    string nombreUsuario;
    int idUsuario;

public:
    Usuario();
    Usuario(string n, int id);

    void mostrarInformacion();
    int getId();
    string getNombre();   // ? ARREGLADO
};

#endif
