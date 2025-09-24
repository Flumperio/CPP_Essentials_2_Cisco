#include <iostream>
#include <string>

using namespace std;

class Square
{
// esta es la parte privada de la clase, se puede marcar como protectec para que tengan acceso las clases delegadas de esta. 
    private:
        double side;
        double area;
// definimos la parte pública con el constructor y los metodos de esta clase
    public:
        Square(double s): side(s){   // este es el constructor El nombre tiene que ser el mismo de la clase
        if (s < 0) {
            side = 0;
            area = 0;
        }
        else area = side * side;
        cout << "Ejecutamos el constructor y asignamos el valor de s(" << s << ") a side" << endl;
    } 
        void imp_resultado(){      // Esto es un método que es público para manejo de la clase
            cout << "El lado del cuadrado es de: " << side << " y su airea es de: " << area << endl;
    }
};

int main()
{
    Square s(4);

    
    s.imp_resultado();

    s = 2.0;
    s.imp_resultado();

    s = -33.0;
    s.imp_resultado();

    return 0;
}
