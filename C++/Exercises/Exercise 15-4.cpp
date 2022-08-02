#include <iostream>
#include <vector>

using namespace std;

vector<int> primes { 2 }; // considering 2 as the first prime number
enum bools { NOT_PRIME, IS_PRIME };

bool is_prime(int n);

int main()
{
    int n = 5;

    cout << "Type how many prime numbers you want to generate\n> ";
    cin >> n;

    int i = 3;
    while (primes.size() < n) {
        if (is_prime(i))
            primes.push_back(i);
        ++i;
    }

    for (int i = 0; i < primes.size(); ++i)
        cout << primes[i] << endl;

    return 0;
}


bool is_prime(int n)
{
    if (n == 0 || n == 1) return NOT_PRIME;
    else if (n == 2) return IS_PRIME;

    for (int i = 0; i < primes.size(); ++i) // If n is divisible by any prime number then n is composite, otherwise it is prime.
        if (n%primes[i] == 0) // no reminder
            return NOT_PRIME;
    return IS_PRIME;
}
