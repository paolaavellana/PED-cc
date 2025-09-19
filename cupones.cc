#include <iostream>
#include <string>
#include <vector>
#include <utility>  // para std::pair
#include <cstdlib>  // rand()
#include <ctime>    // time()

// -------------------------------
// Estructuras
// -------------------------------

// Información básica de la persona
struct InformacionPersona {
    std::string nombre_persona;
};

// Información de los cupones que tiene una persona
struct InformacionCupon {
    int cant_cupones; // cuántos cupones pidió
    std::vector<std::pair<std::string, std::string>> cupon_premio; 
    // vector de pares {cupón, premio}

    struct InformacionPersona inf_persona; // vínculo con la persona
};

// Vector global que guarda todos los clientes y sus cupones
std::vector<struct InformacionCupon> vector_cupones;

// -------------------------------
// Declaración de funciones
// -------------------------------
struct InformacionCupon SolicitarDatosGenerales();
std::string SolicitarDatos();
std::string GenerarCupon(std::string prefijo);
std::string AsignarPremio(std::string identificador_cupon);
void ImprimirCupones(std::vector<struct InformacionCupon> cupon);

// -------------------------------
// Main
// -------------------------------
int main() {
    char opcion;

    do {
        srand(time(0)); // semilla para los números aleatorios

        // Crear y llenar un cupón de una persona
        struct InformacionCupon cupon;
        cupon = SolicitarDatosGenerales();

        // Guardarlo en el vector global
        vector_cupones.push_back(cupon);

        // Mostrar todos los cupones hasta ahora
        ImprimirCupones(vector_cupones);

        std::cout << "Desea continuar? (s/n): ";
        std::cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    std::cout << "Programa finalizado.\n";
    return 0;
}

// -------------------------------
// Implementación de funciones
// -------------------------------

// Pide datos de la persona y genera sus cupones
struct InformacionCupon SolicitarDatosGenerales() {
    struct InformacionCupon cupon;

    std::cout << "Ingresa el nombre de la persona: ";
    std::cin >> cupon.inf_persona.nombre_persona;

    std::cout << "Ingresa la cantidad de cupones a generar: ";
    std::cin >> cupon.cant_cupones;

    for (int i = 0; i < cupon.cant_cupones; i++) {
        std::string cupon_generado = GenerarCupon(SolicitarDatos());
        std::string premio = AsignarPremio(cupon_generado);

        // Guardar en el vector de pares {cupón, premio}
        cupon.cupon_premio.push_back({cupon_generado, premio});
    }

    return cupon;
}

// Pide prefijo de 3 letras
std::string SolicitarDatos() {
    std::string prefijo;
    do {
        std::cout << "Ingresa el prefijo del cupon (3 letras maximo): ";
        std::cin >> prefijo;

        if (prefijo.length() == 3) {
            return prefijo;
        } else {
            std::cout << "Error. El prefijo debe ser de 3 letras.\n";
        }
    } while (true);
}

// Genera el cupón combinando prefijo + número aleatorio
std::string GenerarCupon(std::string prefijo) {
    int numero_aleatorio = rand() % 900 + 100; // entre 100 y 999
    std::string conversion = std::to_string(numero_aleatorio);
    return prefijo + conversion; // ejemplo: "ABC123"
}

// Determina si tiene premio o no
std::string AsignarPremio(std::string identificador_cupon) {
    std::string mensaje;
    identificador_cupon = identificador_cupon.substr(3, 3); // tomar solo los números
    int conversion_entero = std::stoi(identificador_cupon);

    if (conversion_entero % 2 == 0) {
        mensaje = "Tiene premio";
    } else {
        mensaje = "No tiene premio";
    }

    return mensaje;
}

// Imprime todo lo que hay en el vector global
void ImprimirCupones(std::vector<struct InformacionCupon> cupon) {
    for (auto c : vector_cupones) {
        std::cout << "\n-Imprimiendo registros de cupones-\n";
        std::cout << "Nombre: " << c.inf_persona.nombre_persona << "\n";
        std::cout << "Cantidad de cupones: " << c.cant_cupones << "\n";

        for (auto cp : c.cupon_premio) {
            std::cout << "Cupon: " << cp.first << " - " << cp.second << "\n";
        }
    }
}