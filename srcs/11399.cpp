// https://www.acmicpc.net/problem/11399

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long sum = 0;
	long long acc = 0;

	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());


	for (auto a : arr) {
		acc += a;
		sum += acc;
	}

	cout << sum << "\n";



}

