#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Estructura para guardar los datos de cada luchador
struct Luchador {
    string nombre;
    float peso;
};

// Función para solicitar los datos de un luchador
Luchador SolicitarDatos() {
    Luchador luchador;
    cout << "Ingrese el nombre del luchador: ";
    cin >> luchador.nombre;
    cout << "Ingrese el peso en libras: ";
    cin >> luchador.peso;
    return luchador;
}

// Función para encontrar el luchador más pesado
Luchador LuchadorMasPesado(const vector<Luchador>& lista) {
    Luchador masPesado = lista[0];
    for (size_t i = 1; i < lista.size(); i++) {
        if (lista[i].peso > masPesado.peso) {
            masPesado = lista[i];
        }
    }
    return masPesado;
}

// Función para ordenar de mayor a menor peso (burbuja)
void OrdenarPorPeso(vector<Luchador>& lista) {
    for (size_t i = 0; i < lista.size() - 1; i++) {
        for (size_t j = i + 1; j < lista.size(); j++) {
            if (lista[i].peso < lista[j].peso) {
                swap(lista[i], lista[j]);
            }
        }
    }
}

int main() {
    vector<Luchador> luchadores;
    const int kn = 5;

    // Ingreso de datos
    cout << "Registro de Luchadores\n";
    for (int i = 0; i < kn; i++) {
        cout << "\nLuchador " << i + 1 << ":\n";
        Luchador nuevo = SolicitarDatos();
        luchadores.push_back(nuevo);
    }
    
    // Ordenar e imprimir resultados
    OrdenarPorPeso(luchadores);
    cout << "\n Luchadores de mayor a menor peso \n";
    for (size_t i = 0; i < luchadores.size(); i++) {
        cout << i + 1 << ". " << luchadores[i].nombre
             << " - " << luchadores[i].peso << " lbs\n";
    }

    // Determinar el luchador más pesado
    Luchador pesado = LuchadorMasPesado(luchadores);
    cout << "\nEl luchador mas pesado es: " << pesado.nombre
         << " con " << pesado.peso << " lbs.\n";

    return 0;
}