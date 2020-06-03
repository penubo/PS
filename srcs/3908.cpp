// https://www.acmicpc.net/problem/3908

#include <bits/stdc++.h>

#define MAX 186

using namespace std;
vector<long long> ps;
long long dp[1121][MAX+1];

bool is_prime(long long x) {
	long long i = 3;

	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;

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


	long long i = 2;
	ps.push_back(-1);
	while (i <= 1120LL) {
		if (is_prime(i))
			ps.push_back(i);
		i++;
	}
	dp[0][0] = 1;

	for (int i = 1; i < ps.size(); ++i) {
		for (int k = 14; k >= 1; --k) {
			for (int x = 0; x <= 1120; ++x) {
				if (x - ps[i] >= 0) {
					dp[x][k] += dp[x-ps[i]][k-1];
				}
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n, k;

		cin >> n >> k;

		cout << dp[n][k] << "\n";
	}

}