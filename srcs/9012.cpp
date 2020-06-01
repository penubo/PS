#include <iostream>
#include <string>

using namespace std;
// TODO
int main()
{
    int n;
    string str, stack;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        stack.clear();
        while (!str.empty())
        {
            if (str.front() == ')' && stack.empty())
                break;
            else if (str.front() == ')')
                stack.pop_back();
            else
                stack.push_back(str.front());
            str = str.substr(1);
        }
        if (str.empty() && stack.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}