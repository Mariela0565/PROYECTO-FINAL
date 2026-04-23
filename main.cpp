#include <iostream>
#include <string>
#include "Libro.h"
#include "Usuario.h"
#include "Reserva.h"

using namespace std;

// ================= VALIDACIONES =================

int buscarLibro(Libro libros[], int total, string titulo) {
    for (int i = 0; i < total; i++) {
        if (libros[i].getTitulo() == titulo) return i;
    }
    return -1;
}

int buscarUsuario(Usuario usuarios[], int total, string nombre) {
    for (int i = 0; i < total; i++) {
        if (usuarios[i].getNombre() == nombre) return i;
    }
    return -1;
}

// ================= MAIN =================

int main() {

    Libro libros[120];
    Usuario usuarios[120];
    Reserva reservas[120];

    int totalLibros = 0;
    int totalUsuarios = 0;
    int totalReservas = 0;
    int idReserva = 1;

    int opcion;

    // LIBROS INICIALES
    libros[totalLibros++] = Libro("Cardiologia Clinica", "Braunwald", 2015, true);
    libros[totalLibros++] = Libro("Enfermeria Basica", "Kozier", 2018, true);
    libros[totalLibros++] = Libro("Anatomia Humana", "Gray", 2011, true);

    // ================= LIBROS AGREGADOS =================

    // Edgar Allan Poe
    libros[totalLibros++] = Libro("El cuervo", "Edgar Allan Poe", 1845, true);
    libros[totalLibros++] = Libro("Los crimenes de la Rue Morgue", "Edgar Allan Poe", 1841, true);
    libros[totalLibros++] = Libro("El corazon delator", "Edgar Allan Poe", 1843, true);
    libros[totalLibros++] = Libro("La caida de la casa Usher", "Edgar Allan Poe", 1839, true);
    libros[totalLibros++] = Libro("El gato negro", "Edgar Allan Poe", 1843, true);

    // Don Quijote de la Mancha
    libros[totalLibros++] = Libro("Don Quijote de la Mancha I", "Miguel de Cervantes", 1605, true);
    libros[totalLibros++] = Libro("Don Quijote de la Mancha II", "Miguel de Cervantes", 1615, true);

    // Física
    libros[totalLibros++] = Libro("Fisica Conceptual", "Paul Hewitt", 2002, true);
    libros[totalLibros++] = Libro("Introduccion a la Mecanica Cuantica", "David J. Griffiths", 1995, true);
    libros[totalLibros++] = Libro("Relatividad: Teoria Especial y General", "Albert Einstein", 1916, true);
    libros[totalLibros++] = Libro("Feynman Lectures on Physics", "Richard Feynman", 1964, true);

    // Matemáticas
    libros[totalLibros++] = Libro("Algebra Lineal y sus Aplicaciones", "Gilbert Strang", 2016, true);
    libros[totalLibros++] = Libro("Calculo", "James Stewart", 2015, true);
    libros[totalLibros++] = Libro("Teoria de Numeros", "G.H. Hardy", 1938, true);

    // Medicina / Cardiología
    libros[totalLibros++] = Libro("Harrison Principios de Medicina Interna", "Harrison", 2018, true);
    libros[totalLibros++] = Libro("Cardiologia Clinica Avanzada", "Braunwald", 2020, true);
    libros[totalLibros++] = Libro("Atlas de Anatomia Humana", "Frank Netter", 2014, true);
    libros[totalLibros++] = Libro("Fisiologia Medica", "Arthur Guyton", 2016, true);
    libros[totalLibros++] = Libro("Farmacologia Basica y Clinica", "Katzung", 2018, true);

    // Ciencias generales
    libros[totalLibros++] = Libro("Biologia Molecular de la Celula", "Alberts", 2014, true);
    libros[totalLibros++] = Libro("Quimica General", "Raymond Chang", 2017, true);
    libros[totalLibros++] = Libro("Neurociencia: explorando el cerebro", "Bear", 2016, true);

    // Artes
    libros[totalLibros++] = Libro("Historia del Arte", "Gombrich", 1995, true);
    libros[totalLibros++] = Libro("El Arte de la Pintura", "Varios Autores", 2001, true);
    libros[totalLibros++] = Libro("Teoria del Color", "Johannes Itten", 2010, true);
    libros[totalLibros++] = Libro("Dibujo para Artistas", "Andrew Loomis", 2008, true);

    do {
        cout << "\n===== SISTEMA BIBLIOTECA =====\n";
        cout << "1. Agregar libro\n";
        cout << "2. Ver libros\n";
        cout << "3. Eliminar libro\n";
        cout << "4. Buscar libro\n";
        cout << "5. Agregar usuario\n";
        cout << "6. Ver usuarios\n";
        cout << "7. Eliminar usuario\n";
        cout << "8. Reservar libro\n";
        cout << "9. Ver reservas\n";
        cout << "10. Devolver libro\n";
        cout << "11. Salir\n";
        cout << "Opcion: ";

        cin >> opcion;
        cin.ignore();

        // ================= 1 AGREGAR LIBRO =================
        if (opcion == 1) {
            string t, a;
            int anio;

            cout << "Titulo: ";
            getline(cin, t);

            if (buscarLibro(libros, totalLibros, t) != -1) {
                cout << "Ya existe ese libro\n";
                continue;
            }

            cout << "Autor: ";
            getline(cin, a);

            cout << "Anio: ";
            cin >> anio;
            cin.ignore();

            libros[totalLibros++] = Libro(t, a, anio, true);
            cout << "Libro agregado\n";
        }

        // ================= 2 VER LIBROS =================
        else if (opcion == 2) {
            if (totalLibros == 0) cout << "No hay libros\n";
            else {
                for (int i = 0; i < totalLibros; i++) {
                    libros[i].mostrarInformacion();
                }
            }
        }

        // ================= 3 ELIMINAR LIBRO =================
        else if (opcion == 3) {
            string t;
            cout << "Titulo a eliminar: ";
            getline(cin, t);

            int pos = buscarLibro(libros, totalLibros, t);

            if (pos == -1) {
                cout << "No encontrado\n";
            } else {
                for (int i = pos; i < totalLibros - 1; i++) {
                    libros[i] = libros[i + 1];
                }
                totalLibros--;
                cout << "Libro eliminado\n";
            }
        }

        // ================= 4 BUSCAR LIBRO =================
        else if (opcion == 4) {
            string t;
            cout << "Titulo: ";
            getline(cin, t);

            int pos = buscarLibro(libros, totalLibros, t);

            if (pos == -1) cout << "No encontrado\n";
            else libros[pos].mostrarInformacion();
        }

        // ================= 5 AGREGAR USUARIO =================
        else if (opcion == 5) {
            string n;
            int id;

            cout << "Nombre: ";
            getline(cin, n);

            cout << "ID: ";
            cin >> id;
            cin.ignore();

            usuarios[totalUsuarios++] = Usuario(n, id);
            cout << "Usuario agregado\n";
        }

        // ================= 6 VER USUARIOS =================
        else if (opcion == 6) {
            for (int i = 0; i < totalUsuarios; i++) {
                usuarios[i].mostrarInformacion();
            }
        }

        // ================= 7 ELIMINAR USUARIO =================
        else if (opcion == 7) {
            string n;
            cout << "Nombre a eliminar: ";
            getline(cin, n);

            int pos = buscarUsuario(usuarios, totalUsuarios, n);

            if (pos == -1) cout << "No encontrado\n";
            else {
                for (int i = pos; i < totalUsuarios - 1; i++) {
                    usuarios[i] = usuarios[i + 1];
                }
                totalUsuarios--;
                cout << "Usuario eliminado\n";
            }
        }

        // ================= 8 RESERVAR =================
        else if (opcion == 8) {
            string libroT, userN, fecha;

            cout << "Libro: ";
            getline(cin, libroT);

            int posLibro = buscarLibro(libros, totalLibros, libroT);

            if (posLibro == -1 || !libros[posLibro].estaDisponible()) {
                cout << "Libro no disponible\n";
                continue;
            }

            cout << "Usuario: ";
            getline(cin, userN);

            int posUser = buscarUsuario(usuarios, totalUsuarios, userN);

            if (posUser == -1) {
                cout << "Usuario no existe\n";
                continue;
            }

            cout << "Fecha: ";
            getline(cin, fecha);

            libros[posLibro].marcarComoReservado();

            reservas[totalReservas++] = Reserva(idReserva++, libros[posLibro], usuarios[posUser], fecha);

            cout << "Reserva creada\n";
        }

        // ================= 9 VER RESERVAS =================
        else if (opcion == 9) {
            for (int i = 0; i < totalReservas; i++) {
                reservas[i].mostrar();
            }
        }

        // ================= 10 DEVOLVER LIBRO =================
        else if (opcion == 10) {
            string t;
            cout << "Libro a devolver: ";
            getline(cin, t);

            int pos = buscarLibro(libros, totalLibros, t);

            if (pos == -1) {
                cout << "No encontrado\n";
            } else {
                libros[pos].marcarComoDisponible();
                cout << "Libro devuelto\n";
            }
        }

    } while (opcion != 11);

    return 0;
}
