#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double mean(vector<double> v);
double median(vector<double> v);

int main()
{
	vector<double> temps;	// temperatures
	
	// find mean
	cout << "Type some temperatures separated by a space (end w/ a non-number character):\n> ";

	for (double tmp; cin >> tmp; ) // read int tmp
		temps.push_back(tmp);
	
	cout << "Average temperature: " << mean(temps) << '\n';
	
	// find median
	cout << "Median temperature: " << median(temps) << '\n';


	return 0;
}


// compute mean temperature
double mean(vector<double> v)
{
	double sum = 0;
	for (double x : v)
		sum += x;
	
	return sum/v.size();
}


double median(vector<double> v)
{
	sort(v.begin(), v.end());

	int size = v.size();
	
	return (size%2 == 0) ? (v[(size-1)/2] + v[size/2]) / 2.0 : v[size/2];
}
