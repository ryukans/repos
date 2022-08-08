#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
T min_(vector<T> v);

template <typename T>
T max_(vector<T> v);

template <typename T>
T mode(vector<T> v);

template <typename T>
void getdata(vector<T>& v);


int main()
{
    vector<double> v;
    vector<string> s;

    cout << "Type numbers separated by a space\nEnd with non-digit character.\n> ";
    getdata(v);
    cout << "Max\tMin\tMode\n"
         << max_(v) << "\t"
         << min_(v) << "\t"
         << mode(v)
         << endl;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout <<"\n\n\nType strings separated by a space\nEnd with Ctrl-D (Unix) or Ctrl-Z (Windows).\n> ";
    getdata(s);
    cout << "Max\tMin\tMode\n"
         << max_(s) << "\t"
         << min_(s) << "\t"
         << mode(s)
         << endl;


    return 0;
}

template <typename T>
void getdata(vector<T>& v)
{
    T data;
    while (cin >> data) {
        v.push_back(data);
    }
}


template <typename T>
T min_(vector<T> v)
{
	T min_val = v[0];

	for (T val : v) {
        if (val < min_val) min_val = val;
	}
	return min_val;
}


template <typename T>
T max_(vector<T> v)
{
	T max_val = v[0];

	for (T val : v) {
        if (val > max_val) max_val = val;
	}
	return max_val;
}


template <typename T>
T mode(vector<T> v)
{
    T mode;
    int prev = 0, curr = 0;

    sort (v.begin(), v.end());

    uint32_t i;
    while (i < v.size()) {
        static uint32_t j;

        while (j < v.size() && v.at(j) == v.at(i)) {
            ++curr;
            ++j;
        }

        if (curr > prev) {
            prev = curr;
            mode = v[i];
        }

        i = j;
        curr = 0;
    }
    return mode;
}


