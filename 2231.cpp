#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, sum, tmp;
    bool end = false;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        tmp = i;
        sum = tmp;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N) {
            end = true;
            cout << i << "\n";
            break;
        }
    }

    if (!end) {
        cout << 0 << "\n";
    }

    return 0;
}