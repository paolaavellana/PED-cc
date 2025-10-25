#include <iostream>
#include <string>
using namespace std;

struct Movimiento {// Nodo para la lista doblemente enlazada
    int id;
    char tipo;
    double monto;
    double saldo;
    Movimiento* prev;// Puntero al nodo anterior
    Movimiento* next;// Puntero al nodo siguiente
};

Movimiento* head = nullptr;// Puntero al inicio de la lista
Movimiento* tail = nullptr;// Punteros al inicio y fin de la lista
double saldoActual = 0;

void recalcularSaldo(){ 
    double saldo = 0;
    Movimiento *temp = head;
    while (temp){
        if (temp->tipo == 'D'){
            saldo += temp->monto;
        }
        else if (temp->tipo == 'R'){
            saldo -= temp->monto;
        }
        temp->saldo = saldo; // actualizar el saldo del nodo
        temp = temp->next;
    }
    saldoActual = saldo;
}

void agregarMovimiento(int id, char tipo, double monto) {
    Movimiento* nuevo = new Movimiento;// Crear un nuevo nodo
    nuevo->id = id;
    nuevo->tipo = tipo;
    nuevo->monto = monto;
    nuevo->next = nullptr;
    nuevo->prev = tail;// Enlazar con el nodo anterior
    if (!head) head = nuevo;// Si la lista está vacía, el nuevo nodo es la cabeza
    if (tail) tail->next = nuevo;// Enlazar el nodo anterior con el nuevo
    tail = nuevo;// Actualizar la cola de la lista
    recalcularSaldo();// Recalcular después de agregar
}

void mostrarMovimiento() {
    Movimiento* temp = head;// Recorrer la lista desde la cabeza
    while (temp) {
        cout << "ID: " << temp->id << " Tipo: " << temp->tipo 
             << " Monto: " << temp->monto 
             << " Saldo: " << temp->saldo << endl;
        temp = temp->next;
    }
}

void eliminarMovimiento(int id){
    Movimiento* actual = head;

    while (actual != nullptr && actual->id != id) {
        actual = actual->next; 
    }

    if (actual == nullptr) {
        cout << "Movimiento con ID " << id << " no encontrado.\n";
        return;
    }

    if (actual->prev != nullptr) {
        actual->prev->next = actual->next;
    } else {
        head = actual->next;
    }

    if (actual->next != nullptr) {
        actual->next->prev = actual->prev;
    } else {
        tail = actual->prev; // actualizar si se borra el último
    }

    delete actual;

    cout << "Movimiento con ID " << id << " eliminado.\n";
    recalcularSaldo();// Recalcular después de eliminar
}

void recalcularMovimiento(){
   double saldo = 0;
    Movimiento *temp = head;
    while (temp)
    {
        if (temp->tipo == 'D')
        {
            saldo += temp->monto;
        }
        else if (temp->tipo == 'R')
        {
            saldo -= temp->monto;
            temp->saldo = saldo;
            temp = temp->next;
        }
    }
    saldoActual = saldo;
}

int main (){
    int opcion;
    do {
        cout << "1. Agregar movimiento\n2. Mostrar movimientos\n3. Eliminar movimiento\n4. Salir\n";
        cin >> opcion;
        if (opcion == 1) {
            int id; char tipo; double monto;
            cout << "ID: "; cin >> id;
            cout << "Tipo (D/R): "; cin >> tipo;
            cout << "Monto: "; cin >> monto;
            agregarMovimiento(id, tipo, monto);
        } else if (opcion == 2) {
            mostrarMovimiento();
        } else if (opcion == 3) {
            int id;
            cout << "ID a eliminar: "; cin >> id;
            eliminarMovimiento(id);
        }
    } while (opcion != 4);
    return 0;
}