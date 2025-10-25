#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

struct Habitacion {
    int numero;
    string tipo;
    float precio;
    int capacidad;
    string estado;
};

// Lista global de habitaciones
list<Habitacion> listaHabitaciones;

// Función para mostrar todas las habitaciones
void mostrarHabitaciones() {
    if (listaHabitaciones.empty()) {
        cout << "\nNo hay habitaciones registradas.\n";
        return;
    }

    cout << "\nLista de Habitaciones:\n";
    for (const auto &h : listaHabitaciones) {
        cout << "Numero: " << h.numero 
             << " | Tipo: " << h.tipo
             << " | Precio: $" << h.precio
             << " | Capacidad: " << h.capacidad
             << " | Estado: " << h.estado << endl;
    }
}

// Función para agregar una habitación
void agregarHabitacion() {
    Habitacion h;
    cout << "\nRegistrar nueva habitación\n";
    cout << "Número de habitación: ";
    cin >> h.numero;
    cin.ignore();

    cout << "Tipo (sencilla, doble, suite, etc): ";
    getline(cin, h.tipo);

    cout << "Precio por noche: ";
    cin >> h.precio;
    cin.ignore();

    cout << "Capacidad de la habitación: ";
    cin >> h.capacidad;
    cin.ignore();

    cout << "Estado (disponible o reservada): ";
    getline(cin, h.estado);

    listaHabitaciones.push_back(h);
    cout << "\nHabitación registrada correctamente.\n";
}

// Función para ordenar habitaciones por precio
void ordenarPorPrecio() {
    if (listaHabitaciones.empty()) {
        cout << "\nNo hay habitaciones para ordenar.\n";
        return;
    }

    listaHabitaciones.sort([](const Habitacion &a, const Habitacion &b) {
        return a.precio < b.precio;
    });

    cout << "\nHabitaciones ordenadas por precio correctamente.\n";
}

// Función para buscar habitación por número
void buscarHabitacion() {
    if (listaHabitaciones.empty()) {
        cout << "\nNo hay habitaciones registradas.\n";
        return;
    }

    int num;
    cout << "\nIngrese el número de habitación a buscar: ";
    cin >> num;

    auto it = find_if(listaHabitaciones.begin(), listaHabitaciones.end(),
                      [num](const Habitacion &h) { return h.numero == num; });

    if (it != listaHabitaciones.end()) {
        cout << "\nHabitación encontrada:\n";
        cout << "Número: " << it->numero << endl;
        cout << "Tipo: " << it->tipo << endl;
        cout << "Precio: $" << it->precio << endl;
        cout << "Capacidad: " << it->capacidad << " personas\n";
        cout << "Estado: " << it->estado << endl;
    } else {
        cout << "\nNo se encontró ninguna habitación con el número " << num << ".\n";
    }
}

int main() {
    int opcion;

    do {
        cout << "\n=== Menú de Opciones ===\n";
        cout << "1. Agregar Habitación\n";
        cout << "2. Ordenar Habitaciones por Precio\n";
        cout << "3. Buscar Habitación por Número\n";
        cout << "4. Mostrar Todas las Habitaciones\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarHabitacion();
                break;
            case 2:
                ordenarPorPrecio();
                break;
            case 3:
                buscarHabitacion();
                break;
            case 4:
                mostrarHabitaciones();
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}