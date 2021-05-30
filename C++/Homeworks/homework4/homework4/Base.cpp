#include "Base.h"

Base::Base()
{
}


float Base::calcolaSpesa()
{
	float spesa = 0.0F;
	
	for (int i = 0; i < nmov; i++) {
		if (movimenti[i] < 0) {

			if (franchigia) {
				if (freeop < 90321)	//Con franchigia + freeop
					spesa += movimenti[i] + canone;	//freeop
				else 
					spesa += movimenti[i] + tasso + canone; //No freeop 
			}
			else
				spesa += movimenti[i] + tasso;	//No franchigia
			
		}
	}

	return spesa;
}

