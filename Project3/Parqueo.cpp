#include "Parqueo.h"

Parqueo::Parqueo()
{
}

Parqueo::Parqueo(string id) : id(id)
{
}

string Parqueo::getId() const
{
	return id;
}

void Parqueo::setId(const string& id)
{
	this->id = id;
}

Automovil& Parqueo::getLote(int k)
{
	return lote[k];
}

void Parqueo::setLote(Automovil lote[25])
{
	this->lote[25] = lote[25];
}

void Parqueo::autoEntra()
{
	system("cls");
	int k = 0;
	if (lote[24].getOcupado() == true)//si no hay espacio
	{
		cout << "No hay espacio\n";
		return;
	}
	while (lote[k].getOcupado() == true && k < 25)//encontrar espacio
	{
		k++;
	}
	cout << "Digite el nombre y apellidos del due\244o:\n";//el \244 es una ñ en ascii
	lote[k].getDueno().setNombre(readString());
	cout << "Digite el numero de c\202dula:\n";//el \202 es una é
	lote[k].getDueno().setCedula(readString());
	cout << "Digite el numero de placa del auto:\n";
	lote[k].setPlaca(readString());
	cout << "Digite la fecha de entrada (si desea hacerlo automatico pulse 1 si no pulse cualquier otro n\243mero):\n";
	if (readInt() == 1)
		lote[k].setFecha(fecha(k));
	else
		fechaManual(k);
	cout << "Digite la hora de entrada (si desea hacerlo automatico pulse 1 si no pulse cualquier otro n\243mero):\n";
	if (readInt() == 1)
		lote[k].setHora(hora(k));
	else
		horaManual(k);
	system("cls");
	cout << "Esta es la informacion agregada: \n";
	lote[k].imprimir();
	lote[k].setOcupado(1);
	system("pause");
}

void Parqueo::autoSale()
{
	system("cls");
	cout << "Digite la placa del auto:\n";
	int k = buscarAuto(readString());
	if (k == 25)
	{
		cout << "\nEl carro no se encuentra en el lote\n";
		system("pause");
		return;
	}
	cout << "\nEsta es la informacion de este auto: \n";
	lote[k].imprimir();
	system("pause");
	cout << "Este es el monto que deber\240 pagar: " << pago(lote[k].getHoraDif()) << " Colones.\n";
	system("pause");
	lote[k].limpiar();
	ordenar();
}

double Parqueo::pago(tm tiempo)
{
	time_t ahora;
	time(&ahora);
	double minutos = difftime(ahora, mktime(&tiempo)) / 60;
	return minutos * (700 / 60); //cobrar por minutos, si son 60 minutos son 700 colones
}

void Parqueo::fechaManual(int k)
{
	cout << "\nDigite el a\244o de entrada:\n";
	lote[k].getHoraDif().tm_year = readInt()-1900;
	cout << "\nDigite el mes de entrada(1 a 12):\n";
	lote[k].getHoraDif().tm_mon = readInt() - 1;//0 a 11
	cout << "\nDigite el d\241a de entrada:\n";
	lote[k].getHoraDif().tm_mday = readInt();
	char buf[80];
	strftime(buf, sizeof(buf), "%F", &lote[k].getHoraDif());
	lote[k].setFecha(buf);
}

void Parqueo::horaManual(int k)
{
	cout << "\nDigite solo la hora de entrada(hora militar de 0 a 23):\n";
	lote[k].getHoraDif().tm_hour = readInt();
	cout << "\nDigite los minutos de la hora de entrada(0 a 59):\n";
	lote[k].getHoraDif().tm_min = readInt();
	lote[k].getHoraDif().tm_sec = 0;
	char buf[80];
	strftime(buf, sizeof(buf), "%r", &lote[k].getHoraDif());
	lote[k].setHora(buf);
}

void Parqueo::restaura()
{
	ifstream restaura;
	string line;
	int k = 0;
	string nombre = "parqueo";
	nombre += id;
	restaura.open(nombre);
	if (restaura.is_open())
	{
		while (!restaura.eof() && k < 25)
		{
			getline(restaura, line);//placa
			lote[k].setPlaca(line);
			/*getline(restaura, line);//modelo
			lote[k].setModelo(line);
			getline(restaura, line);//marca
			lote[k].setMarca(line);*/
			getline(restaura, line);//nombre dueño
			lote[k].getDueno().setNombre(line);
			getline(restaura, line);//cedula
			lote[k].getDueno().setCedula(line);
			getline(restaura, line);//fecha
			lote[k].setFecha(line);
			getline(restaura, line);//Hora
			lote[k].setHora(line);
			getline(restaura, line);//Ocupado
			lote[k].setOcupado(atoi(line.c_str()));
			getline(restaura, line);//Hora
			lote[k].getHoraDif().tm_hour = stoi(line);
			getline(restaura, line);//min
			lote[k].getHoraDif().tm_min = stoi(line);
			getline(restaura, line);//sec
			lote[k].getHoraDif().tm_sec = stoi(line);
			getline(restaura, line);//dia
			lote[k].getHoraDif().tm_mday = stoi(line);
			getline(restaura, line);//mes
			lote[k].getHoraDif().tm_mon = stoi(line);
			getline(restaura, line);//año
			lote[k].getHoraDif().tm_year = stoi(line);
			k++;
		}
	}
	restaura.close();
}

void Parqueo::respalda()
{
	ofstream respaldo;
	string nombre = "parqueo";
	nombre += id;
	respaldo.open(nombre); //abrir archivo
	if (respaldo.is_open())
	{
		int k = 0;
		while (k < 25 && lote[k].getOcupado() == true)
		{
			respaldo << lote[k].getPlaca() << "\n";
			/*respaldo << lote[k].getModelo() << "\n";
			respaldo << lote[k].getMarca() << "\n";*/
			respaldo << lote[k].getDueno().getNombre() << "\n";
			respaldo << lote[k].getDueno().getCedula() << "\n";
			respaldo << lote[k].getFecha() << "\n";
			respaldo << lote[k].getHora() << "\n";
			respaldo << lote[k].getOcupado() << "\n";
			respaldo << lote[k].getHoraDif().tm_hour << "\n";
			respaldo << lote[k].getHoraDif().tm_min << "\n";
			respaldo << lote[k].getHoraDif().tm_sec << "\n";
			respaldo << lote[k].getHoraDif().tm_mday << "\n";
			respaldo << lote[k].getHoraDif().tm_mon << "\n";
			respaldo << lote[k].getHoraDif().tm_year;
			if (lote[k + 1].getOcupado() == true)
			{
				respaldo << endl;
			}
			k++;
		}
	}
	else
		cout << "No se pudo crear o acceder al registro\n";
	respaldo.close();
}

int Parqueo::buscarAuto(string placa)
{
	for (int i = 0; i < 25 && lote[i].getOcupado() == true; i++)
	{
		if (lote[i].getPlaca() == placa)
			return i;
	}
	return 25;
}

string Parqueo::fecha(int k)
{ //automatico
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	localtime_s(&tstruct, &now);
	lote[k].setHoraDif(tstruct);
	strftime(buf, sizeof(buf), "%F", &tstruct);
	return buf;
}

string Parqueo::hora(int k)//automatico, como se llama primero a fecha esta ya crea la estructura con la hora
{
	char buf[80];
	strftime(buf, sizeof(buf), "%r", &lote[k].getHoraDif());
	return buf;
}

void Parqueo::ordenar()
{
	for (int i = 0; i < 25; i++)
		if (lote[i].getOcupado() == false)//encuentra cuales estan vacios al frente
			for (int k = i + 1; k < 25; k++)
				if (lote[k].getOcupado() == true)
				{//encuentra cual puede meter ahi
					lote[i] = lote[k];
					lote[k].limpiar();
					break;
				}
}

string Parqueo::readString()
{
	string i;
	getline(cin, i);
	return i;
}

int Parqueo::readInt()
{
	string i;
k:
	getline(cin, i);
	for (int k = 0; k < strlen(i.c_str()); k++)
	{
		if (isdigit(i[k]) == false)
		{
			cout << "Digite lo que se le solicit\242, intente de nuevo\n";
			goto k;
		}
	}
	return atoi(i.c_str());
}

