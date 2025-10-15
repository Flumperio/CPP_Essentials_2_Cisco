// *****************************************
// Created by jcsantos on 10/15/25.
// Curso Cisco: c++ Essentials 1
// 1.2.12   LAB   Flight booking system: part 1
// Scenario
// Now that you're a little more familiar with classes and objects, let's
// pretend we're working on an airline flight booking system.
// Our systems save an identification number, the capacity and the number of seats reserved
// for all flight bookings.
// Our first job will be to print out a status report about the percentage of capacity filled.
// The report should be in the form:
// "Flight [id] : [reserved]/[capacity] ([percentage]%) seats taken"
// For now, let's not limit the number of reserved seats. We'll work on that later.
// *****************************************
#include <iostream>
using namespace std;

class Reporte {
private:
    int     id_vuelo;
    int     plazas_disponibles;
    int     plazas_reservadas;

public:
    // El constructor lo podemos inicializar de dos maneras, en este caso recibe tres valores, y los incializamos,
    // en la declaración o en el cuerpo. Es más eficiente lo primero, si no hay que operar sobre los valores.
    Reporte(int int_vuelo, int int_disponibles, int int_reservadas): id_vuelo(int_vuelo) {
        this->plazas_disponibles = int_disponibles;
        this->plazas_reservadas = int_reservadas;
    }

    void    imprimir_estado(){
        cout << "Numero Vuelo: " << id_vuelo << endl
        << " " << plazas_reservadas << "/" << plazas_disponibles <<
        "(" << ((plazas_reservadas * 100) / plazas_disponibles ) << "%) asientos reservados" << endl;
    }
};

int main () {
    int     id = 1;
    int     disponibles = 0;
    int     reservadas = 0;
    cout << "Introduce el número de plazas disponibles: ";
    cin >> disponibles;
    cout << "Introduce el número de reservas: ";
    cin >> reservadas;
    Reporte Reporte_Vuelos(id, disponibles, reservadas);

    Reporte_Vuelos.imprimir_estado();
    return 0;
}
