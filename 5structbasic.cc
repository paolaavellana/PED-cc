#include <iostream> 
using namespace std;

struct Alumno {
    string nombre;
    int edad;
    float promedio;
};

struct Promedio {
    float mejor;
    string nombreAlumno; // ahora guardamos también el nombre
};

// Prototipos
Alumno SolicitarDatos();
Promedio calcularMejorPromedio(Alumno alumnos[], int tam); 

int main() {
    Alumno alumnos[3]; // arreglo estático de 3 alumnos

    // Llenar datos de cada alumno
    for (int i = 0; i < 3; i++) {
        cout << "\n--- Alumno " << i + 1 << " ---\n";
        alumnos[i] = SolicitarDatos(); 
    }

    // Mostrar datos ingresados
    cout << "\n=== LISTA DE ALUMNOS ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "Alumno " << i + 1 << ":\n";
        cout << "Nombre: " << alumnos[i].nombre << "\n";
        cout << "Edad: " << alumnos[i].edad << "\n";
        cout << "Promedio: " << alumnos[i].promedio << "\n\n";
    }

    // Calcular y mostrar el mejor promedio
    Promedio mejorPromedio = calcularMejorPromedio(alumnos, 3);
    cout << "El mejor promedio es de " << mejorPromedio.nombreAlumno 
         << " con " << mejorPromedio.mejor << "\n";

    return 0;
}

// Función para solicitar datos de un alumno
Alumno SolicitarDatos() {
    Alumno alumno;

    cout << "--- INGRESAR INFORMACION ---\n";
    cout << "Nombre: ";
    cin >> alumno.nombre;
    cout << "Edad: ";
    cin >> alumno.edad;
    cout << "Promedio: ";
    cin >> alumno.promedio;

    return alumno;
}  

// Función para calcular el mejor promedio
Promedio calcularMejorPromedio(Alumno alumnos[], int tam) {
    Promedio mejorPromedio;
    mejorPromedio.mejor = alumnos[0].promedio;
    mejorPromedio.nombreAlumno = alumnos[0].nombre;

    for (int i = 1; i < tam; i++) {
        if (alumnos[i].promedio > mejorPromedio.mejor) {
            mejorPromedio.mejor = alumnos[i].promedio;
            mejorPromedio.nombreAlumno = alumnos[i].nombre;
        }
    }

    return mejorPromedio;
}
