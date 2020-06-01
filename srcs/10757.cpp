#include <iostream>
#include <string>

using namespace std;

int add(char a, char b, int *cr)
{
    int n1, n2, carriage;

    n1 = a - '0';
    n2 = b - '0';

    carriage = *cr;

    if (n1 + n2 + *cr > 9)
        *cr = 1;
    else
        *cr = 0;
    return ((n1 + n2 + carriage) % 10);
}

int main()
{
    string a, b, res, last;
    int cr;

    res = "";
    cr = 0;
    cin >> a >> b;

    while (!a.empty() && !b.empty())
    {
        res.insert(res.begin(), add(a.back(), b.back(), &cr) + '0');
        a.pop_back();
        b.pop_back();
    }

    last = a.empty() ? b : a;

    while (!last.empty())
    {
        res.insert(res.begin(), add('0', last.back(), &cr) + '0');
        last.pop_back();
    }
    if (cr)
        res.insert(res.begin(), '1');

    cout << res << "\n";
}