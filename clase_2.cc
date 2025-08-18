#include <iostream>
#include <string.h>
#include <ctime>   // Para time()


// Declaración de la funcion
std :: string Generar_cupon (std :: string letras, std :: string numeros);
void Asignar_premio (std :: string id_cupon);

int main(){

    std :: cout << "Bienvenido al generador de cupones\n";
    std :: string letras, numeros;
    std :: cout << "Ingrese las letras del cupon: \n"; 
    std :: cin >> letras; 

    std :: cout << "El cupon generado es: " 
                << Generar_cupon(letras, numeros) << "\n";
    
  
    Asignar_premio (id_cupon);
    
return 0;
}
// Definición de la función
std :: string Generar_cupon (std :: string letras, std :: string numeros) {

    // Generar números aleatorios
     srand(time(0)); // Inicializar la semilla para números aleatorios
    int numero_aleatorio = 100 + rand() % 900; // Genera un número aleatorio entre 100 y 999
    numeros = std :: to_string(numero_aleatorio); // Convertir el número a cadena
    std :: string cupon = letras + numeros; // Concatenar letras y números
    return cupon; // Retornar el cupón generado
}

// Extraer el número aleatorio y pasarlo de string a int
void Asignar_premio(std::string id_cupon) {
    // Extraer los últimos 3 caracteres (los números)
    std::string numeros = id_cupon.substr(3,4);

    // Convertir el string a int
    int numero = std::stoi(numeros);

    std::cout << "El número del cupón es: " << numero << "\n";
     // Decidir premio
    if (numero % 2 == 0) {
        std::cout << "¡Felicidades! Ganaste un premio: Descuento del 20%\n";
    } else if (numero % 5 == 0) {
        std::cout << "¡Suerte! Ganaste un premio: Producto gratis\n";
    } else {
        std::cout << "Lo sentimos, no hay premio esta vez.\n";
    }
}