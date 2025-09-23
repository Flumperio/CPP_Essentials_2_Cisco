// *****************************************
// Created by Juan Carlos Santos on 18/9/25.
// Curso Cisco: c++ Essentials 1
// *****************************************
#include <iostream>
using namespace std;

class CuentaBancaria {

	public:
		string titular;
		double saldo;
	// La delegación evita la duplicidad de lineas

	CuentaBancaria (string tit): CuentaBancaria(tit, 0.0) {
		// se pueden poner parametros adicionales.
		cout << endl << "Hemos delegado el trabajo" << endl;
	}

	// CuentaBancaria(string tit): titular(tit), saldo(0.0) {
	// 	cout << "La cuenta para el cliente, " << titular << " con un saldo de: " << saldo << endl;
	// }
	CuentaBancaria(string tit, double sal): titular(tit), saldo(sal) {
		cout << "La cuenta para el cliente, " << titular << " con un saldo de: " << saldo << endl;
	}

	//Se pueden usar parámetros opcionales, la inicializacón de variable.
	// CuentaBancaria(string tit, bouble sal=0.0), con eso si no se pasa saldo es 0.0

};





int main () {
	CuentaBancaria cuenta1("Maria");
	CuentaBancaria cuenta2("Carlos", 99.50);
	return 0;
}