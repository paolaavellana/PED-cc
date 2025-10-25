#include <iostream>
using namespace std;

struct Datos 
{
    int numero;
    string nombre;
};

struct Nodo
{
    struct Datos datos;//
    struct Nodo *siguiente;//
};
struct Nodo *inicio_lista = nullptr;// Puntero global que apunta al inicio de la lista
void InsertarInicio (int n);
void Imprimir ();
void InsertarFinal (int n);
void EliminarInicio ();
void EliminarFinal ();

int main(){ 
    InsertarFinal (89);
    InsertarInicio(40);
    InsertarInicio(80);
    InsertarInicio(100);
    EliminarInicio();
    Imprimir();
    /* cout << "Direccion de memoria del inicio de la lista: " << inicio_lista << endl;
    cout << "Valor del primer nodo: " << inicio_lista->datos.numero << endl;
    cout << "Direccion de memoria del inicio de la lista: " << inicio_lista->siguiente->siguiente << endl;
    cout << "Valor del tercer nodo: " << inicio_lista->siguiente->siguiente->datos.numero << endl;
   */

return 0;
}

void InsertarInicio (int n)
{
    struct Nodo *nuevo_nodo = new Nodo();// Reserva de memoria para un nuevo nodo 
    //Variable auxiliar que almacena el nodo actual
    nuevo_nodo->datos.numero = n;
    nuevo_nodo->siguiente = nullptr;// El siguiente del nuevo nodo apunta a null

    //Si la lista esta vacia se agrega el primero nodo 
    if (inicio_lista == nullptr) 
    {
        inicio_lista = nuevo_nodo;// El inicio de la lista apunta al nuevo nodo
    } 
    else 
    {
        nuevo_nodo->siguiente = inicio_lista; // El siguiente del nuevo nodo apunta al inicio de la lista
        inicio_lista = nuevo_nodo; // El inicio de la lista apunta al nuevo nodo
    }
}

void Imprimir ()
{
    struct Nodo *temporal = inicio_lista; // Variable auxiliar que almacena el nodo actual
    if (inicio_lista != nullptr) 
    {
        while (temporal != nullptr) // Mientras el nodo actual no sea null
        {
            cout << "Valores de la lista " << temporal->datos.numero << endl; // Imprime el numero del nodo actual
            cout << "Direccion de memoria del nodo: " << temporal << endl; // Imprime la direccion de memoria del nodo actual
            cout << "Direccion de memoria del siguiente nodo: " << temporal->siguiente << endl; // Imprime la direccion de memoria del siguiente nodo
            temporal = temporal->siguiente; // El nodo actual apunta al siguiente nodo
        }
    } 
    else 
    {
        cout << "La lista esta vacia" << endl; // Si la lista esta vacia
    }
}

void InsertarFinal (int n)
{
    struct Nodo *nuevo_nodo = new Nodo(); // Reserva de memoria para un nuevo nodo
    nuevo_nodo->datos.numero = n;
    nuevo_nodo->siguiente = nullptr; // El siguiente del nuevo nodo apunta a null

    struct Nodo *temporal = inicio_lista; // Variable auxiliar que almacena el nodo actual
    if (inicio_lista == nullptr) 
    {
        inicio_lista = nuevo_nodo; // Si la lista esta vacia, el inicio de la lista apunta al nuevo nodo
    } 
    else 
    {
        while (temporal->siguiente != nullptr) // Mientras el siguiente del nodo actual no sea null
        {
            temporal = temporal->siguiente; // El nodo actual apunta al siguiente nodo
        }
        temporal->siguiente = nuevo_nodo; // El siguiente del ultimo nodo apunta al nuevo nodo
    }
}

void EliminarInicio ()
{
    struct Nodo *temporal = inicio_lista; // Variable auxiliar que almacena el nodo actual
    //Si en la lista se encuentran elementos
    if (inicio_lista != nullptr) // Si la lista no esta vacia
    {
        inicio_lista = temporal->siguiente; // El inicio de la lista apunta al siguiente nodo
        delete temporal; // Se libera la memoria del nodo eliminado
        temporal = nullptr; // Se asigna null al puntero temporal
    } 
    else 
    {
        cout << "La lista esta vacia" << endl; // Si la lista esta vacia
    }
}

void EliminarFinal ()
{
    struct Nodo *temporal = inicio_lista; // Variable auxiliar que almacena el nodo actual
    struct Nodo *anterior = nullptr; // Variable auxiliar que almacena el nodo anterior
    //Si en la lista se encuentran elementos
    if (inicio_lista != nullptr) // Si la lista no esta vacia
    {
        while (temporal->siguiente != nullptr) // Mientras el siguiente del nodo actual no sea null
        {
            anterior = temporal; // El nodo anterior apunta al nodo actual
            temporal = temporal->siguiente; // El nodo actual apunta al siguiente nodo
        }
        if (anterior != nullptr) // Si el nodo anterior no es null
        {
            anterior->siguiente = nullptr; // El siguiente del nodo anterior apunta a null
        } 
        else // si unicamente se encuentra un nodo en la lista
        {
            inicio_lista = nullptr; // Si el nodo anterior es null, el inicio de la lista apunta a null
        }
        delete temporal; // Se libera la memoria del nodo eliminado
        temporal = nullptr; // Se asigna null al puntero temporal
    } 
    else 
    {
        cout << "La lista esta vacia" << endl; // Si la lista esta vacia
    }
}