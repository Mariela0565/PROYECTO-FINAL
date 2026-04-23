#include "Libro.h"

Libro::Libro() {
    titulo = "";
    autor = "";
    anioPublicacion = 0;
    disponible = true;
}

Libro::Libro(string t, string a, int anio, bool d) {
    titulo = t;
    autor = a;
    anioPublicacion = anio;
    disponible = d;
}

void Libro::mostrarInformacion() {
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Año: " << anioPublicacion << endl;
    cout << "Estado: " << (disponible ? "Disponible" : "Reservado") << endl;
    cout << "----------------------" << endl;
}

void Libro::marcarComoReservado() {
    disponible = false;
}

void Libro::marcarComoDisponible() {
    disponible = true;
}

bool Libro::estaDisponible() {
    return disponible;
}

string Libro::getTitulo() {
    return titulo;
}
