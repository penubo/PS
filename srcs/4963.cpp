// https://www.acmicpc.net/problem/4963

#include <bits/stdc++.h>

using namespace std;

bool adj[52][52];
bool visited[52][52];
vector<pair<int, int>> off = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y) {
	visited[x][y] = true;

	for (auto of : off) {
		int nx = x + of.first;
		int ny = y + of.second;

		if (!visited[nx][ny] && adj[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = -1, m = -1, x;

	while (1) {
		cin >> m >> n;
		if (n == 0 && m == 0)
			break;
		
		int cnt = 0;
		memset(visited, 0, 52*52);
		memset(adj, 0, 52*52);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> x;
				adj[i][j] = x;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!visited[i][j] && adj[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

}