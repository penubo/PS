// https://www.acmicpc.net/problem/9461

#include <bits/stdc++.h>

using namespace std;

long long dp[101];

int main() {

	int t;
	cin >> t;

	for (int i = 1; i <= 3; i++)
		dp[i] = 1;

	for (int i = 4; i <= 100; i++)
		dp[i] = dp[i-3] + dp[i-2];

	while (t--) {
		int x;
		cin >> x;
		cout << dp[x] << "\n";
	}

}