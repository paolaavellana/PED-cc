#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct Informacion_Cantante {
    std::string nombre_persona;
    std::string nacionalidad;
};

struct Informacion_Cancion {
    std::string nombre_cancion;
    std::string duracion; 
};

struct Informacion_Album {
    std::string nombre_album;
    std::string lanzamiento; 
    std::vector<struct Informacion_Cancion> cancion;
}
std::vector<struct Informacion_Cancion> vector_canciones;

int main() {
   

return 0;    
}
struct Informacion_Album SolicitarDatos() {
    struct Informacion_Album album;

    std::cout << "Ingresa el nombre del album: ";
    std::cin >> nombre_album;
    std::cout << "Ingresa el año de lanzamiento: ";
    std::cin >> lanzamiento;

    return album;
}
