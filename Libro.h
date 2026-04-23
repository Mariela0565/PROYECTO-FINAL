#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anioPublicacion;
    bool disponible;

public:
    Libro();
    Libro(string t, string a, int anio, bool d);

    void mostrarInformacion();

    void marcarComoReservado();
    void marcarComoDisponible();

    bool estaDisponible();
    string getTitulo();
};

#endif
