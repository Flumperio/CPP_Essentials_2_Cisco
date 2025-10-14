// *****************************************
// Created by jcsantos on 10/9/25.
// Curso Cisco: c++ Essentials 2
//          STACK
// *****************************************
#include <iostream>

using namespace std;

//Para esta prueba vamos a usar variables globales

int stack[100];
int SP = 0; 

// Push para poner un valor en el stack. SP es el Puntero, el número de valores que hay.
// Una vez introducido el valor sumamos 1 a SP
void push (int value) {
    stack[SP] = value;
    SP++;
}
// pop se usa para sacar un valor de stack. Una vez sacado restamos uno al valor de SP. 
int pop(void){
    return stack[--SP];
}

//Ahora vamos a crear una clase, para crearnos un stack con encapsulado y protegerlo.
//También podemos crear subclases para ir aumentando las funcionalidades. 

class Stack {
protected: // con esto marcamos todos los datos a partir de aqui privados. o protected. 
    int stackstore[100];
    int stackpointer; // stackpointer = SP
//Ahora creamos los metodos, que los marcamos como públicos para que tengan acceso todos.
//Los métodos se puede crear dentro o fuera de la clase. Es indiferente. Pongo las dos formas
public:
    //Vamos a crear un constructor que es como se incializa la clase siempre
    Stack(void) { 
        stackpointer = 0;
    }
    //Creamos los métodos
    void    push_stack( int value); //Lo definimos más adelante
    int     pop_stack (void) {
        return stackstore[--stackpointer];
    }
};

void Stack::push_stack(int value){
    stackstore[stackpointer] = value;
    stackpointer++;
}

//Vamos a crear una subclase que tenga un sumatorio del todo el stack.
//La herencia en las clases por defecto es privada, es decir todos los miembros se vuelven privados
//Para usarlos la tendrémos que importar como Public, que mantiene los permisos heredados.
// class AddingStack: public Stack {
class AddingStack:Stack{
private:
    int sum;
public:
    //Creamos el constructor de clase
    AddingStack(void) : Stack(){
        sum = 0;
    }
    void push_add_stack (int value){
        sum += value;
        Stack::push_stack(value);
    }
    int pop_add_stack (void){
        int val = Stack::pop_stack();
        sum -= val;
        return val;
    }
    int get_sum_add_stack (void){
        return sum;
    }
    void print_Stack (void){
        cout << stackpointer << " ---> " << stackstore[stackpointer - 1] << endl;
    }
};

int main () {
    push(3); // Pasamos el número 3
    push(2); // Pasamos el número 2
    push(1); // Pasamos el número 1
    cout << pop() << endl; // Sacamos el stack
    cout << pop() << endl;
    cout << pop() << endl;
    //Pruebas con la clase
    Stack little_stack, another_stack, funny_stack; //Creamos tres objetos de clase Stack
    little_stack.push_stack(1);
    another_stack.push_stack(little_stack.pop_stack() + 1);
    funny_stack.push_stack(another_stack.pop_stack() + 2);
    cout << funny_stack.pop_stack() << endl;
//Uso subclase
    cout << "---------------------------------------------------------" << endl;
    AddingStack super_stack;
    for (int cnt = 1; cnt < 10; cnt ++){
        super_stack.push_add_stack(cnt + 100);
        super_stack.print_Stack();
    }
    cout << super_stack.get_sum_add_stack() << endl;

    for (int cnt = 1; cnt < 10; cnt ++){
        super_stack.pop_add_stack();
    }
    cout << super_stack.get_sum_add_stack() << endl;
    return 0;
}
