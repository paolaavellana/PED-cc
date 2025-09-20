#include <iostream>
#include <vector> 
#include <string.h> 
using namespace std;

// Estructura para guardar información de un producto
struct Producto {
    int id;
    string nombre;
    int cantidad;
    float precio;
};
vector<Producto> producto;// Vector global que almacena todos los productos en el inventario

Producto RequestData();// Función para ingresar datos de un producto
void PrintData(vector<Producto> productos_registrados);// Función para mostrar la información
void AddProductToInventory();// Función para agregar un producto al inventario
void FindID(vector<Producto> productos_registrados, int id);// Función para buscar un producto por su ID
void UpdateStock(vector<Producto> productos_registrados, int id, int cantidad);// Función para actualizar la cantidad en stock de un producto
void CalculateTotalStockValue(vector<Producto> productos_registrados);// Función para calcular el valor total del inventario

int main(){
    int choice, id, cantidad;
    do {
        cout << "\n--- GESTION DE INVENTARIO ---\n";
        cout << "1. Agregar producto al inventario\n";
        cout << "2. Mostrar todos los productos\n";
        cout << "3. Buscar producto por ID\n";
        cout << "4. Actualizar cantidad en stock\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "6. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> choice;

        switch(choice) {
            case 1:
                AddProductToInventory();
                break;
            case 2:
                PrintData(producto);
                break;
            case 3:
                cout << "Ingrese el ID del producto a buscar: ";
                cin >> id;
                FindID(producto, id);
                break;
            case 4:
                cout << "Ingrese el ID del producto a actualizar: ";
                cin >> id;
                cout << "Ingrese la nueva cantidad en stock: ";
                cin >> cantidad;
                UpdateStock(producto, id, cantidad);
                break;
            case 5:
                CalculateTotalStockValue(producto);
                break;
            case 6:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while(choice != 6);

return 0;
}
// Función que pide información de un producto
Producto RequestData(){
    Producto prod;// se crea un producto vacío
    cout << "--- INGRESAR INFORMACION DEL PRODUCTO ---\n" ;

    cout << "ID del producto: ";
    cin >> prod.id;
    cin.ignore();
    cout << "Nombre del producto: ";
    getline(cin, prod.nombre);// Usamos getline para permitir nombres con espacios
    cout << "Cantidad en stock: ";
    cin >> prod.cantidad;
    cout << "Precio por unidad: ";
    cin >> prod.precio;

    cout << "Informacion guardada exitosamente!\n";
    return prod; 
}
// Función que muestra la información almacenada
void PrintData(vector<Producto> productos_registrados){
    cout << "--- PRODUCTOS EN INVENTARIO --- " << "\n";

    for(auto prod: productos_registrados){// Recorremos todos los productos guardados en el vector global
        cout << "ID: " << prod.id << "\n";
        cout << "Nombre: "<< prod.nombre << "\n";
        cout << "Cantidad en stock: "<< prod.cantidad << "\n";
        cout << "Precio por unidad: "<< prod.precio << "\n\n";
    }
}
// Función para agregar un producto al inventario
void AddProductToInventory(){
    Producto prod = RequestData();
    producto.push_back(prod); // Guardarlo en el vector global
    cout << "Producto agregado al inventario.\n";
}
// Función para buscar un producto por su ID
void FindID(vector<Producto> productos_registrados, int id){    
    bool found = false;// Variable para verificar si se encontró el producto
    cout << "--- BUSCAR PRODUCTO POR ID ---\n";
    for(auto prod: productos_registrados){
        if(prod.id == id){// Si el ID coincide, mostramos la información del producto
            cout << "Producto encontrado:\n";
            cout << "ID: " << prod.id << "\n";
            cout << "Nombre: "<< prod.nombre << "\n";
            cout << "Cantidad en stock: "<< prod.cantidad << "\n";
            cout << "Precio por unidad: "<< prod.precio << "\n\n";
            found = true;
            break;
        }
    }
    if(!found){// Si no se encontró el producto, mostramos un mensaje
        cout << "Producto con ID " << id << " no encontrado.\n";
    }
}
// Función para actualizar la cantidad en stock de un producto
void UpdateStock(vector<Producto> productos_registrados, int id, int cantidad){
    bool found = false;// Variable para verificar si se encontró el producto
    cout << "--- ACTUALIZAR CANTIDAD EN STOCK ---\n";
    for(auto &prod: productos_registrados){// Usamos & como referencia para modificar el producto directamente en el vector
        if(prod.id == id){// Si el ID coincide, actualizamos la cantidad
            prod.cantidad = cantidad;
            cout << "Cantidad actualizada. Nuevo stock de " << prod.nombre << ": " << prod.cantidad << "\n";
            found = true;
            break;
        }
    }
    if(!found){// Si no se encontró el producto, mostramos un mensaje
        cout << "Producto con ID " << id << " no encontrado.\n";
    }
}
// Función para calcular el valor total del inventario
void CalculateTotalStockValue(vector<Producto> productos_registrados){
    float total_value = 0.0;// Variable para acumular el valor total
    cout << "--- VALOR TOTAL DEL INVENTARIO ---\n";
    for(auto prod: productos_registrados){// Recorremos todos los productos
        total_value += prod.cantidad * prod.precio; // Valor total = cantidad * precio por unidad
    }
    cout << "El valor total del inventario es: $" << total_value << "\n";
}