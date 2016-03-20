#include "Automovil.h"

Automovil::Automovil()
{
	placa = string();
	modelo = string();
	marca = string();
	fecha = string();
	hora = string();
	ocupado = 0;
}

Automovil::Automovil(string placa, string modelo, string marca): placa(placa), modelo(modelo), marca(marca), ocupado(true)
{
}

string Automovil::getPlaca() const
{
	return placa;
}

void Automovil::setPlaca(const string& placa)
{
	this->placa = placa;
}

string Automovil::getModelo() const
{
	return modelo;
}

void Automovil::setModelo(const string& modelo)
{
	this->modelo = modelo;
}

string Automovil::getMarca() const
{
	return marca;
}

void Automovil::setMarca(const string& marca)
{
	this->marca = marca;
}

Persona& Automovil::getDueno()
{
	return dueno;
}

void Automovil::setDueno(const Persona& dueno)
{
	this->dueno = dueno;
}

string Automovil::getFecha() const
{
	return fecha;
}

void Automovil::setFecha(const string& fecha)
{
	this->fecha = fecha;
}

string Automovil::getHora() const
{
	return hora;
}

void Automovil::setHora(const string& hora)
{
	this->hora = hora;
}

tm& Automovil::getHoraDif()
{
	return horaDif;
}

void Automovil::setHoraDif(const tm& hora_dif)
{
	horaDif = hora_dif;
}

bool Automovil::getOcupado() const
{
	return ocupado;
}

void Automovil::setOcupado(bool ocupado)
{
	this->ocupado = ocupado;
}

void Automovil::imprimir() const
{
	cout << " Placa: " << placa << endl
		/*<< " Modelo: " << modelo << endl
		<< " Marca: " << marca << endl*/
		<< " Nombre del due\244o: " << dueno.getNombre() << endl
		<< " C\202dula: " << dueno.getCedula() << endl
		<< " Fecha: " << fecha << endl
		<< " Hora: " << hora << endl;
}

void Automovil::limpiar()
{
	placa = string();
	modelo = string();
	marca = string();
	fecha = string();
	hora = string();
	ocupado = 0;
}

