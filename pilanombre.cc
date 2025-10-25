#include <iostream>
#include <stack>  
using namespace std;

int main(){
char letra;

stack <int> pila; //creacion de la pila
for (int i=0; i<5; i++){
    std::cout << "Ingrese la letra "<< i+1 << " de su nombre: ";
    std::cin >> letra;
    pila.push(letra); //insertar elemento en la pila
    
}
while (!pila.empty()){
    cout << (char)pila.top() << endl; //muestra el elemento que esta en la cima de la pila
    pila.pop(); //elimina el elemento que esta en la cima de la pila
}

return 0;
}