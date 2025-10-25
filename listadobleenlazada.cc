#include <iostream>
using namespace std;

struct Datos
{
    int numero;
};

struct Nodo
{
    struct Datos datos;     
    struct Nodo *siguiente; 
    struct Nodo *anterior;
};
void InsertarInicio(struct Nodo **lista, int n);
void InsertarFinal (struct Nodo **lista, int n);
void EliminarNodoValor (struct Nodo **lista, int n);

int main(int argc, char *argv[])
{

    // Reserva de memoria stack
    struct Nodo *lista = nullptr;
    InsertarInicio(&lista, 100);
    InsertarInicio(&lista, 7);
    InsertarInicio(&lista, 17);
    cout << "Direccion de memoria del inicio de la lista: " << lista << endl;
    cout << "Direccion de memoria del siguiente nodo: " << lista->siguiente << endl;
    cout << "Direccion de memoria del anterior nodo: " << lista->anterior << endl;
    cout << "Valor " << lista->datos.numero << endl;
    
    cout << "Direccion de memoria del segundo nodo: " << lista->siguiente << endl;
    cout << "Direccion de memoria del siguiente nodo: " << lista->siguiente->siguiente << endl;
    cout << "Direccion de memoria del anterior nodo: " << lista->siguiente->anterior << endl;
    cout << "Valor " << lista->siguiente->datos.numero << endl;


    return 0;
}
// Insertar un nodo al inicio de la lista
void InsertarInicio(struct Nodo **lista, int n)
{
    struct Nodo *nuevo_nodo = new Nodo(); // Reserva de memoria para un nuevo nodo
    // Variable auxiliar que almacena el nodo actual
    nuevo_nodo->datos.numero = n;
    nuevo_nodo->anterior = nullptr;
    nuevo_nodo->siguiente = nullptr; // El siguiente del nuevo nodo apunta a null

    // Si la lista esta vacia se agrega el primero nodo
    if (*lista == nullptr)
    {
        *lista = nuevo_nodo; // El inicio de la lista apunta al nuevo nodo
    }
    else
    {
        nuevo_nodo->siguiente = *lista; // El siguiente del nuevo nodo apunta al inicio de la lista
        (*lista)->anterior = nuevo_nodo;
        *lista = nuevo_nodo; // El inicio de la lista apunta al nuevo nodo
    }
}

void InsertarFinal (struct Nodo **lista, int n)
{
    struct Nodo *nuevo_nodo = new Nodo(); // Reserva de memoria para un nuevo nodo
    nuevo_nodo->datos.numero = n;
    nuevo_nodo->siguiente = nullptr; // El siguiente del nuevo nodo apunta a null
    nuevo_nodo->anterior = nullptr;

    struct Nodo *temporal = *lista; // Variable auxiliar que almacena el nodo actual
    if (*lista == nullptr) 
    {
        *lista = nuevo_nodo; // Si la lista esta vacia, el inicio de la lista apunta al nuevo nodo
    } 
    else 
    {
        Nodo *temporal = *lista;
        while (temporal->siguiente != nullptr) // Mientras el siguiente del nodo actual no sea null
        {
            temporal = temporal->siguiente; // El nodo actual apunta al siguiente nodo
        }
        temporal->siguiente = nuevo_nodo; // El siguiente del ultimo nodo apunta al nuevo nodo
        nuevo_nodo->anterior = temporal;
    }
}

void EliminarNodoValor (struct Nodo **lista, int n){
    //tengo que terminarlo
}