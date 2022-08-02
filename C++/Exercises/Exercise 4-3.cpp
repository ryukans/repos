/// Bjarne Stroustrup's solution: http://www.stroustrup.com/Programming/Solutions/Ch4/e4-3.cpp
#include <iostream>
#include <vector>

using namespace std;

double total_distance(vector<double> v);
double max(vector<double> v);
double min(vector<double> v);
double median(vector<double> v);

int main()
{
	vector<double> dist; // each value is the distance between two cities

    for (double val; cin >> val && val > 0; )
        dist.push_back(val);

	cout << "Total distance:\t" << total_distance(dist) << '\n'
		 << "Smallest value:\t" << min(dist) << '\n'
		 << "Greatest value:\t" << max(dist) << '\n'
		 << "Median value:\t" << median(dist) << endl;

	return 0;
}

double total_distance(vector<double> v)
{
	double tot_dis = 0.0;

	for (double val : v) {
		tot_dis += val;
	}
	return tot_dis;
}


double min(vector<double> v)
{
	double min_val = v[0];

	for (double val : v) {
        if (val < min_val) min_val = val;
	}
	return min_val;
}


double max(vector<double> v)
{
	double max_val = v[0];

	for (double val : v) {
        if (val > max_val) max_val = val;
	}
	return max_val;
}


double median(vector<double> v)
{
    return (v.size() % 2 == 0) ? v.size() / 2 : (v.size() + v.size()-1) / 2;
}





