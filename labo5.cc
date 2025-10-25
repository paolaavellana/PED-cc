#include <iostream>
#include <string>
#include <queue>

using namespace std;
struct Persona
{
    string nombre;
    int numeroAsiento;
    string categoria;
   
};

queue<Persona> cola;
int contadorAsientos = 1;

void mostrarMenu()
{
    cout << "1. Agregar persona a la cola" << endl;
    cout << "2. Mostrar cola" << endl;
    cout << "3. Iniciar Viaje" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}  

void agregarPersona() {
    Persona p;
    cout << "Ingrese el nombre: ";
    cin >> p.nombre;
    cout << "Ingrese la categoria (adulto, nino u otros): ";
    cin >> p.categoria;
    p.numeroAsiento = contadorAsientos++;
    cola.push(p);
    cout << "Persona agregada con asiento #" << p.numeroAsiento << endl;
}

void mostrarCola()
{
    if (cola.empty())
    {
        cout << "La cola esta vacia." << endl;
        return;
    }
    queue<Persona> copiaCola = cola;
    cout << "Cola de personas:" << endl;
    while (!copiaCola.empty())
    {
        Persona p = copiaCola.front();
        cout << "Nombre: " << p.nombre << ", Asiento: " << p.numeroAsiento << ", Categoria: " << p.categoria << endl;
        copiaCola.pop();
    }
}

void iniciarViaje() {
    if (cola.empty()) {
        cout << "\n No hay personas en la cola para iniciar el viaje.\n";
        return;
    }

    cout << "\n Iniciando viaje con hasta 5 personas...\n";

    int contador = 0;
    while (!cola.empty() && contador < 5) {
        Persona p = cola.front();
        cola.pop();
        cout << " Subio al viaje -> "
             << "Asiento #" << p.numeroAsiento
             << " | Nombre: " << p.nombre
             << " | Categoria: " << p.categoria << endl;
        contador++;
    }

    if (contador < 5)
        cout << " Solo " << contador << " personas subieron esta vez.\n";
    else
        cout << " Viaje completo con 5 personas.\n";
}

int main()
{
    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarPersona();
            break;
        case 2:
            mostrarCola();
            break;
        case 3:
            iniciarViaje();
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
    return 0;
}