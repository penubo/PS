// https://www.acmicpc.net/problem/7576

#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> arr, int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;
	vector<vector<int>> arr(n+2, vector<int>(m+2, -1));
	queue<pair<int, int>> q;
	int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push({i, j});
		}
	}

	int ans = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + offset[i][0], ny = y + offset[i][1];
			if (arr[nx][ny] == 0) {
				arr[nx][ny] = arr[x][y] + 1;
				ans = max(ans, arr[nx][ny] - 1);
				q.push({nx, ny});
			}
		}
	}
	if (check(arr, n, m))
		cout << ans << "\n";
	else
		cout << -1 << "\n";

}