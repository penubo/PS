// https://www.acmicpc.net/problem/2875

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	int cnt = 0;

	while (n + m - 3 >= k) {
		if (n < 2 || m < 1)
			break;
		cnt++;
		n -= 2;
		m -= 1;
	}

	cout << cnt << "\n";

}