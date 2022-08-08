#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flush(void);
void get_vector(vector<double>& v);
double sum(vector<double> v, double n);
double difference(vector<double> v, double n);

int main()
{
    vector<double> v;
    vector<double> v2;

    cout << "Enter a series of number\n> ";
    get_vector(v);

    flush();

    cout << "Type the first N numbers to sum\n> ";
    int n;
    cin >> n;

    double s = sum(v, n);
    double d = difference(v, n);

    cout << "\nSum: " << s << "\nDiff: " << d << endl;

    return 0;
}


void get_vector(vector<double>& v)
{
    double tmp;
    while (cin >> tmp)
        v.push_back(tmp);
}


double sum(vector<double> v, double n)
{
     if (n > v.size()) {
        cerr << "Number requested grater than vector size\n";
        exit(1);
    }
    else if (n < 0) {
        cerr << "Negative number is not allowed\n";
        exit(2);
    }
    if (n == 0)
        return v.at(0);

    double sum = 0;
    for (int i = 0; i < n; ++i) sum += v[i];

    return sum;
}

double difference(vector<double> v, double n)
{
    if (n > v.size()) {
        cerr << "Number requested grater than vector size\n";
        exit(1);
    }
    else if (n < 0) {
        cerr << "Negative number is not allowed\n";
        exit(2);
    }
    if (n == 0)
        return v.at(0);

    double diff = v[0];
    for (int i = 1; i < n; ++i) diff -= v[i];

    return diff;
}

void flush()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

