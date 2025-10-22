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
#include <cctype>
#include <limits>

using namespace std;

class Reporte {
private:
    int id_vuelo;
    int plazas_disponibles;
    int plazas_reservadas;
    int plazas_overbooking;

    static constexpr double FACTOR_OVERBOOKING = 1.05; // 105%

public:
    // Constructor
    Reporte(int id, int disponibles, int reservadas)
        : id_vuelo(id),
          plazas_disponibles(disponibles > 0 ? disponibles : 0),
          plazas_reservadas(reservadas >= 0 ? reservadas : 0),
          plazas_overbooking(static_cast<int>(disponibles * FACTOR_OVERBOOKING))
    {
        if (plazas_reservadas > plazas_overbooking)
            plazas_reservadas = plazas_overbooking;
    }

    // Mostrar el estado actual del vuelo
    void imprimir_estado() const {
        cout << "\nNúmero de vuelo: " << id_vuelo << endl;
        cout << "Reservas: " << plazas_reservadas << " / " << plazas_disponibles
             << " (" << (plazas_reservadas * 100 / plazas_disponibles)
             << "% ocupación)" << endl;
    }

    // Añadir plazas
    bool add_plazas(int cantidad) {
        if (plazas_reservadas + cantidad > plazas_overbooking) {
            cout << "No se puede realizar la operación (supera el límite de overbooking)\n";
            return false;
        }
        plazas_reservadas += cantidad;
        return true;
    }

    // Cancelar plazas
    bool cancel_plazas(int cantidad) {
        if (plazas_reservadas - cantidad < 0) {
            cout << "No se puede realizar la operación (reservas negativas)\n";
            return false;
        }
        plazas_reservadas -= cantidad;
        return true;
    }
};

// --- Funciones auxiliares ---

// Pasa una cadena a minúsculas
void str_lower(string &texto) {
    for (char &c : texto)
        c = tolower(c);
}

// Analiza el comando del usuario
bool procesar_entrada(const string &entrada, string &accion, int &cantidad) {
    string texto = entrada;
    str_lower(texto);

    // Si el usuario quiere salir
    if (texto == "quit") {
        accion = "quit";
        return true;
    }

    size_t espacio = texto.find(' ');
    if (espacio == string::npos) return false;

    accion = texto.substr(0, espacio);
    string parte_numerica = texto.substr(espacio + 1);

    if (parte_numerica.empty()) return false;

    // Verificamos que sea un número
    for (char c : parte_numerica)
        if (!isdigit(c)) return false;

    cantidad = stoi(parte_numerica);
    if (accion != "add" && accion != "cancel") return false;

    return true;
}

// Control de operaciones
void modificar_datos(Reporte &vuelo) {
    string entrada, accion;
    int cantidad = 0;

    while (true) {
        cout << "\n¿Qué quieres hacer? (add N / cancel N / quit): ";
        getline(cin, entrada);

        if (!procesar_entrada(entrada, accion, cantidad)) {
            cout << "Comando no válido. Intenta de nuevo.\n";
            continue;
        }

        if (accion == "quit")
            break;
        else if (accion == "add") {
            if (vuelo.add_plazas(cantidad))
                vuelo.imprimir_estado();
        } else if (accion == "cancel") {
            if (vuelo.cancel_plazas(cantidad))
                vuelo.imprimir_estado();
        }
    }
}

// --- Función principal ---

int main() {
    int id = 1;
    int disponibles = 0;
    int reservadas = 0;

    cout << "Introduce el número de plazas disponibles: ";
    while (!(cin >> disponibles) || disponibles <= 0) {
        cout << "Valor no válido. Introduce un número positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Introduce el número de reservas: ";
    while (!(cin >> reservadas) || reservadas < 0) {
        cout << "Valor no válido. Introduce un número positivo o cero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

    Reporte vuelo(id, disponibles, reservadas);
    vuelo.imprimir_estado();

    modificar_datos(vuelo);

    cout << "\nPrograma finalizado.\n";
    return 0;
}
