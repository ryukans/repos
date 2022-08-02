#include <iostream>

int calculate_squares(int total_grains);

using namespace std;

int main()
{
    int squares, total_grains;

    for (double pos = 1, curr_grains = 1; pos <= 64; ++pos, curr_grains *= 2)
        cout << "square "<< pos << " grains " << curr_grains << endl;


/*
    total_grains = 1000;
    squares = calculate_squares(total_grains);
    cout << squares << " squares are needed for " << total_grains << endl;

    total_grains = 1000000;
    squares = calculate_squares(total_grains);
    cout << squares << " squares are needed for " << total_grains << endl;

    total_grains = 1000000000;
    squares = calculate_squares(total_grains);
    cout << squares << " squares are needed for " << total_grains << endl;
*/
    return 0;
}

int calculate_squares(int total_grains)
{
    int pos, curr_grains, sum_prev;

    for (pos = 1, curr_grains = 1, sum_prev = 1;

            sum_prev < total_grains;

                ++pos,
                curr_grains *= 2,
                sum_prev += curr_grains
        );

    return pos;
}





