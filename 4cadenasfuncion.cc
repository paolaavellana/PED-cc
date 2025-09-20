#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Prototipos de funciones
void palindromo(char array[]);
void vocales(char array[]);

int main()
{
    // Declaramos un arreglo de caracteres para almacenar la palabra (máx. 30 caracteres)
    char palabra[30]{};

    // Solicitamos al usuario que ingrese una palabra
    cout << "Ingrese una sola palabra:\n";
    cin >> palabra;

    // Llamamos a las funciones
    palindromo(palabra);
    vocales(palabra);
}

// Función que verifica si la palabra ingresada es un palíndromo
void palindromo(char array[])
{
    int n = 0; // longitud de la palabra
    int x = 0; // bandera (0 = es palíndromo, 1 = no es)

    // Contamos los caracteres de la palabra hasta el carácter nulo '\0'
    for (int i = 0; i < 30; i++)
    {
        if (array[i] != '\0')
        {
            n++;
        }
    }

    // Comparamos los caracteres simétricamente (inicio con final)
    for (int j = 0; j < n; j++)
    {
        if (array[j] != array[n - 1 - j])
        {
            x = 1; // Si no son iguales, ya no es palíndromo
        }
    }

    // Mostramos el resultado
    if (x != 1)
    {
        cout << "La palabra es un palindromo\n";
    }
    else
    {
        cout << "La palabra no es un palindromo\n";
    }
}

// Función que cuenta cuántas vocales y consonantes tiene la palabra
void vocales(char array[])
{
    int n = 0; // longitud de la palabra
    int a = 0; // cantidad de vocales

    // Calculamos la longitud de la palabra
    for (int i = 0; i < 30; i++)
    {
        if (array[i] != '\0')
        {
            n++;
        }
    }

    // Contamos las vocales
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u' ||
            array[i] == 'A' || array[i] == 'E' || array[i] == 'I' || array[i] == 'O' || array[i] == 'U')
        {
            a++;
        }
    }

    // Imprimimos la cantidad de vocales y consonantes
    cout << "La palabra tiene " << a << " vocales y " << n - a << " consonantes \n";
}