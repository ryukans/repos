/*
Progettare e realizzare in C++ una classe Conto Corrente bancario.
Un conto corrente bancario ha un titolare, un iban, e la classe prevede anche una variabile membro che rappresenta il saldo attuale. 
Il titolare è rappresentato mediante una stringa C allocata dinamicamente, mentre  l’Iban sè rappresentato da una stringa C allocata staticamente.

La classe  deve offrire  oltre ai costruttori e alle funzionalità necessarie ad una corretta gestione della memoria dinamica, 
la possibilità di effettuare accrediti e prelievi, la possibilità di avere il valore del saldo corrente, l’overloading degli operatori <<, >> ==, !=.

Si utilizzi la compilazione condizionale per evitare che il file di intestazione venga incluso più volte da uno stesso modulo e i namespace per evitare conflitti con i nomi di libreria.
Si realizzi un programma di prova (main) che alloca dinamicamente un vettore di conti correnti,  inserisca nel vettore alcuni elementi e ne stampi i dati. Il vettore deve essere distrutto al termine della stampa.
*/

#include "Account.h"

int main()
{
	ContoCorrente* vcc = new ContoCorrente[3];

	for (size_t i = 0; i < 3; i++)
	{
		cin >> vcc[i];
		
	}

	for (size_t i = 0; i < 3; i++)
	{
		cout << vcc[i] << endl;
	}
	
	delete[] vcc;

}
