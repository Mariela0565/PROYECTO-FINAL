#ifndef RESERVA_H
#define RESERVA_H

#include "Libro.h"
#include "Usuario.h"
#include <string>

using namespace std;

class Reserva {
private:
    int idReserva;
    Libro libro;
    Usuario usuario;
    string fecha;

public:
    Reserva();
    Reserva(int id, Libro l, Usuario u, string f);

    void mostrar();
};

#endif
