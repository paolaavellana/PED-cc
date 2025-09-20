#include <iostream>   // Para entrada y salida estándar
#include <cstdlib>    // Para rand() y srand()
#include <ctime>      // Para time()
#include <algorithm>  // Para usar sort()
using namespace std;

// Declaración de una matriz global de 5x5
int matriz[5][5];

// Prototipos de funciones
void random(int array[5][5]); // Llenar matriz con números aleatorios
void suma(int array[5][5]);   // Calcular sumas de filas y columnas
void trans(int array[5][5]);  // Calcular transpuesta de la matriz

int main()
{
    srand(time(0));   // Inicializa la semilla para generar números aleatorios diferentes cada vez

    random(matriz);   // Genera la matriz con números aleatorios y la imprime
    suma(matriz);     // Calcula y muestra sumas de filas y columnas
    trans(matriz);    // Calcula y muestra la transpuesta de la matriz
}

// -------------------- FUNCIONES -------------------- //

// Función que llena la matriz con números aleatorios
void random(int array[5][5])
{
    // Llenar la matriz con valores aleatorios
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            array[i][j] = rand(); // Número aleatorio entre 0 y RAND_MAX
        }
    }

    // Imprimir la matriz original
    cout << "La matriz es: \n";
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << array[i][j] << "\t";
        }
    }
}

// Función que calcula la suma de cada fila y cada columna
void suma(int array[5][5])
{
    int suma_fila[5];     // Guardar suma de cada fila
    int suma_columna[5];  // Guardar suma de cada columna
    int suma = 0;         // Variable acumuladora

    // Calcular suma de filas
    for (int i = 0; i < 5; i++)
    {
        suma = 0;
        for (int j = 0; j < 5; j++)
        {
            suma = suma + array[i][j];   // Acumula valores de la fila i
            suma_fila[i] = suma;         // Guarda la suma en el vector
        }
    }

    // Calcular suma de columnas
    for (int i = 0; i < 5; i++)
    {
        suma = 0;
        for (int j = 0; j < 5; j++)
        {
            suma = suma + array[j][i];   // Acumula valores de la columna i
            suma_columna[i] = suma;      // Guarda la suma en el vector
        }
    }

    // Mostrar resultados
    for (int i = 0; i < 5; i++)
    {
        cout << "La suma de la fila " << i + 1 << " es: " << suma_fila[i] << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "La suma de la columna " << i + 1 << " es: " << suma_columna[i] << endl;
    }

    // Ordenar las sumas de filas para encontrar la mayor
    sort(suma_fila, suma_fila + 5);
    cout << "\nLa fila con mayor suma es " << suma_fila[4] << endl;
}

// Función que calcula la transpuesta de la matriz
void trans(int array[5][5])
{
    int matriz2[5][5]; // Matriz para guardar la transpuesta

    // Transponer la matriz: fila pasa a columna
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz2[j][i] = array[i][j];
        }
    }

    // Imprimir la matriz transpuesta
    cout << "\nLa transposicion de la matriz es:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << matriz2[i][j] << "\t";
        }
    }
}
