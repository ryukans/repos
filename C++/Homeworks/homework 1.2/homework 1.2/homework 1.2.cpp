#include "utils.h"

int main()
{
	Calciatore c1, c2, c3;
	elencoCalciatori e, e2;
	int n_elem = 0; //numero di elementi nella lista
	
	setCalciatore(c1);
	setCalciatore(c2);
	setCalciatore(c3);
	getCalciatore(c1);
	getCalciatore(c2);
	getCalciatore(c3);
	setGoal(c1);
	cout << getGoal(c1);
	
	cout << endl;

	//inizializza eleno vuoto
	setElenco(e, dim, n_elem);
	setElenco(e2, dim, n_elem);
	getElenco(e, n_elem);
	getElenco(e2, n_elem);

	
	bool inserito = NULL;


	inserito = setElenco(c1, e, dim, n_elem);

	inserito ? cout << "c1 inserito" << endl : cout << "Errore: impossibile inserire c1" << endl;


	inserito = setElenco(c2, e, dim, n_elem);

	inserito ? cout << "c2 inserito" << endl : cout << "Errore: impossibile inserire c2" << endl;


	inserito = setElenco(c3, e, dim, n_elem);

	inserito ? cout << "c3 inserito" << endl : cout << "Errore: impossibile inserire c3" << endl;
	

	getElenco(e, n_elem);
	
	
	Calciatore c4;
	int pos = -1;
	setCalciatore(c4);
	verificaElemento(c4, e, n_elem, pos);
	
	(pos != -1) ? cout << "Elemento presente in posizione " << pos + 1 << endl : cout << "Errore -1: Elemento non presente in lista" << endl;

	cout << "Elenco prima riordinamento" << endl;
	getElenco(e, n_elem);

	cout << "Elenco dopo riordinamento" << endl;
	riordinaElenco(e, n_elem);
	getElenco(e, n_elem);
	

	copiaElenco(e, e2, n_elem);
	getElenco(e2, n_elem);


	system("pause");
	return 0;
}            

