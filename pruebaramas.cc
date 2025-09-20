#include <iostream>
using namespace std;

// Función para llenar un arreglo con números enteros
void llenarArreglo(int arr[], int n, string nombre) {
    cout << "Ingrese los elementos del arreglo " << nombre << ":\n";
    for (int i = 0; i < n; i++) {
        cout << nombre << "[" << i << "] = ";
        cin >> arr[i];
    }
}

// Función para sumar dos arreglos y guardar el resultado en un tercero
void sumarArreglos(int arr1[], int arr2[], int resultado[], int n) {
    for (int i = 0; i < n; i++) {
        resultado[i] = arr1[i] + arr2[i];
    }
}

// Función para calcular el producto escalar (dot product)
int productoEscalar(int arr1[], int arr2[], int n) {
    int producto = 0;
    for (int i = 0; i < n; i++) {
        producto += arr1[i] * arr2[i];
    }
    return producto;
}

// Función para mostrar un arreglo
void mostrarArreglo(int arr[], int n, string nombre) {
    cout << nombre << ": ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de los arreglos: ";
    cin >> n;

    int arr1[n], arr2[n], suma[n];

    // Llenar arreglos
    llenarArreglo(arr1, n, "A");
    llenarArreglo(arr2, n, "B");

    // Mostrar arreglos originales
    mostrarArreglo(arr1, n, "Arreglo A");
    mostrarArreglo(arr2, n, "Arreglo B");

    // Calcular suma
    sumarArreglos(arr1, arr2, suma, n);
    mostrarArreglo(suma, n, "Suma A+B");

    // Calcular producto escalar
    int prodEsc = productoEscalar(arr1, arr2, n);
    cout << "Producto escalar (A·B): " << prodEsc << endl;

    return 0;
}
