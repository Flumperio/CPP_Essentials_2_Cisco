#include <iostream>
using namespace std;

//Definición de clases. Van fuera del programa. 
class Coche {
    // atributos o propiedades. Que características tiene este objeto. Por norma general todos los atributos o
    // propiedades son private. Se pueden hacer publicos pero es una mala practica. Para establecer valores se usan los
    // metodos de acceso públicos setters y getters
    string  modelo;
    string  color;
    int     cilindrada;
    int     potencia;
    double  precio;

    // Métoods o comportamientos. Como se comporta el coche.
    // Al igual que los metodos también pueden ser públicos o privados, los setters y getters por lógica tienen que
    // ser publicos.
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
public:
    void set_Precio (double precio_nuevo) {
        if (precio_nuevo < 0) {
            precio = 15000;
        } else {
            precio = precio_nuevo;
        }
        //Gracias a que es una funcion podemos controlar el valor que se nos pasa para modificarlo, dar error
        // interrumpir el programa, etc. Por esto no se recomienda modiciar los atributos directamente.
    }
    double get_Precio () {
        return precio;
    }
};


int main (){
    Coche coche_Ana;
    Coche coche_Carlos;

    coche_Carlos.set_Precio(37000);
    cout << "El precio del coche de Carlos: " << coche_Carlos.get_Precio() << "€" << endl;

    // Otra opción generalmente para optimizar código y hacerlo más eficiente es usar punteros a objetos.
    // Creamos los punteros con * y leemos con &
    Coche *ptr_Coche_Ana = &coche_Ana;
    Coche *ptr_Coche_Carlos = &coche_Carlos;

    //En vez de usar el punto como separador de parámetros usarmos la flecha.
    ptr_Coche_Ana->set_Precio(76345.50);
    cout << "El precio del coche de Ana es de: " << ptr_Coche_Ana->get_Precio() << "€" << endl;

    return 0;
}
