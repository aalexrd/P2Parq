#pragma once
#ifndef Auto_H
#define Auto_H
#include <iostream>
#include "Persona.h"
using namespace std;

class Automovil
{
	string placa;
	string modelo;
	string marca;
	Persona dueno;
	string fecha;
	string hora;
	bool ocupado;
	struct tm horaDif;//donde se guarda la estructura de tiempo
public:
	Automovil();
	Automovil(string placa, string modelo, string marca);
	string getPlaca() const;
	void setPlaca(const string& placa);
	string getModelo() const;
	void setModelo(const string& modelo);
	string getMarca() const;
	void setMarca(const string& marca);
	Persona& getDueno();
	void setDueno(const Persona& dueno);
	string getFecha() const;
	void setFecha(const string& fecha);
	string getHora() const;
	void setHora(const string& hora);
	tm& getHoraDif();
	void setHoraDif(const tm& hora_dif);
	bool getOcupado() const;
	void setOcupado(bool ocupado);
	void imprimir() const;
	void limpiar();
};
#endif

