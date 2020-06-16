// https://www.acmicpc.net/problem/2357

#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<long long> arr(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << *min_element(arr.begin()+a+1, arr.begin()+b+1) << " ";
		cout << *max_element(arr.begin()+a+1, arr.begin()+b+1) << "\n";
		// search(arr, a, b);
	}



}