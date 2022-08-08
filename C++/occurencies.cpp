#include <iostream>

int count_x(
    char* s,
    char x
);

int main()
{
    char* s = "Hello";

    int d = count_x(s, 'l');

    cout << d;

    return 0;
}

int count_x(char* s, char x)
{
    if (s == nullptr) { return 0; }

    int c = 0;
    while (*s != 0) {
        if (*s == x)
            ++c;
        ++s;
    }

    return c;
}
