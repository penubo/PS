// https://www.acmicpc.net/problem/1149

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

 	int arr[n][3];

	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
	}

	int dp[n][3];
	for (int i = 0; i < 3; i++)
		dp[0][i] = arr[0][i];

	for (int i = 1; i < n; i++) {
		dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}


	cout << *min_element(dp[n-1], dp[n-1]+3) << "\n";


}