#include <iostream>
using namespace std;

class Persona{
    //Esto es un constructor, empieza con el nombre de la variable al ser un constructor, debería ser Public
    public: Persona (){
        cout << "Hola!, soy el constructor por defecto. He sido invocado" << endl;
    }
};

class Rectangulo{

    private:
        int     ancho;
        int     alto;
        string  nombre;

    // Sobrecarga de constructores. Cada constructor hace una cosa distinta dependiendo de la sobrecarga 
    // Tienen que llamarse igual.
    public:
        Rectangulo(string nom){
            ancho = 10;
            alto = 5;
            nombre = nom;
    }
        Rectangulo(int medida, string nom){
            ancho = medida;
            alto = medida * 2;
            nombre = nom;
    }
        Rectangulo (int anch, int alt, string nom){
            ancho = anch;
            alto = alt;
            nombre = nom;
    }
       ~Rectangulo(){
            cout << "Destructor invocado para el rectangulo: " << nombre << endl;
    }    
        void getRectangulo (){
            cout << "El rectangulo " << nombre << " tiene " << ancho << " cm de ancho, por " << alto << " cm de alto." << endl;
        }
};

int main (){

    Persona p1;

    Rectangulo r1("R1");
    r1.getRectangulo();
    Rectangulo r2 (12,"R2");
    r2.getRectangulo();
    Rectangulo r3 (12, 8, "R3");
    r3.getRectangulo();

    return 0;
}
