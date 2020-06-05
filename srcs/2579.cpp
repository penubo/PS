// https://www.acmicpc.net/problem/2579

#include <bits/stdc++.h>

using namespace std;
int dp[301][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	vector<int> arr(n+1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	
	dp[1][0] = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
		dp[i][1] = dp[i-1][0] + arr[i];		
	}	
	cout << *max_element(dp[n], dp[n]+2) << "\n";
}