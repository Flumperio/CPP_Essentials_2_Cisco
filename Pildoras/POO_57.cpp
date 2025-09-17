#include <iostream>
using namespace std;

class MiClase {

    //Exsiste un metodo para heredar los private y es protected, que se pasan los private pero solo a las clades derivadas. 
    protected: 
    int edad; //Miembro Público
    
    public:
    void set_Valor (int nueva_edad){
        if (nueva_edad < 0 || nueva_edad > 100){
            cout << "Esta edad no puede ser." << endl;
            edad = 0;
        } else {
            edad = nueva_edad;
        }
    }
    void get_Valor () {
        cout << "Valor de la edad es: " << edad << endl;
    }
};

class claseDerivada:public MiClase {
    
    public:
    void imprimir_valor(){
        cout << "Este es el valor de la clase derivada: " << edad << endl;
    }
};

int main () {
    MiClase         obj;
    claseDerivada   new_obj;
    //puntero a obj;
    MiClase *ptr_obj = &obj;
    obj.set_Valor(35);
    obj.get_Valor();
    obj.set_Valor(36);
    obj.get_Valor();
    new_obj.set_Valor(99);
    new_obj.imprimir_valor();
    new_obj.get_Valor();
}
