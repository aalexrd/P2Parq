#pragma once
#ifndef Principal_H
#define Principal_H
#include <string>
#include <iostream>
#include "Parqueo.h"
using namespace std;

class Principal
{
	Parqueo parqueo;
public:
	Principal();
	void menu();
	static int readInt();
};
#endif

