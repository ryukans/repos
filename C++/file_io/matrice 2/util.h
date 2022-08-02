
//declarations

using namespace std;

typedef int matrice [5][5];
typedef char* stringa;


void leggi_mat(const stringa, matrice, int&, int&);

void stampa_mat(const matrice, int, int);

int calc_min(const matrice, int, int);

int calc_max(const matrice, int, int);

void normalizza_mat(const matrice, matrice, int, int, int, int);
