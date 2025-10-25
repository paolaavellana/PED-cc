#include <iostream>
struct Datos
{
    int elemento;
};
struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
};

void Insertar(struct Nodo *&pila, int n);
void Eliminar(struct Nodo *&pila);
void Imprimir(struct Nodo *pila);
bool Vacia(struct Nodo *pila);
void UltimoElemento(struct Nodo *pila);

int main(int argc, char *argv[])
{
    struct Nodo *pila = nullptr;
    int valor;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingrese un valor ";
        std::cin >> valor;
        Insertar(pila, valor);
    }
    std::cout << "------------------" << std::endl;
    Imprimir(pila);
    std::cout << "------------------" << std::endl;
    UltimoElemento(pila);
    return 0;
}

void Insertar(struct Nodo *&pila, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

void Eliminar(struct Nodo *&pila)
{
    if (pila != nullptr)
    {
        struct Nodo *temporal = pila;
        pila = temporal->siguiente;
        delete temporal;
        temporal = nullptr;
    }
    else
    {
        std::cout << "Pila vacia\n";
    }
}

void Imprimir(struct Nodo *pila)
{
    struct Nodo *temporal = pila;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la pila " << temporal->datos.elemento
                  << " dir. memoria del nodo " << temporal
                  << " Dir memoria nodo sig " << temporal->siguiente << std::endl;

        temporal = temporal->siguiente;
    }
}

bool Vacia(struct Nodo *pila)
{
    if (pila == nullptr)
    {
        std::cout << "Pila vacia\n";
        return true;
    }
    else
    {
        std::cout << "Pila no vacia\n";
        return false;
    }
}

void UltimoElemento(struct Nodo *pila)
{
    if (pila != nullptr)
    {
        std::cout << "Elemento en la cima de la pila: " << pila->datos.elemento << std::endl;
    }
    else
    {
        std::cout << "Pila vacia\n";
    }
}
