// *****************************************
// Created by jcsantos on 10/15/25.
// Curso Cisco: c++ Essentials 1
// 1.2.12   LAB   Flight booking system: part 1
//
// Scenario
//
// Let's continue working on our booking system.
// You may remember in our last task that we had no limit on the number of reserved seats.
// Airlines often allow the overbooking of flights, expecting that some passengers will not make it.
// Modify the constructor so that it will not allow more than 105% reservation of the total capacity.
// Also for a negative number of reservations, set the number to 0.
// We might also want to be able to add new reservations or cancel them. Provide a way for the user to do this via a simple interface.
//     The command "add [n]" will try to add n reservations to the flight.
//     The command "cancel [n]" will try to cancel n reservations from the flight.
//     If an operation fails for any reason, the program will issue the message "Cannot perform this operation"
//     The command "quit" will stop execution of the program.
// Use the code from the previous lab as a starting point.
// *****************************************
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Reporte {
private:
    int                     id_vuelo;
    int                     plazas_disponibles;
    int                     plazas_reservadas;
    int                     plazas_overbooking;
    static constexpr double FACTOR_OVERBOOKING = 1.05; // 105%

public:
    // El constructor lo podemos inicializar de dos maneras, en este caso recibe tres valores, y los incializamos,
    // en la declaración o en el cuerpo. Es más eficiente lo primero, si no hay que operar sobre los valores.
    Reporte (){
        id_vuelo = 0;
        plazas_disponibles = 0;
        plazas_reservadas = 0;
        plazas_overbooking = 0;
    }
    Reporte(int int_vuelo, int int_disponibles, int int_reservadas):  
        id_vuelo(int_vuelo > 0 ? int_vuelo : 0),
        plazas_disponibles(int_disponibles > 0 ? int_disponibles : 0),
        plazas_reservadas(int_reservadas >= 0 ? int_reservadas : 0),
        plazas_overbooking(static_cast<int>(int_disponibles * FACTOR_OVERBOOKING))
    {
        if (plazas_reservadas > plazas_overbooking)
            plazas_reservadas = plazas_overbooking;
    }
    ~Reporte(){
        cout << "Destruido: " << id_vuelo << endl; 

    void    imprimir_estado(){
        cout << "Numero Vuelo: " << id_vuelo << endl
        << " " << plazas_reservadas << "/" << plazas_disponibles
        << "(" << ((plazas_reservadas * 100) / plazas_disponibles )
        << "%) asientos reservados" << endl;
    }
    int     show_id(){
        return id_vuelo;
    }

    bool    add_plazas(int cantidad){
        if (plazas_reservadas + cantidad > plazas_overbooking){
            cout << "No se puede realizar la operación" << endl;
            return false;
        }
        else{
            plazas_reservadas += cantidad;
            return true;
        }
    }
    bool    cancel_plazas(int cantidad){
        if (plazas_reservadas - cantidad < 0){
            cout << "No se puede realizar la operación" << endl;
            return false;
        }
        else{
            this->plazas_reservadas  -= cantidad;
            return true;
        }
    }
};
// --- Estructura de intercambio ---
struct  datos_vuelo {
    string  accion = "";
    int     vuelo = 0;
    int     cantidad = 0;
    int     cnt_vuelo = 0;
};


// --- Funciones auxiliares ---

// Pasa una cadena a minúsculas

void str_lower (string &texto){
    for (char &c : texto)
        c = tolower(c);
}

// Analiza el comando del usuario
bool verificar_entrada(string entrada, int& vuelo, string& accion, int& cantidad) {
    size_t  pos_espacio = 0;
    string  parte_numerica = "";
    if (entrada == "quit"){
        vuelo = 0;
        accion = "";
        cantidad = 0;
        return false;
    }
    str_lower(entrada);
    pos_espacio = entrada.find(' ');
    if (pos_espacio == string::npos)
        return true;
    accion = entrada.substr(0, pos_espacio);
    parte_numerica = entrada.substr(pos_espacio + 1);
    if (parte_numerica.empty() || parte_numerica.find_first_of("01234567890") == string::npos)
        return true;
    cantidad = stoi(parte_numerica);
    if (accion != "add" && accion != "cancel")
        return true;
    return false;
}

int entrada_datos(Reporte& vuelo){
    string  entrada_usuario;
    string  accion;
    int     cantidad;
    bool    comando_erroneo = false;
    do {
        cout << "Que quieres hacer ?: ";
        getline(cin, entrada_usuario);
        comando_erroneo = verificar_entrada(entrada_usuario, accion, cantidad);
        if (comando_erroneo)
            cout << "Error de comando. Usar add XX, cancel XX o quit." << endl;
        else if (accion == "add")
            comando_erroneo = vuelo.add_plazas(cantidad);
        else if (accion == "cancel")
            comando_erroneo = vuelo.cancel_plazas(cantidad);
        if (comando_erroneo)
            vuelo.imprimir_estado();
    } while (entrada_usuario != "quit");
    return cnt_vuelos;
}

int ft_split(string entrada){


}

int main (){
    datos_vuelo datos_vuelo; 
    Reporte* informacion_vuelos = nullptr;
    if (informacion_vuelos[datos_vuelo.cnt_vuelo].show_id() <= 0)
        cout << "No hay vuelos disponibles." << endl;
    cnt_vuelos = entrada_datos(informacion_vuelos[cnt_vuelos]);
    return 0;
}


// int main () {
//     int     id = 1;
//     int     disponibles = 0;
//     int     reservadas = 0;
//     cout << "Introduce el número de plazas disponibles: ";
//     cin >> disponibles;
//     cout << "Introduce el número de reservas: ";
//     cin >> reservadas;
//     cin.ignore();
//     Reporte Reporte_Vuelos(id, disponibles, reservadas);
//     Reporte_Vuelos.imprimir_estado();
//     entrada_datos(Reporte_Vuelos);
//     return 0;
