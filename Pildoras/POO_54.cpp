#include <iostream>
using namespace std;

//Definición de clases. Van fuera del programa. 
class Coche {
    // atributos o propiedades. Que características tiene este objeto
    string  modelo;
    string  color;
    int     cilindrada;
    int     potencia;
    double  precio;

    // Métoods o comportamientos. Como se comporta el coche. 
    void arrancar (){
    cout << "El coche está arrancado." << endl;
    }
    void acelerar (){
    cout << "El coche está acelerando." << endl;
    }
    void frenar (){
    cout << "El coche está frenando." << endl;
    }
    void girar (){
    cout << "El coche está girando." << endl;
    }
    bool en_marcha (){
        return true;
    }
};


int main (){




    return 0;
}
