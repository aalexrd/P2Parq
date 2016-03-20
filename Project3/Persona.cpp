#include "Persona.h"

Persona::Persona()
{
	nombre = string();;
	cedula = string();;
}

Persona::Persona(string nombre, string cedula): nombre(nombre), cedula(cedula)
{
}

string Persona::getNombre() const
{
	return nombre;
}

void Persona::setNombre(const string& nombre)
{
	this->nombre = nombre;
}

string Persona::getCedula() const
{
	return cedula;
}

void Persona::setCedula(const string& cedula)
{
	this->cedula = cedula;
}

