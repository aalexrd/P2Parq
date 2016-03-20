#pragma once
#ifndef Parqueo_H
#define Parqueo_H
#include <iostream>
#include <ctime>
#include <fstream>
#include "Automovil.h"
using namespace std;

class Parqueo
{
	string id;
	Automovil lote[25];
public:
	Parqueo();
	Parqueo(string id);
	string getId() const;
	void setId(const string& id);
	Automovil& getLote(int k);
	void setLote(Automovil lote[]);
	void autoEntra();
	void autoSale();
	static double pago(tm tiempo);
	void fechaManual(int k);
	void horaManual(int k);
	void restaura();
	void respalda();
	int buscarAuto(string placa);
	string fecha(int k);
	string hora(int k);
	void ordenar();
	static string readString();
	static int readInt();
};
#endif

