#include <iostream>
#include <fstream>

using namespace std;

int const tot_temps = 100;
int const max_row = 4;
int const max_col = 2;
typedef double matrix [max_row][max_col];

struct Record {
    int hour; // 24h format [0,23]
    double temperature;
}r;

void readRawData(string, matrix&);
void readTemps(Record[], int&);

int main()
{
    matrix rawData;
    Record temps[tot_temps];
    int t;

    string name {"records.txt"};

    readRawData(name, rawData);
    readTemps(temps, t);

    // print out temps

    for (int i = 0; i < t; i++)
        cout << temps[i].hour << '-' << temps[i].temperature << endl;

    return 0;
}


void readRawData(string fileName, matrix &data)
{
    ifstream file {fileName};

    if (!file) {
        cerr << "Error: file not found";
        exit(1);
    }

    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j < max_col; j++)
            file >> data[i][j];
    }
}

void readTemps(Record temps[], int &t)
{
    t = 0;
    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j < max_col; j++)
            temps[t++] = Record{i, j};
    }
}
/*
void printTemps(const Record temps[])
{


}
*/






