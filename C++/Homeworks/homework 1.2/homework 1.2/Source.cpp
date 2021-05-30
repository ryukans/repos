#include "utils.h"


void setCalciatore(Calciatore &c) 
{
	cin >> c.nome >> c.cognome >> c.squadra >> c.goal;
}

void getCalciatore(Calciatore c) 
{
	cout << c.nome << " " << c.cognome << " " << c.squadra << " " << c.goal << endl;
}

void setGoal(Calciatore &c)
{
	int n_goal = 0;

	cin >> n_goal;
	c.goal += n_goal;
}

int getGoal(Calciatore c)
{
	return c.goal;
}

bool uguali(Calciatore c1, Calciatore c2)
{
	return (c1.nome == c2.nome && c1.cognome == c2.cognome && c1.squadra == c2.squadra);
}

void setElenco(elencoCalciatori &e, int dim, int &n_elem)
{
	for (size_t i = 0; i < dim; i++) {
		e[i].nome = "";
		e[i].cognome = "";
		e[i].squadra = "";
		e[i].goal = 0;
	}
	n_elem = 0;
}

bool setElenco(Calciatore &c, elencoCalciatori e, int dim, int &n_elem)
{
	if (n_elem == dim) return false;	//se lista è piena allora ritorna false

	int i = 0;
	while (i < n_elem) {
		if (uguali(c, e[i++])) return false;	//se trova due uguali allora ritorna false
	}

	//altrimenti inserisci il nuovo dato 

	e[i].nome = c.nome;
	e[i].cognome = c.cognome;
	e[i].squadra = c.squadra;
	e[i].goal = c.goal;

	++n_elem;

	return true;
}


void getElenco(elencoCalciatori e, int n_elem)
{
	if (!n_elem) {
		cout << "Elenco vuoto" << endl;
		return;
	}

	for (size_t i = 0; i < n_elem; i++) getCalciatore(e[i]);
}


void verificaElemento(Calciatore c, elencoCalciatori e, int n_elem, int &pos)
{
	if (!n_elem) {
		cout << "Elemento non presente: elenco vuoto" << endl;
		return;	// failure
	}

	for (size_t i = 0; i < n_elem; i++) {
		if (uguali(c, e[i])) {
			pos = i;
			return;	// success
		}
	}
}

void riordinaElenco(elencoCalciatori e, int n_elem)
{
	for (size_t i = 0; i < n_elem; i++)	{
		for (size_t j = 1, tmp = 0; j < n_elem; j++) {
			if (e[i].goal > e[j].goal) {
				tmp = e[i].goal;
				e[i].goal = e[j].goal;
				e[j].goal = tmp;
			}
		}
	}
}

void copiaElenco(elencoCalciatori e1, elencoCalciatori e2, int n_elem)
{
	for (size_t i = 0; i < n_elem; i++) {
		e2[i].nome		= e1[i].nome;
		e2[i].cognome	= e1[i].cognome;
		e2[i].squadra	= e1[i].squadra;
		e2[i].goal		= e1[i].goal;
	}
}


