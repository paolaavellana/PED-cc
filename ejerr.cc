#include <iostream>
using namespace std;

void SolicitarDatos(float *&ptr, int &n) {
    cout << "Ingrese la cantidad de ventas: ";
    cin >> n;

    // Reservar memoria
    ptr = new float[n];

    // Llenar datos
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la venta " << i + 1 << ": ";
        cin >> ptr[i];
    }
}

int main() {
    int n;
    float *ptr = nullptr; // puntero inicializado en nullptr

    SolicitarDatos(ptr, n);

    cout << "\n--- Ventas registradas ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Venta " << i + 1 << ": " << ptr[i] << endl;
    }

    // Liberar memoria
    delete[] ptr;
    ptr = nullptr;

    return 0;
}

