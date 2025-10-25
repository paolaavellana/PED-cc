#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

// Función para mostrar la lista de luchadores
void MostrarLuchadores(const vector<Luchador>& luchadores) {
    cout << "\n--- Lista de Luchadores ---\n";
    for (const auto& l : luchadores) {
        cout << "Nombre: " << l.nombre << " | Peso: " << l.peso << " lbs\n";
    }
}

bool CompararPeso (const Luchador& a, const Luchador& b) 
    {//ordenamos de mayor a menor
    return a.peso < b.peso;
    } 

//Implementando find_if
void BuscarPorNombre (const vector<Luchador>& luchadores, const string& nombreBuscar);

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
    
    // Ordenar por peso (requisito para usar binary_search)
    sort(luchadores.begin(), luchadores.end(), CompararPeso);

    // Mostrar la lista ordenada
    MostrarLuchadores(luchadores);

    // Buscar un luchador por su peso usando binary_search
    float pesoBuscar;
    cout << "\nIngrese el peso del luchador a buscar: ";
    cin >> pesoBuscar;

   // Buscar un luchador por su nombre usando find_if
string nombre_buscado;
cout << "\nIngrese el nombre del luchador a buscar: ";
cin >> nombre_buscado;

auto it = find_if(luchadores.begin(), luchadores.end(), [&](const Luchador& luchador) {return luchador.nombre == nombre_buscado;});

if (it != luchadores.end()) {
    cout << "Luchador encontrado: " << it->nombre << " con peso " << it->peso << " lbs.\n";
} else {
    cout << "Luchador con nombre '" << nombre_buscado << "' no encontrado.\n";
}
    // binary_search necesita una forma de comparar
    bool encontrado = binary_search(luchadores.begin(), luchadores.end(),  Luchador{"", pesoBuscar}, CompararPeso);

    if (encontrado) {
        cout << "Luchador con peso " << pesoBuscar << " lbs encontrado.\n";
    } else {
        cout << "Luchador con peso " << pesoBuscar << " lbs no encontrado.\n";
    }
    return 0;
}
//colas, listas, pilas no permiten buscar por indice 
//los vectores si permiten buscar por indice