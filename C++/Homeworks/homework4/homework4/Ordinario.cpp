#pragma once
#include "Ordinario.h"


Ordinario::Ordinario(string titolare, int conto, int nmax, float tasso, int nop) : Conto(titolare, conto, nmax), tasso(0.2), nop(3)
{
	movimenti = new float[nmax];
}

float Ordinario::calcolaSpese()
{
	float spesa = 0.0F;
	for (int i = 0; i < nmov; i++)
	{
		if (movimenti[i] < 0)
			spesa += movimenti[i]+tasso;
	}

	return spesa;
}

