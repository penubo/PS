#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, x, y;
    vector<pair<int, int> > arr;
    vector<int> ans;

    cin >> N;
    arr.assign(N, pair<int, int>());
    ans.assign(N, 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) 
                continue;
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
                ans[i]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}