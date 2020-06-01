#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int N, M, sum, ans;
    vector<int> c;

    cin >> N >> M;

    c.assign(N, 0);
    sum = 0, ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int k = j+1; k < N; k++) {
                sum = c[i] + c[j] + c[k];
                if (sum <= M && sum > ans) {
                    ans = sum;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}