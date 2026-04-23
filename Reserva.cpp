#include "Reserva.h"

Reserva::Reserva() {
    idReserva = 0;
    fecha = "";
}

Reserva::Reserva(int id, Libro l, Usuario u, string f) {
    idReserva = id;
    libro = l;
    usuario = u;
    fecha = f;
}

void Reserva::mostrar() {
    cout << "\n===== RESERVA =====" << endl;
    cout << "ID: " << idReserva << endl;
    cout << "Fecha: " << fecha << endl;

    cout << "\nLibro:\n";
    libro.mostrarInformacion();

    cout << "\nUsuario:\n";
    usuario.mostrarInformacion();

    cout << "===================\n";
}
