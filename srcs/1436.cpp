#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX INT32_MAX

bool check(long long n) {
    string num = to_string(n);
    int cnt = 0;

    if (num.size() < 3) {
        return false;
    }

    for (int i = 0; i < num.size()-2; i++) {
        if (num[i] == '6' && num[i+1] == '6' && num[i+2] == '6') {
            return true;
        }
    }
    
    return false;
}

int main() {

    int N, cnt = 0;

    cin >> N;

    for (long long i = 0; i < MAX; i++) {
        if (check(i)) {
            cnt++;
            if (cnt == N) {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;

}