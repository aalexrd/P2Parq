#include "Principal.h"

Principal::Principal()
{
}

void Principal::menu()
{
	parqueo.restaura();
vuelve://retorno al principio
	system("cls");
	system("Color F6");
	cout << "1) Auto entra\n"
		<< "2) Auto sale\n"
		<< "3) Salir\n"
		<< "Digite el n\243mero de la opci\242n deseada:\n";
	switch (readInt())
	{
	case 1:
		parqueo.autoEntra();
		goto vuelve;
	case 2:
		parqueo.autoSale();
		goto vuelve;
	case 3:
		parqueo.respalda();
		exit(0);
	default:
		system("cls");
		cout << "\nNo esta esa opcion intente de nuevo\n";
		system("pause");
		goto vuelve;
	}
}

int Principal::readInt()
{
	string i;
	getline(cin, i);
k:
	for (int k = 0; k < strlen(i.c_str()); k++) {
		if (isdigit(i[k]) == false)
		{
			cout << "Digite lo que se le solicit\242, intente de nuevo\n";
			getline(cin, i);
			goto k;
		}
	}
	return atoi(i.c_str());
}

