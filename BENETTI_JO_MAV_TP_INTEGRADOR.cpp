// BENETTI_JO_MAVI_TP_INTEGRADOR.cpp: define el punto de entrada de la aplicación.


#include "stdafx.h"
#include "Juego.h"

using namespace sf;

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	Juego GangBenetti;
	GangBenetti.Loop();
	return 0;
};


