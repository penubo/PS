// https://www.acmicpc.net/problem/2156

#include <bits/stdc++.h>

using namespace std;

int dp[10001][3];

int main() {

	int n;
	cin >> n;
	vector<int> arr(n+1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1][1] = arr[1];
	
	for (int i = 2; i <= n; i++) {
		dp[i][0] = *max_element(dp[i-1], dp[i-1]+3);
		dp[i][1] = dp[i-1][0] + arr[i];
		dp[i][2] = dp[i-1][1] + arr[i];
	}

	cout << *max_element(dp[n], dp[n]+3) << "\n";

	return 0;
}