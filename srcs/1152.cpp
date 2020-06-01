#include <iostream>
#include <string>

using namespace std;

int main()
{
    char c, prev;
    int cnt;

    cnt = 0;
    prev = 0;
    while ((c = cin.get()))
    {
        if (c == EOF || c == '\n')
            break;
        if (prev == 0 && c != ' ')
            cnt++;
        else if (prev == ' ' && c != ' ')
            cnt++;
        prev = c;
    }
    cout << cnt;
}