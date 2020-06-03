// https://www.acmicpc.net/problem/3908

#include <bits/stdc++.h>

#define MAX 398

using namespace std;
vector<long long> ps;
long long dp[1121][MAX+1];

bool is_prime(long long x) {
	long long i = 3;

	while (i*i <= x) {
		if (x % i == 0)
			return false;
		i += 2;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	long long i = 2;
	ps.push_back(-1);
	while (i < 1120LL) {
		if (is_prime(i))
			ps.push_back(i);
		i++;
	}

	dp[0][0] = 1;

	for (int k = 1; k <= ps.size(); k++) {
		for (int x = 0; x <= 1120; x++) {
			if (x - ps[k] >= 0)
				dp[x][k] += dp[x-ps[k]][k-1];
			dp[x][k] += dp[x][k-1];
		}
	}

	while (t--) {
		int n, k;

		cin >> n >> k;
		long long max = 0;
		for (int i = 0; i <=ps.size(); i++) {
			if (dp[n][i] == k)
				max++;
		}
		cout << max << "\n";
	}

}