#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

// Prototipos de funciones
void llenarArreglo(int arr[], int tam); // arreglo y su tamaño
void imprimirArreglo(int arr[], int tam);
void maximo(int arr[], int tam);
void minimo(int arr[], int tam);
void promedio(int arr[], int tam);

// ------------------ MAIN ------------------
int main() {
    int numeros[10]; // arreglo estatico de 10 enteros

    srand(time(0)); // inicializar semilla (solo una vez en todo el programa)

    llenarArreglo(numeros, 10);   // llenar con aleatorios
    imprimirArreglo(numeros, 10); // imprimir los números
    maximo(numeros, 10);          // encontrar el máximo
    minimo(numeros, 10);          // encontrar el mínimo
    promedio(numeros, 10);        // calcular el promedio

    return 0;
}

// ------------------ FUNCIONES ------------------

// Llena el arreglo con números aleatorios del 1 al 100
void llenarArreglo(int arr[], int tam) {
    for (int i = 0; i < tam; i++) { //emepezar en 0
        arr[i] = rand() % 100 + 1;
    }
}

// Imprime los valores del arreglo
void imprimirArreglo(int arr[], int tam) {
    cout << "Numeros generados: ";
    for (int i = 0; i < tam; i++) { // recorrer todo el arreglo
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Encuentra e imprime el valor máximo del arreglo
void maximo(int arr[], int tam) {
    int max = arr[0];
    for (int i = 1; i < tam; i++) { 
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "El valor maximo es: " << max << endl;
}

// Encuentra e imprime el valor mínimo del arreglo
void minimo(int arr[], int tam) {
    int min = arr[0];
    for (int i = 1; i < tam; i++) { // empezar en 1 ya que 0 ya se usó
        if (arr[i] < min) { 
            min = arr[i];
        }
    }
    cout << "El valor minimo es: " << min << endl;
}

// Calcula e imprime el promedio de los valores del arreglo
void promedio(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i]; // suma = suma + arr[i];
    }
    float prom = static_cast<float>(suma) / tam; // conversión a float para obtener decimal
    cout << "El promedio es: " << prom << endl;
}