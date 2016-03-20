#pragma once
#ifndef Persona_H
#define Persona_H
#include <string>
using namespace std;

class Persona
{
	string nombre;
	string cedula;
public:
	Persona();
	Persona(string nombre, string cedula);
	string getNombre() const;
	void setNombre(const string& nombre);
	string getCedula() const;
	void setCedula(const string& cedula);
};
#endif

