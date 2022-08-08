#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int max_range = 0;
    vector<bool> primes(max_range);

    cout << "Type max range\n> ";
    cin >> max_range;

    for (int i = 2; i <= max_range; ++i) { primes[i] = true; }

    primes[0] = false;
    primes[1] = false; /* 0 and 1 are not prime */

    for (int p = 2; p <= max_range; ++p)
        if (primes[p] == true) /* if is not marked yet */
            for (int p2 = p*p; p2 <= max_range; p2+=p)
                primes[p2] = false;


    for (int i = 0; i < max_range; ++i)
        if (primes[i] == true) cout << i << " is prime" << endl;


    return 0;
}

