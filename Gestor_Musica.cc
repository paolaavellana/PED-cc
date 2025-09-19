#include <iostream>   // Librería para entrada/salida (cout, cin)
#include <vector>     // Librería para usar vectores dinámicos (std::vector)
#include <string.h>   // Librería de strings (aunque aquí bastaba con <string>)

// ------------------ DEFINICIÓN DE ESTRUCTURAS ------------------

// Estructura para guardar información de un álbum
struct AlbumsInformation {
    std::string album_name;  // Nombre del álbum
    int release_year;        // Año en que se lanzó
    std::vector<std::pair<std::string, int>> songs; // Vector de canciones (nombre + número de canción)
    int album_age;           // Antigüedad del álbum (años desde el lanzamiento)
};

// Estructura para guardar información de un artista
struct artistInformation {
    std::string name;        // Nombre del artista
    std::string nationality; // Nacionalidad del artista
    std::vector<AlbumsInformation> discography; // Lista de sus álbumes
};

// ------------------ VARIABLES GLOBALES ------------------

std::vector<artistInformation> artist_inf;  
// Vector global que almacena todos los artistas y sus álbumes

// ------------------ PROTOTIPOS DE FUNCIONES ------------------
AlbumsInformation RequestData();  // Función para ingresar datos de un álbum
void PrintData(std::vector<AlbumsInformation> albums_registrated); // Función para mostrar la información
int CalculateAlbumAge(AlbumsInformation album); // Función que calcula la antigüedad del álbum
void AddAlbumToArtist(); // Función que agrega un álbum a un artista

// ------------------ FUNCIÓN PRINCIPAL ------------------

int main(){
    int choise; // variable para decidir si seguir o no
    std::vector<AlbumsInformation> albums_registrated; // <-- (este vector no se usa realmente)
    
    do {
        AddAlbumToArtist(); // Llamamos la función que pide datos del artista y álbum
        std::cout << "Si deseas continuar ingresa 1\n";
        std::cin >> choise; // el usuario decide si seguir
        std::cin.ignore();  // limpia el buffer del Enter
    } while(choise==1); // mientras elija 1, sigue pidiendo datos

    PrintData(albums_registrated); // Muestra toda la información guardada
    return 0;
}

// ------------------ DEFINICIÓN DE FUNCIONES ------------------

// Función que pide información de un álbum
AlbumsInformation RequestData() {
    AlbumsInformation album; // se crea un álbum vacío
    std::cout << "--- INGRESAR INFORMACION DEL ALBUM ---\n" ;
    int numero_de_canciones;

    // Guardamos nombre y año
    std::cout << "Nombre del album: ";
    std::getline(std::cin, album.album_name);
    std::cout << "Anio de lanzamiento: ";
    std::cin >> album.release_year;

    // Número de canciones
    std::cout << "Numero de canciones: ";
    std::cin >> numero_de_canciones;

    // Pedimos datos de cada canción
    std::cout << "\n--- INGRESAR INFORMACION DE CANCIONES ---\n" ;
    std::cin.ignore(); // limpiar buffer
    for(int i=0;i<numero_de_canciones;i++){
        std::string nombre_cancion;
        std::cout << "Cancion " << i+1 << ": ";
        std::getline(std::cin, nombre_cancion); 
        album.songs.push_back({nombre_cancion, i+1}); 
        // Guardamos canción en el vector del álbum
    }

    // Calculamos la antigüedad del álbum
    album.album_age = CalculateAlbumAge(album);

    std::cout << "Informacion guardada exitosamente!\n";
    return album; // devolvemos el álbum con sus datos completos
}

// Función que muestra la información almacenada
void PrintData(std::vector<AlbumsInformation> albums_registrated){
    std::cout << "--- ARTISTAS --- " << "\n";

    // Recorremos todos los artistas guardados en el vector global
    for(auto artist: artist_inf){
        std::cout << "Cantante: " << artist.name << "\n";
        std::cout << "Nacionalidad: "<< artist.nationality << "\n\n";

        // Recorremos todos los álbumes de ese artista
        for(auto album: artist.discography){
            std::cout << "Album: " << album.album_name << "\n";
            std::cout << "Anio de lanzamiento: " << album.release_year << "\n";
            std::cout << "Antiguedad: " << album.album_age << "\n";
            std::cout << "Canciones: \n";

            // Recorremos las canciones del álbum
            for(auto song: album.songs){
                std::cout << song.second << " - " << song.first << "\n";
                // song.second = número de canción
                // song.first = nombre de la canción
            }
            std::cout<<"\n";
        }
    }
}

// Función que calcula la antigüedad de un álbum
int CalculateAlbumAge(AlbumsInformation album) {
    return 2025 - album.release_year; // Año actual (2025) menos el de lanzamiento
}

// Función que agrega un álbum a un artista
void AddAlbumToArtist(){
    std::string artist_name, nacionality;
    std::cout << "\n--- INGRESAR INFORMACION DEL CANTANTE ---\n" ;

    // Pedimos datos del artista
    std::cout << "Nombre del cantante: ";
    std::getline(std::cin, artist_name);
    std::cout << "Nacionalidad del cantante: ";
    std::getline(std::cin, nacionality);

    bool found=false; // bandera para saber si el artista ya existe

    // Pedimos los datos del álbum con la función RequestData()
    AlbumsInformation album = RequestData(); 

    // Buscamos si el artista ya existe en el vector global
    for(auto &a: artist_inf){
        if(a.name==artist_name && a.nationality==nacionality){
            a.discography.push_back(album); // si existe, agregamos el álbum
            found=true;
            break;
        }
    }

    // Si no lo encontramos, creamos un nuevo artista y lo agregamos
    if(!found){
        artistInformation new_artist={artist_name, nacionality, {}}; // artista vacío
        new_artist.discography.push_back(album); // le agregamos el álbum
        artist_inf.push_back(new_artist); // guardamos en el vector global
    }
}
